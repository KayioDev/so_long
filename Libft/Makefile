NAME = libft.a

BONUS_SRCS= \
	ft_lstadd_back_bonus.c\
	ft_lstadd_front_bonus.c\
	ft_lstclear_bonus.c\
	ft_lstdelone_bonus.c\
	ft_lstiter_bonus.c\
	ft_lstlast_bonus.c\
	ft_lstnew_bonus.c\
	ft_lstsize_bonus.c\
	ft_lstmap_bonus.c

SRCS = \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_split.c\
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c\
	get_next_line.c\
	ft_itoa.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -fPIC

all: $(NAME)

$(NAME): $(OBJS) $(BONUS_OBJS)
	@echo "📦 Compilando arquivos obrigatórios..."
	@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
	@echo "✅ Todos os arquivos foram compilados com sucesso!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@


bonus: .bonus_build

.bonus_build: $(OBJS) $(BONUS_OBJS)
	@echo "📦 Compilando arquivos bônus e obrigatórios..."
	@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
	@touch .bonus_build
	@echo "✅ Todos os arquivos foram compilados com sucesso!"

clean:
	@rm -f $(OBJS)
	@rm -f $(BONUS_OBJS)
	@rm -f .bonus_build
fclean: clean
	@rm -f $(NAME)
	@echo "❗Todos os arquivos foram removidos com sucesso!"

re: fclean all

.PHONY: all clean fclean re check bonus
