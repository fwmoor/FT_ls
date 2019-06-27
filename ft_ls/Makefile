NAME = ft_ls

LIBFT_PATH = ./libft/

FLAGS = -Wall -Werror -Wextra
INC = -I ./includes/ -I $(LIBFT_PATH)includes/

all: $(NAME)

$(NAME):
	@make -C $(LIBFT_PATH)
	@gcc $(FLAGS)

clean:
	@make -C $(LIBFT_PATH) clean
	@/bin/rm -rf *.o

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@/bin/rm -rf $(NAME)

re: fclean all
