# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/04 14:37:16 by shthevak     #+#   ##    ##    #+#        #
#    Updated: 2019/01/09 04:35:39 by shthevak    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY : all clean fclean re

NAME = libftprintf.a
# **************************************************************************** #
#									PATH                                       #
# **************************************************************************** #

SRC_PATH= ./
OBJ_PATH= ./obj/
INC_PATH= ./

# **************************************************************************** #
# 									SRCS                                       #
# **************************************************************************** #

SRC_NAME = print.c  modulo.c\
		   struct/t_printcrea.c struct/t_printget.c\
		   struct/t_len.c\
		   functions/strfunc.c functions/usefull.c functions/creafill.c\
		   letters/type_c.c letters/type_s.c\
		   style/color.c style/format.c\
		   numbers/dconvert.c\
		   numbers/ft_nullpoint.c numbers/type_u.c numbers/typeint.c\
		   numbers/u_add.c numbers/uconvert.c numbers/x_add.c\
		   numbers/o_add.c numbers/type_b.c numbers/type_k.c\
		   numbers/type_kk.c numbers/type_d.c numbers/d_addpre.c\
		   unicode/bitise.c unicode/bitodec.c unicode/bytechart.c\
		   unicode/type_w.c unicode/type_ws.c unicode/unicode.c\
		   unicode/ft_ureplace.c

INC_NAME= ft_printf.h

# **************************************************************************** #
#  									VAR                                        #
# **************************************************************************** #

OBJ_NAME= $(SRC_NAME:.c=.o)
INC= $(addprefix $(INC_PATH), $(INC_NAME))
OBJ= $(addprefix $(OBJ_PATH), $(OBJ_NAME))
SRC= $(addprefix $(SRC_PATH), $(SRC_NAME))

# **************************************************************************** #
#  									FLAG                                       #
# **************************************************************************** #

ifndef FLAGS
FLAGS= -Wall -Werror -Wextra
endif

NORME= norinette

# **************************************************************************** #
#  									STYLE                                      #
# **************************************************************************** #

SAY=@echo
SAYD=@echo $

R_1= \033[1A
CLEAR_R= \033[J
WHITE= "\033[1;37m
GREEN= "\033[1;32m
RED= "\033[1;31m
YELLOW= "\033[1;33m
BLUE= "\033[1;34m
END= \033[0m"
MY_HEADER= \033[1J \033[H \033[18A\
		 \n	\# **************************************************************************** \#\
		 \n	\#                                                            LE -/             \#\
		 \n	\#                                                               /              \#\
		 \n	\#    ft_printf🖋                                       .::    .:/ .      .::    \#\
		 \n	\#                                                  +:+:+   +:    +:  +:+:+     \#\
		 \n	\#    ⁙⁙⁙⁙ ⁙   ⁙   ⁙                                 +:+   +:    +:    +:+      \#\
		 \n	\#    ⁙    ⁙   ⁙   ⁙                                \#+\#   \#+    \#+    \#+\#       \#\
		 \n	\#    ⁙⁙⁙⁙ ⁙⁙⁙ ⁙⁙  ⁙⁙⁙ ⁙⁙⁙ ⁙   ⁙  ⁙   ⁙  ⁙         \#+\#   \#\#    \#\#    \#+\#        \#\
		 \n	\#       ⁙ ⁙ ⁙ ⁙   ⁙ ⁙ ⁙⁙   ⁙ ⁙  ⁙⁙⁙  ⁙⁙          \#\#\#    \#+. /\#+    \#\#\#.fr      \#\
		 \n	\#    ⁙⁙⁙⁙ ⁙ ⁙ ⁙⁙⁙ ⁙ ⁙ ⁙⁙⁙   ⁙  ⁙   ⁙ ⁙  ⁙                  /                   \#\
		 \n	\#                                                         /                    \#\
		 \n	\# **************************************************************************** \#\
		 \n\n$(END)

# **************************************************************************** #
# 									REGLES                                     #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	$(SAY) $(GREEN) $(MY_HEADER)
	@sleep 0.3
	$(SAY) $(GREEN) $(R_1) $(CLEAR_R) 	                        ⚜ ⚜ ⚜  ft_printf is done ⚜ ⚜ ⚜ \n$(END)

$(OBJ_PATH):
	$(SAY) $(BLUE) $(MY_HEADER)
	@mkdir -p $(OBJ_PATH) 2> /dev/null
	@sleep 0.3
	@mkdir -p $(OBJ_PATH)functions/
	@mkdir -p $(OBJ_PATH)struct/
	@mkdir -p $(OBJ_PATH)letters/
	@mkdir -p $(OBJ_PATH)style/
	@mkdir -p $(OBJ_PATH)numbers/
	@mkdir -p $(OBJ_PATH)unicode/
	$(SAY) $(YELLOW) $(R_1) $(CLEAR_R)  	                          Directory ./obj created$(END)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	 @gcc $(FLAGS) -I $(INC) -o $@ -c $<
	 $(SAY) $(YELLOW) $(R_1) $(CLEAR_R)  		              Binary File done : $*$(END)
	 @sleep 0.1

clean:
	$(SAY) $(RED) $(MY_HEADER)
	@rm -rf $(OBJ_PATH) 2> /dev/null
	@sleep 0.3
	$(SAY) $(RED) $(R_1) $(CLEAR_R) 	             ☠ Binary files directory \"/obj\" hab been deleted.☠\n$(END)

fclean: clean
	@rm -rf $(NAME) 2> /dev/null
	@sleep 0.3
	$(SAY) $(RED) $(R_1) $(CLEAR_R)     	                     ☹ ft_printf has been deleted.☹\n$(END)
	@sleep 0.3

re: fclean all
