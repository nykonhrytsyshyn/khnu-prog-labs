# ============================================================================ #
#                               Lab Task Runner                                #
# ============================================================================ #
# Thin CLI wrapper around this lab's own CMakePresets.json - lets you work on  #
# this lab in isolation (cd lab_n && make build) without touching the rest of  #
# the repo. From the repo root, "make <target> LAB=<n>" forwards here.         #
#                                                                              #
# Usage:                                                                       #
#  make <target>               e.g. make build / make format-check             #
#  make <target> PRESET=debug  use the debug preset instead of release         #
#                                                                              #
# Available targets:                                                           #
#  help         - List available targets and usage instructions                #
#  configure    - Generate this lab's CMake build directory for PRESET         #
#  build        - Configure (if needed) and compile this lab                   #
#  rebuild      - Wipe this lab's build directory for PRESET and build from    #
#                 scratch                                                      #
#  clean        - Remove this lab's build directory for PRESET                 #
#  run          - Build and run this lab's executable                          #
#  format       - Auto-format this lab's C sources in place                    #
#  format-check - Verify formatting without modifying files                    #
# ============================================================================ #

PRESET := release

LAB_ID := $(patsubst lab_%,%,$(notdir $(CURDIR)))
TARGET := lab$(LAB_ID)

.PHONY: all build rebuild configure clean run format format-check check-clang-format help

all: build

## help: List available targets and usage instructions
help:
	@echo "Usage: make <target> [PRESET=debug|release]"
	@echo
	@echo "Available targets for $(TARGET):"
	@grep -E '^## ' $(MAKEFILE_LIST) | \
		awk -F': ' '{printf "  make %-14s %s\n", $$1, $$2}' | sed 's/## //'

## configure: Generate this lab's CMake build directory for PRESET
configure:
	cmake --preset $(PRESET)

## build: Configure (if needed) and compile this lab
build: configure
	cmake --build --preset $(PRESET)

## rebuild: Wipe this lab's build directory for PRESET and build from scratch
rebuild: clean build

## clean: Remove this lab's build directory for PRESET
clean:
	rm -rf build/$(PRESET)

## run: Build and run this lab's executable
run: build
	@./build/$(PRESET)/$(TARGET)

## format: Auto-format this lab's C sources in place
format: check-clang-format configure
	cmake --build --preset $(PRESET) --target format

## format-check: Verify formatting without modifying files
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
