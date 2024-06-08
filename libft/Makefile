NAME	=	libft.a

SRCS	=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
				ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
				ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
				ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
				ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c 

OBJS = $(SRCS:.c=.o)
GNL_DIR = get_next_line
GNL_SRCS= $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)
PRINTF_DIR = printf
PRINTF_SRCS = $(PRINTF_DIR)/ft_func.c $(PRINTF_DIR)/ft_printf.c 
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)

CC	=	gcc
RM	=	rm -f
FLAGS	= -Wall -Wextra -Werror

$(NAME): $(GNL_OBJS) $(PRINTF_OBJS) $(OBJS) 
		$(CC) $(FLAGS) -c $(SRCS) 
		ar rc $(NAME) $(PRINTF_OBJS) $(GNL_OBJS) $(OBJS)

all: $(NAME)

clean:	
		$(RM) $(GNL_OBJS) $(OBJS)  $(PRINTF_OBJS)


fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re