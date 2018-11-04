cmake_minimum_required(VERSION 3.9)
set(CMAKE_C_STANDARD 99)
project(_ft_printf)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Ipthreads")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -Ipthreads")
set(SOURCE_FILES
        inc/ft_printf.h
        src/ft_printf.c
        src/handle_cs.c
        src/handle_id.c
        src/handle_oubxp.c
        src/pr_refresh_buf.c
        src/pr_define_flags.c
        src/pr_join.c
        src/pr_color.c
        src/pr_utoa.c

        libft/ft_atoi.c
        libft/ft_bzero.c
        libft/ft_nbrlen.c
        libft/ft_nbrulen.c
        libft/ft_strlen.c
        libft/ft_tolower.c
        main.c)
link_directories(libft) # header directories
add_executable(_ft_printf ${SOURCE_FILES})
target_link_libraries(_ft_printf -lft) # linkage