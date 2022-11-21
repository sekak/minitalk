NAME = server
NAME1 = client

Header = minitalk.h

Files =   functions.c client.c server.c 
Files_O = $(Files:.c=.o)

Files1 =   functions.c client.c server.c 
Files_O1 = $(Files1:.c=.o)
 
 %.o: %.c 
	gcc -Wall -Wextra -Werror -c $< -o $@
	
$(NAME): $(Files_O)
	ar rcs $(NAME) $(Files_O)
$(NAME1): $(Files_O1)
	ar rcs $(NAME1) $(Files_O1)

all: $(NAME) $(NAME1)

clean:
	rm -rf $(Files_O)  

fclean: clean
	rm -rf $(NAME)$(NAME1)

re: fclean 
		$(NAME) $(NAME1) 

.PHONY: all bonus clean fclean re



# # NAME = server
# # NAME1 = client

# # Header = minitalk.h

# # Files =   functions.c server.c 
# # Files_O = $(Files:.c=.o)
# # Files1 =   functions.c client.c
# # Files_O1 = $(Files1:.c=.o)

# # all: $(NAME) $(NAME1)

# # %.o: %.c 
# # 	gcc -Wall -Wextra -Werror -c $< -o $@
	
# # $(NAME): $(Files_O) server.o
# # 	cc -Wall -Werror -Wextra $(Files_O) -o server

# # $(NAME1): $(Files_O1) client.o
# # 	cc -Wall -Werror -Wextra $(Files_O1) -o client

# # clean:
# # 	rm -rf $(Files_O) $(Files_O1) 

# # fclean: clean
# # 	rm -rf $(NAME) $(NAME1)

# # re: fclean 
# # 	$(NAME) $(NAME1) 

# # .PHONY: all bonus clean fclean re

# NAME1 = server
# NAME2 = client

# FILES = functions.c
# FILES_O = $(FILES:.c=.o)


# all: $(NAME1) $(NAME2)

# %.o: %.c
# 	cc -Wall -Wextra -Werror -c $< -o $@

# $(NAME1): $(FILES_O) server.o client.o
# 	cc -Wall -Wextra -Werror $(FILES_O) server.o -o server
# 	cc -Wall -Wextra -Werror $(FILES_O) client.o -o client

# $(NAME2): $(NAME1)
	

# clean:
# 	rm -rf $(FILES_O)

# fclean: clean
# 	rm -rf $(NAME2) $(NAME1)

# re: fclean all 