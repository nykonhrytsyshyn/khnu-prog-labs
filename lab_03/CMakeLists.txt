add_executable(lab03
        src/main.c
        src/utils.c
)

target_include_directories(lab03 PRIVATE include)

target_compile_options(lab03 PRIVATE -Wall -Wextra -Werror -pedantic)
