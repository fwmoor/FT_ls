NAME =		libftprintf.a

FLAG =		-Wall -Werror -Wextra -I 

FTDR =		libft/

FTFL =		ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	  ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c \
	  ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c \
	  ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
	  ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c \
	  ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
	  ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c \
	  ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
	  ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c \
	  ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
	  ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
	  ft_tolower.c ft_toupper.c ft_foreach.c ft_strrev.c ft_factorial.c \
	  ft_sqrt.c ft_power.c ft_str_upper.c ft_extra.c ft_flags.c ft_middle.c \
	  ft_misc.c ft_printing.c ft_printf.c ft_strfill.c ft_middle_2.c \
	  get_next_line.c

LOBJ =		$(FTFL:.c=.o)

all: $(NAME)

$(LOBJ): %.o: %.c
	@gcc -c $(FLAG) FTFL $< -o $@

$(NAME): $(LOBJ)
	@ar rcs $(NAME) $(LOBJ)
	@ranlib $(NAME)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)
	@rm -rf a.out

re: fclean all

.PHONY: all fclean clean re