NAME = libftprintf.a

SRCS = ft_printf.c ft_print_memory.c\
	ft_putchar.c ft_putstr.c\
	ft_putnbr.c ft_putnbr_u.c\
	ft_puthex.c\

OBJS = $(SRCS:.c=.o)

CC = cc -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f

$(NAME): $(OBJS)
	$(AR) $@ $^
# $@ $(NAME)
# $^ $(OBJS)

all: $(NAME)

%.o: %.c
	$(CC) -c $< -o $@
# $< %.c
# $@ %.o

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus

#a single character
#a string
#address
#decimal number & integer
#unsigned decimal number
#exadecimal (base 16) lowercase & uppercase format
#a percent sign

#va_list = pointer data type for storing the address of a vriable argument.
#		= It’s effectively a pointer to an arguments in the var-args array.

#va_arg = Get the next item in a list of variable arguments
#va_arg(*a, int) =  ap points next factor or int and return one before next factor

#va_start = initialises a pointer of a type va_list to the first variable argument address
#va_start(ap, str) = ap points next the str

#va_end = initialises the variable argument list pointer to NULL
#va_end(ap) = ap is initialised
