NAME = ft_ls

LIBFT_PATH = ./libft/
SRC_PATH = ./srcs/

INCS = ./includes/ft_ls.h

SRCS =	./srcs/flags.c ./srcs/ft_ls.c ./srcs/errors.c ./srcs/lists.c \
		./srcs/convert.c ./srcs/sort.c ./srcs/printing.c ./srcs/args.c \
		./srcs/long.c ./srcs/time.c ./srcs/extras.c ./srcs/maxs.c \
		./srcs/single.c

FLAGS = -Wall -Werror -Wextra

INC =  -I $(INCS) -I $(LIBFT_PATH)libft.h

SRCO = $(patsubst %.c, %.o, $(SRCS))

all: $(NAME)

$(NAME): $(SRCO)
	@make -C $(LIBFT_PATH)
	@gcc $(FLAGS) -o $(NAME) $(SRCS) $(LIBFT_PATH)libftprintf.a
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m Created.\033[0m"

$(SRC_PATH)%.o: $(SRC_PATH)%.c
	@gcc $(FLAGS) -c $< -o $@

clean:
	@make -C $(LIBFT_PATH) clean
	@/bin/rm -rf $(SRCO)
	@echo "\033[31mObjects Files \033[1;31m$(OBJS_LIST)\033[1;0m\033[31mRemoved.\033[0m"

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@/bin/rm -rf $(NAME)
	@echo "\033[31mBin \033[1;31m$(NAME)\033[1;0m\033[31m Removed.\033[0m"

re: fclean all

.PHONY: all fclean clean re
