add_executable(lab07
        src/main.c
        src/utils.c
)

target_include_directories(lab07 PRIVATE include)

target_compile_options(lab07 PRIVATE -Wall -Wextra -Werror -pedantic)
