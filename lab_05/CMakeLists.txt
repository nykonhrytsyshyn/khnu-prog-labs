add_executable(lab05
        src/main.c
        src/utils.c
)

target_include_directories(lab05 PRIVATE include)

target_compile_options(lab05 PRIVATE -Wall -Wextra -Werror -pedantic)
