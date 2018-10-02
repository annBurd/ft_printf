cmake_minimum_required(VERSION 3.9)
project(_ft_printf)

#set(CMAKE_CXX_STANDARD 11)

cmake_minimum_required(VERSION 3.9)
set(CMAKE_C_STANDARD 99)
project(_ft_printf)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -Ipthreads")
set(SOURCE_FILES
        inc/ft_printf.h
        src/additional.c
        src/specification_define.c
        src/ft_printf.c
        src/handle_i.c
        src/handle_c.c
        src/handle_wc.c
        main.c)
link_directories(libft) # header directories
add_executable(_ft_printf ${SOURCE_FILES})
target_link_libraries(_ft_printf -lft) # linkage