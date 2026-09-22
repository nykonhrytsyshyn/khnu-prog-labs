# ============================================================================ #
#                                Format Targets                                #
# ============================================================================ #
# add_format_targets(<glob-pattern>...) creates "format" and "format-check"    #
# custom targets that run clang-format -i / --dry-run --Werror over every file #
# matched by the given glob patterns.                                          #
# ============================================================================ #

function(add_format_targets)
  if (TARGET format)
    return()
  endif ()

  find_program(CLANG_FORMAT_EXE NAMES clang-format)

  if (NOT CLANG_FORMAT_EXE)
    message(STATUS "clang-format not found - 'format' / 'format-check' targets unavailable")
    return()
  endif ()

  file(GLOB_RECURSE FORMAT_SOURCE_FILES CONFIGURE_DEPENDS ${ARGN})

  list(FILTER FORMAT_SOURCE_FILES EXCLUDE REGEX "/(build|cmake-build-[^/]*|\\.git)/")

  if (NOT FORMAT_SOURCE_FILES)
    return()
  endif ()

  add_custom_target(format
          COMMAND ${CLANG_FORMAT_EXE} -i ${FORMAT_SOURCE_FILES}
          WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
          COMMENT "Formatting C sources with clang-format"
          VERBATIM)

  add_custom_target(format-check
          COMMAND ${CLANG_FORMAT_EXE} --dry-run --Werror ${FORMAT_SOURCE_FILES}
          WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
          COMMENT "Checking C source formatting with clang-format"
          VERBATIM)
endfunction()
