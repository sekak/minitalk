NAME = libftprintf.a
Header = printf.h

Files = func1.c func2.c printf.c
Files_o = $(Files:.c=.o)

%.o: %.c
	gcc -Wall -Wextra -Werror -c $< -o $@


$(NAME) : $(Files_o)
	ar rcs $(NAME) $(Files_o)


all : $(NAME)


clean: 
	rm -f $(Files_o)


fclean: clean
	rm -f $(NAME)

re:	fclean $(NAME)
	

