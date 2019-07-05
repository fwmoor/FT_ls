NAME = ft_ls

LIBFT_PATH = ./libft/
SRC_PATH = ./srcs/
FLAGS = -Wall -Werror -Wextra
INC =  -I ./includes/ft_ls.h -I $(LIBFT_PATH)includes/
all: $(NAME)

$(NAME):
	@make -C $(LIBFT_PATH)
	@gcc $(FLAGS) -o $(NAME) $(SRC_PATH)*.c $(LIBFT_PATH)libft.a

%.o: %.c
	@gcc -c $< -o $@

clean:
	@make -C $(LIBFT_PATH) clean
	@/bin/rm -f *.o

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
