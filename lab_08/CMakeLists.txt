add_executable(lab08
        src/main.c
        src/utils.c
)

target_include_directories(lab08 PRIVATE include)

target_compile_options(lab08 PRIVATE -Wall -Wextra -Werror -pedantic)
