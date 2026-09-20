# KhNU Programming Labs

Laboratory works for the "Programming" course at Khmelnytskyi National
University (KhNU), written in C11 and built with CMake + Ninja.

Every `lab_NN/` directory is an independent, buildable program with its own
sources, assignment (`docs/task.pdf`) and write-up (`README.md`). The root
project builds all of them together, and a root `Makefile` wraps the CMake
presets so the same short commands work on Windows and Linux.

```
.
├── .github/workflows/   # build + format check
├── cmake/               # shared CMake modules (format targets)
├── lab_NN/              # each lab is a separate subproject [NN = 01, 02, ...]
│   ├── docs/              # Task description and other lab-specific docs
│   ├── include/           # public headers for the lab
│   ├── src/               # source files for the lab
│   ├── CMakeLists.txt     # lab-specific build rules
│   ├── CMakePresets.json  # lab-specific debug / release presets
│   └── Makefile           # lab-specific task runner (same targets as root)
├── .clang-format        # code style (LLVM-based, 4 spaces, 80 columns)
├── CMakeLists.txt       # aggregate project, adds every lab_*
├── CMakePresets.json    # debug / release presets
└── Makefile             # task runner, see "Commands"
```

## Requirements

| Tool         | Version | Needed for                             |
|--------------|---------|----------------------------------------|
| CMake        | >= 3.21 | configuring the build                  |
| Ninja        | any     | build backend used by the presets      |
| C compiler   | C11     | GCC, Clang or MSVC                     |
| GNU Make     | any     | the `make` commands below              |
| clang-format | 22.x    | `format` / `format-check` targets only |

> [!IMPORTANT]
> clang-format output differs between major versions, so `format-check` only
> matches CI when you use the same major version as the workflow (22.x).

## Installation

### Windows (MSYS2 UCRT64)

Install [MSYS2](https://www.msys2.org/), open the **UCRT64** terminal and run:

```bash
pacman -S --needed \
  mingw-w64-ucrt-x86_64-cmake \
  mingw-w64-ucrt-x86_64-ninja \
  mingw-w64-ucrt-x86_64-gcc \
  mingw-w64-ucrt-x86_64-clang-tools-extra \
  make
```

### Linux (Debian / Ubuntu)

```bash
sudo apt-get update
sudo apt-get install -y cmake ninja-build gcc make pipx
pipx install clang-format==22.1.8
```

## Commands

```
make <target> [LAB=<n>] [PRESET=debug|release]
```

| Target              | Description                                                  |
|---------------------|--------------------------------------------------------------|
| `make help`         | List available targets and usage instructions                |
| `make configure`    | Generate the CMake build directory for `PRESET`              |
| `make build`        | Configure (if needed) and compile every lab                  |
| `make rebuild`      | Wipe the build directory for `PRESET` and build from scratch |
| `make clean`        | Remove the build directory for `PRESET`                      |
| `make run`          | Build and run a single lab (requires `LAB=<n>`)              |
| `make format`       | Auto-format the C sources in place with clang-format         |
| `make format-check` | Verify formatting without modifying files (what CI runs)     |

| Variable | Default   | Description                                                                                                  |
|----------|-----------|--------------------------------------------------------------------------------------------------------------|
| `LAB`    | *(unset)* | Scope the target to one lab (`1` and `01` are equivalent). Without it, targets operate on every lab at once. |
| `PRESET` | `release` | CMake preset to use: `release` or `debug`.                                                                   |

> [!NOTE]
> Every `lab_NN/` also has its own `Makefile` with the same targets (except
> `LAB`), so a lab can be built on its own by running `make` from inside its
> directory. `make <target> LAB=<n>` from the root simply forwards there.
