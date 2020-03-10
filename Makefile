# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/07 15:02:44 by nhamill           #+#    #+#              #
#    Updated: 2020/03/10 14:03:33 by dholiday         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_ASM = asm
NAME_VM = corewar
NAME_DIS = dis_asm

FLAGS = -Wall -Wextra -Werror -MMD -MP -g

CC = gcc

SRCS_ASM =	main.c init.c metka.c proc.c useful_helpers.c trim_and_comment.c \
			label.c look_at_list.c some_useful_mass.c spl.c tranc.c negative.c \
			codirovka.c write_to_file.c clean.c  write_to_file_spec.c \
			process.c check_labels.c labels_only.c search_label.c \
			add.c and.c aff.c forki.c ld.c ldi.c lfork.c live.c lld.c lldi.c \
			or.c st.c sti.c sub.c xor.c zjmp.c

SRCS_VM = 	main.c valid_cmd.c help_valid_cmd.c valid_files.c init_arena.c \
			op.c struct_cursor.c help_op.c struct_name.c arena.c error.c  \
			cycle.c live.c ld.c st.c add_sub.c and_or_xor.c zjmp_aff.c fork.c \
			ldi.c init_visu.c help_visu.c visu_update.c visu_get_windows.c \
			create_player.c free_all.c debug.c debug_num.c visu_arena.c \
			debug_gen.c debug10.c debug_arg.c debug1.c

SRCS_DIS =	dis_main.c helpers.c write_inc.c magic.c valid.c read_file.c

DIR_SRCS_ASM = ./srcs/asm
DIR_SRCS_VM = ./srcs/vm
DIR_SRCS_DIS = ./srcs/dis

DEP_ASM = $(addprefix $(DIR_SRCS_ASM)/,$(patsubst %.c,%.d,$(SRCS_ASM)))
DEP_VM = $(addprefix $(DIR_SRCS_VM)/,$(patsubst %.c,%.d,$(SRCS_VM)))
DEP_DIS = $(addprefix $(DIR_SRCS_DIS)/,$(patsubst %.c,%.d,$(SRCS_DIS)))
OBJ_ASM = $(addprefix $(DIR_SRCS_ASM)/,$(SRCS_ASM:.c=.o))
OBJ_VM = $(addprefix $(DIR_SRCS_VM)/,$(SRCS_VM:.c=.o))
OBJ_DIS = $(addprefix $(DIR_SRCS_DIS)/,$(SRCS_DIS:.c=.o))

DIR_LIB = libft
LIB = $(DIR_LIB)/libft.a

INC_ASM = -I includes/asm
INC_VM = -I includes/vm
INC_DIS = -I includes/dis
INCS = $(INC_ASM) $(INC_VM) $(INC_DIS) -I includes -I $(DIR_LIB)

LIBIN = -L $(DIR_LIB) -lft

LIBIN_NCURSES = -lncurses

all: $(NAME_ASM) $(NAME_DIS) $(NAME_VM)

$(NAME_ASM): $(LIB) $(OBJ_ASM)
		$(CC) -o $@ $(OBJ_ASM) $(LIBIN)

$(NAME_VM): $(LIB) $(OBJ_VM)
		$(CC) -o $@ $(OBJ_VM) $(LIBIN) $(LIBIN_NCURSES)

$(NAME_DIS): $(LIB) $(OBJ_DIS)
		$(CC) -o $@ $(OBJ_DIS) $(LIBIN)

LIBA:
		@make -C $(DIR_LIB)

.PHONY: LIBA

$(LIB): LIBA

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@ $(INCS)

-include $(DEP_ASM) $(DEP_VM) $(DEP_DIS)

clean:
		@make -C $(DIR_LIB) clean
		@rm -f $(OBJ_ASM) $(OBJ_VM) $(OBJ_DIS) $(DEP_ASM) $(DEP_VM) $(DEP_DIS)

fclean: clean
		@make -C $(DIR_LIB) fclean
		@rm -f $(NAME_ASM) $(NAME_VM) $(NAME_DIS)

re: fclean all
