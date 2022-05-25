CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS = ./ft_bzero.c ./ft_memcpy.c ./ft_memset.c ./ft_memccpy.c ./ft_memchr.c ./ft_memcmp.c ./ft_strlen.c ./ft_isalpha.c ./ft_isdigit.c ./ft_isalnum.c ./ft_isascii.c ./ft_isprint.c ./ft_tolower.c ./ft_toupper.c ./ft_strchr.c ./ft_strrchr.c ./ft_strncmp.c ./ft_strlcpy.c ./ft_atoi.c ./ft_itoa.c ./ft_memmove.c ./ft_putchar_fd.c ./ft_putendl_fd.c ./ft_putnbr_fd.c ./ft_putstr_fd.c ./ft_split.c ./ft_strdup.c ./ft_strjoin.c ./ft_strmapi.c ./ft_substr.c ./ft_strtrim.c ./ft_calloc.c ./ft_strnstr.c ./ft_strlcat.c
SRCS_B = ./ft_lstnew.c ./ft_lstadd_front.c ./ft_lstadd_back.c ./ft_lstsize.c ./ft_lstlast.c ./ft_lstdelone.c ./ft_lstclear.c ./ft_lstiter.c
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJS_B)
	ar rc $(NAME) $^

clean :
	rm -f $(OBJS) $(OBJS_B)

fclean : clean
	rm -f $(NAME)

re : fclean all
