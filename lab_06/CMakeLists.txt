add_executable(lab06
        src/main.c
        src/utils.c
)

target_include_directories(lab06 PRIVATE include)

target_compile_options(lab06 PRIVATE -Wall -Wextra -Werror -pedantic)
