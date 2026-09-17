# ============================================================================ #
#                           Task Runner / Dispatcher                           #
# ============================================================================ #
# Usage:                                                                       #
#  make <target>               e.g. make build / make format-check             #
#  make <target> LAB=<n>       same target, scoped to "lab_<n>"                #
#                              (accepts LAB=1 or LAB=01 alike, max 99)         #
#  make <target> PRESET=debug  use the debug preset instead of release         #
#                                                                              #
# Available targets:                                                           #
#  help         - List available targets and usage instructions                #
#  configure    - Generate the aggregate CMake build directory for PRESET      #
#  build        - Configure (if needed) and compile every lab                  #
#  rebuild      - Wipe the aggregate build directory for PRESET and build from #
#                 scratch                                                      #
#  clean        - Remove the aggregate build directory for PRESET              #
#  run          - Requires LAB=<n> - build & run a single lab                  #
#                 (e.g. "make run LAB=01")                                     #
#  format       - Auto-format every lab's C sources in place                   #
#  format-check - Verify formatting across every lab                           #
#                                                                              #
# Without LAB= - operates on the aggregate build (root CMakePresets.json,      #
#                every lab at once).                                           #
# With LAB=<n> - pure redirector, forwards the target to that lab's own        #
#                Makefile (lab_<n>/Makefile), which builds/runs/formats just   #
#                that one lab. (accepts LAB=1 or LAB=01 alike, max 99)         #
# ============================================================================ #

ifdef LAB
LAB_NUM_STRIPPED := $(shell echo "$(LAB)" | sed 's/^0*//')
LAB_ID           := $(shell printf '%02d' "$(if $(LAB_NUM_STRIPPED),$(LAB_NUM_STRIPPED),0)" 2>/dev/null)
LAB_DIR          := lab_$(LAB_ID)
endif

ifdef LAB
# ============================================================================ #
# LAB=<n> given: forward every target below to lab_NN/Makefile.                #
# ============================================================================ #

.PHONY: all build rebuild configure clean run format format-check check-lab help

all: build

help: check-lab
	@echo "LAB=$(LAB) -> $(LAB_DIR) (forwarding to its own Makefile):"
	@$(MAKE) --no-print-directory -C $(LAB_DIR) help

build rebuild configure clean run format format-check: check-lab
	@$(MAKE) --no-print-directory -C $(LAB_DIR) $@

check-lab:
	@test -d "$(LAB_DIR)" || { \
		echo "No such lab: '$(LAB_DIR)' (from LAB=$(LAB)). Available labs:"; \
		ls -d lab_[0-9][0-9] 2>/dev/null | sed 's/^/  /'; \
		exit 1; \
	}

else
# ============================================================================ #
# No LAB given: operate on the aggregate build (all labs + root).              #
# ============================================================================ #

PRESET := release

.PHONY: all build rebuild configure clean run format format-check check-clang-format help

all: build

## help: List available targets and usage instructions
help:
	@echo "Usage: make <target> [PRESET=debug|release] [LAB=<n>]"
	@echo
	@echo "Available targets (aggregate - all labs):"
	@grep -E '^## ' $(MAKEFILE_LIST) | \
		awk -F': ' '{printf "  make %-14s %s\n", $$1, $$2}' | sed 's/## //'

## configure: Generate the aggregate CMake build directory for PRESET
configure:
	cmake --preset $(PRESET)

## build: Configure (if needed) and compile every lab
build: configure
	cmake --build --preset $(PRESET)

## rebuild: Wipe the aggregate build directory for PRESET and build from scratch
rebuild: clean build

## clean: Remove the aggregate build directory for PRESET
clean:
	rm -rf build/$(PRESET)

## run: Requires LAB=<n> - build & run a single lab (e.g. "make run LAB=01")
run:
	@echo "Usage: make run LAB=<number>  (e.g. make run LAB=01)"
	@exit 1

## format: Auto-format every lab's C sources in place
format: check-clang-format configure
	cmake --build --preset $(PRESET) --target format

## format-check: Verify formatting across every lab
format-check: check-clang-format configure
	cmake --build --preset $(PRESET) --target format-check

check-clang-format:
	@command -v clang-format >/dev/null 2>&1 || { \
		echo "clang-format not found on PATH. Install it, then retry:"; \
		echo "  MSYS2/UCRT64 (Windows): pacman -S mingw-w64-ucrt-x86_64-clang-tools-extra"; \
		echo "  Debian/Ubuntu:          sudo apt-get install clang-format"; \
		echo "  macOS (Homebrew):       brew install clang-format"; \
		exit 1; \
	}

endif
