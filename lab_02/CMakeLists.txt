add_executable(lab02
        src/main.c
        src/utils.c
)

target_include_directories(lab02 PRIVATE include)

target_compile_options(lab02 PRIVATE -Wall -Wextra -Werror -pedantic)
