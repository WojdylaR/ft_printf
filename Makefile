# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rwojdyla <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2020/01/27 20:11:56 by rwojdyla     #+#   ##    ##    #+#        #
#    Updated: 2020/03/13 00:07:57 by rwojdyla         ###   ########lyon.fr    #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
LIBFT = libft
DIR_S = src
DIR_O = obj
HEADER = include
SOURCES = ft_printf.c \
		  ft_fill_list.c \
		  ft_convert_hexa.c \
		  ft_utoa.c \
		  ft_print_arg.c \
		  ft_free_list.c \
		  put_c_p.c \
		  put_cond_3_4.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))
OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	${MAKE} -C $(LIBFT)
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)/ft_printf.h
	mkdir -p obj
	$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

norme:
	norminette ./libft/
	@echo
	norminette ./$(HEADER)/
	@echo
	norminette ./$(DIR_S)/

clean:
	rm -f $(OBJS)
	rm -rf $(DIR_O)
	make clean -C $(LIBFT)

comp: all
	gcc main.c libftprintf.a

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)
re: fclean all

.PHONY: fclean re norme all clean
