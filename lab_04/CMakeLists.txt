add_executable(lab04
        src/main.c
        src/utils.c
)

target_include_directories(lab04 PRIVATE include)

target_compile_options(lab04 PRIVATE -Wall -Wextra -Werror -pedantic)
