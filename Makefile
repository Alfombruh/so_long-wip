.DEFAULT_GOAL := all
NAME = so_long
CC = clang
CFLAGS = -Werror -Wextra -Wall -g
MLXFLAGS = -lmlx -framework OPENGL -framework Appkit
RM = rm -f

FILES = lops

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

all : $(NAME)

.c.o: $(FILES) $(NAME)
	@$(CC) $(CFLAGS) -Imlx -c -o $@ $^

$(NAME) : $(OBJS) 
	@$(MAKE) -s -C libft 
	@$(MAKE) -s -C mlx 
	@mv mlx/libmlx.a .
	@$(CC) $(CFLAGS) $(OBJS) -L . $(MLXFLAGS) -o $(NAME) 

clean :
	@$(RM) $(OBJS) libft/*.o mlx/*.o
	@printf "\e[31m.o files deleted\e[0m\n"

fclean : clean
	@$(RM) $(NAME) libft/libft.a libmlx.a 
	@printf "\e[31mso_long, libmlx.a and libft.a deleted\e[0m\n"

re: fclean all

.PHONY: all clean fclean re
