NAME = libft.a
CFLAGS = -Wall -Wextra -Werror -I ./
CC = cc

FILE = \
	ft_bzero.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_memset.c\
	ft_strlen.c\
	ft_strchr.c\
	ft_strncmp.c\
	ft_strrchr.c\
	ft_tolower.c\
	ft_toupper.c\
	ft_memcpy.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memmove.c\
	ft_strnstr.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_atoi.c\
	ft_strdup.c\
	ft_calloc.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	get_next_line_utils.c\
	get_next_line.c\
	ft_printf.c\
	ft_putnbr_base_ten.c\
	ft_putstr_printf.c\
	ft_convert_hexa.c\
	ft_putnbr_unsigned.c\
	ft_putnbr_pointer.c\
	ft_putchar_printf.c\
	ft_putchar.c\

OBJECTS = $(FILE:%.c=%.o)

FILE_BONUS = \
	ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstsize.c\
	ft_lstlast.c\
	ft_lstadd_back.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	ft_lstiter.c\
	ft_lstmap.c\

BONUS_OBJECTS = $(FILE_BONUS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $?

bonus: 
	@make OBJECTS="$(BONUS_OBJECTS)"

clean:
	@rm -rf $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus