# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blee <blee@student.42.us.org>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/18 14:11:04 by blee              #+#    #+#              #
#    Updated: 2019/05/08 18:54:10 by blee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC_DIR = ./srcs
OBJ_DIR = ./objs
LIBFT = ./libft/libft.a


SRC_FILES = main.c \
			msh_get_input.c \
			msh_cmd_id.c \
			msh_exec.c \
			msh_echo.c \
			msh_helper.c \
			msh_init_env.c \
			msh_edit_env.c \
			msh_strsplit.c \
			msh_free.c \
			ft_ls/bt_func.c \
			ft_ls/bt_func2.c \
			ft_ls/build_tree.c \
			ft_ls/check_inputs.c \
			ft_ls/file_att1.c \
			ft_ls/file_att2.c \
			ft_ls/ft_ls.c \
			ft_ls/get_len.c \
			ft_ls/init_file.c \
			ft_ls/printing.c \
			ft_ls/print_func.c \
			ft_ls/print_long.c \
			ft_ls/print_dir.c \
			ft_ls/free_ls.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

all: $(NAME)

$(LIBFT):
	make -C libft

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p ./objs/ft_ls

$(OBJS): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -Wall -Wextra -Werror -c $< -o $@ -I ./includes

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT)
	gcc -o $(NAME) $(OBJS) $(LIBFT)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: clean all
