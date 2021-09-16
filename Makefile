NAME = so_long
CC = clang
CFLAGS = -Werror -Wextra -Wall -g
MLXFLAGS = -lmlx -framework OPENGL -framework Appkit
RM = rm -rfv

FILES = so_long

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

all : $(NAME)

.c.o: $(FILES) $(NAME)
	@$(CC) $(CFLAGS) -Imlx -c -o $@ $^

$(NAME) : $(OBJS) 
	@$(MAKE) -C libft 
	@$(MAKE) -C mlx 
	mv mlx/libmlx.a .
	$(CC) $(CFLAGS) $(OBJS) -L . $(MLXFLAGS) -o $(NAME) 

clean :
	@$(RM) $(OBJS) libft/*.o mlx/*.o
	@printf "\e[31m.o files deleted\e[0m\n"

fclean : clean
	@$(RM) $(NAME) libft/libft.a libmlx.a 
	@printf "\e[31mso_long, libmlx.a and libft.a deleted\e[0m\n"

re: fclean all

.PHONY: all clean fclean re
