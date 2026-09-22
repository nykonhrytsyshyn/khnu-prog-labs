cmake_minimum_required(VERSION 3.21)

# Standalone-capable: this file works either as its own top-level project
# (cd lab_01 && cmake --preset release) or as a subdirectory of the root
# aggregate build (root CMakeLists.txt's add_subdirectory()). Project-wide
# settings only need to be (re)established in the former case - the root
# project already sets them for the aggregate build.
if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  project(lab01 LANGUAGES C)

  set(CMAKE_C_STANDARD 11)
  set(CMAKE_C_STANDARD_REQUIRED ON)
  set(CMAKE_C_EXTENSIONS OFF)

  if (MSVC)
    add_compile_options(/W4 /WX)
  else ()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
  endif ()
endif ()

add_executable(lab01
        src/main.c
        src/utils.c
        src/runner.c
        src/task1.c
        src/task2.c
        src/task3.c
        src/task4.c
)

target_include_directories(lab01 PRIVATE include)

if (NOT MSVC)
  target_link_libraries(lab01 PRIVATE m)
endif ()

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/FormatTargets.cmake)
  add_format_targets(
          ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
          ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
endif ()
