add_executable(lab01
        src/main.c
        src/utils.c
)

target_include_directories(lab01 PRIVATE include)

target_compile_options(lab01 PRIVATE -Wall -Wextra -Werror -pedantic)
