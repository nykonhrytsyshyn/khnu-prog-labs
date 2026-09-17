cmake_minimum_required(VERSION 3.20)
project(khnu_prog_labs LANGUAGES C VERSION 1.0.0)

# Set global C standard settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Use CCache if available
find_program(CCACHE_PROGRAM ccache)

if (CCACHE_PROGRAM)
  set(CMAKE_C_COMPILER_LAUNCHER "${CCACHE_PROGRAM}")
endif ()

# Set compiler warning flags based on the compiler
if (MSVC)
  add_compile_options(/W4 /WX)
else ()
  add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif ()

# Add subdirectories for each "lab_*" directory that contains a CMakeLists.txt file
file(GLOB LAB_DIRS LIST_DIRECTORIES true RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} lab_*)

foreach (DIR ${LAB_DIRS})
  if (IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${DIR} AND EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${DIR}/CMakeLists.txt)
    add_subdirectory(${DIR})
  endif ()
endforeach ()

# Add formatting targets for all source and header files
include(${CMAKE_SOURCE_DIR}/cmake/FormatTargets.cmake)

add_format_targets(
        ${CMAKE_SOURCE_DIR}/*.c
        ${CMAKE_SOURCE_DIR}/*.h)
