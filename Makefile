PHONY = all clean fclean re

NAME = ft_ls

# **************************************************************************** #
#          PATH                                                                #
# **************************************************************************** #

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./includes/
PRINT_PATH = ./ft_printf/

# **************************************************************************** #
#           SRCS                                                               #
# **************************************************************************** #

PRT_NAME = libftprintf.a

SRC_NAME = add.c curdir.c dir.c error.c frees.c ft_args.c ft_print_col.c\
		   ft_print_line.c ft_str.c get_details.c main.c others.c parsing.c\
		   print_opt.c print_rights.c show.c sort.c sort_err.c sort_t.c\
		   structs.c
INC_NAME = ls.h

# **************************************************************************** #
#           VAR                                                                #
# **************************************************************************** #

OBJ_NAME= $(SRC_NAME:.c=.o)

INC = $(addprefix $(INC_PATH), $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
PRT = $(addprefix $(PRINT_PATH), $(PRT_NAME))

# **************************************************************************** #
#           FLAG                         						               #
# **************************************************************************** #

ifndef FLAG
	FLAGS = -Wall -Wextra -Werror
endif

# **************************************************************************** #
#           REGLES                                                             #
# **************************************************************************** #

all : make_printf $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ) $(INC) $(PRT)
	@printf "Compiling $(NAME)..."
	@gcc $(FLAGS) -o $@ $(OBJ) $(PRT)
	@printf "\033[32m[OK]\033[0m\n"

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH) 2> /dev/null

make_printf:
	@make -C ft_printf/

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC)
	@gcc $(FLAGS) -I $(INC) -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)
	@make clean -C ft_printf/

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ft_printf/

re: fclean all
