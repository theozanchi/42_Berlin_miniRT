# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 15:19:38 by tzanchi           #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2023/12/15 19:52:46 by helauren         ###   ########.fr        #
=======
#    Updated: 2023/12/15 17:53:21 by tzanchi          ###   ########.fr        #
>>>>>>> 0e973cda8a7cc171623ab9d655c667eb227ae62d
#                                                                              #
# **************************************************************************** #

#Compiler targets and libraries
# -fsanitize=address
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g 
LDFLAGS		=	-Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
NAME		=	miniRT
LIBFT		=	libft.a
LIBMLX		=	libmlx.a

# Directories
SRCS_DIR	=	./src/
HEAD_DIR	=	./inc/
LIBFT_DIR	=	./libft/
LIBMLX_DIR	=	./minilibx-linux/
OBJ_DIR		=	${SRCS_DIR}.o

# Colours, symbols and utils
GREEN		=	\033[1;32m
LIGHT_GREEN	=	\033[1;92m
CYAN		=	\033[1;36m
LIGHT_CYAN	=	\033[1;96m
YELLOW		=	\033[1;33m
LIGHT_YELLOW=	\033[1;93m
RED			=	\033[1;31m
LIGHT_RED	=	\033[1;91m
NC			=	\033[0m
BOLD		=	\033[1m
TICK		=	✓

TEST_SRC	=	./src/ray_tracing/render_scene.c \
				./src/ray_tracing/test_main.c \
				./src/free/free.c \
				./src/algebra_utils/matrix_calculation.c

TEST_OBJS	=	${patsubst ${SRCS_DIR}%, ${OBJ_DIR}/%, ${TEST_SRC:.c=.o}}

SRCS		=	$(wildcard src/*.c) \
				$(wildcard src/*/*.c)
#SRC_NR		=	${words ${SRCS}}

OBJS		=	${patsubst ${SRCS_DIR}%, ${OBJ_DIR}/%, ${SRCS:.c=.o}}

all:			project_logo ${OBJ_DIR}
				@make -s ${LIBFT}
				@make -s ${LIBMLX}
				@make -s ${NAME}

ttest:			${TEST_OBJS}
				@${CC} ${CFLAGS} ${LDFLAGS} ${TEST_OBJS} -I${HEAD_DIR} ${LIBFT_DIR}${LIBFT} ${LIBMLX_DIR}${LIBMLX} -o ttest
				@echo "${YELLOW}\nCompilation complete, test_theo executable at the root of the directory${NC}\n"

tclean:
				@if [ -d "${OBJ_DIR}" ]; \
				then \
					rm -r ${OBJ_DIR}; \
				fi

tfclean:		tclean
				rm ttest

tre:			tfclean ttest

${LIBFT}:
				@echo "${CYAN}\nCOMPILING $$(echo ${LIBFT} | tr '[:lower:]' '[:upper:]')${NC}"
				@if [ -d ${LIBFT_DIR} ]; \
				then git -C ${LIBFT_DIR} pull; \
				else git clone https://github.com/theozanchi/42_Berlin_libft.git ${LIBFT_DIR}; \
				fi
				make -C ${LIBFT_DIR}

${LIBMLX}:
				@echo "${CYAN}\nCOMPILING $$(echo ${LIBMLX} | tr '[:lower:]' '[:upper:]')${NC}"
				@if [ -d ${LIBFT_DIR} ]; then \
					wget https://cdn.intra.42.fr/document/document/22740/minilibx-linux.tgz; \
					tar -xf minilibx-linux.tgz; \
					rm minilibx-linux.tgz; \
				fi
				make -C ${LIBMLX_DIR}

${NAME}:		entry_message ${OBJS}
				@${CC} ${CFLAGS} ${OBJS} -I${HEAD_DIR} ${LIBFT_DIR}${LIBFT} ${LIBMLX_DIR}${LIBMLX} ${LDFLAGS} -o ${NAME}
				@echo "${YELLOW}\nCompilation complete, ${NAME} executable at the root of the directory${NC}\n"

${OBJ_DIR}:
				@if [ ! -d "${OBJ_DIR}" ]; \
				then mkdir -p "${OBJ_DIR}"; \
				fi

${OBJ_DIR}/%.o:	${SRCS_DIR}%.c
				@mkdir -p ${dir $@}
				@printf "Compiling ${notdir $<}"; \
				${CC} ${CFLAGS} -I${HEAD_DIR} -c $< -o $@; \
				printf "${GREEN}"; \
				printf " ${TICK}\n"; \
				printf "${NC}"; 


clean:
				@make -sC ${LIBFT_DIR} clean >/dev/null 2>&1
				@make -sC ${LIBMLX_DIR} clean >/dev/null 2>&1
#				@if [ ! -d "${OBJ_DIR}" ]; \
				then \
					echo "Repo already clean"; \
				else \
					echo "Removing all .o files"; \
					rm -r ${OBJ_DIR}; \
				fi
				@rm src/*.o src/*/*.o

fclean:			clean
				@make -sC ${LIBFT_DIR} fclean >/dev/null 2>&1
				@make -sC ${LIBMLX_DIR} clean >/dev/null 2>&1
				@echo "Removing archive files ${LIBFT} and ${LIBMLX}, removing ${NAME} executable from root"
				@rm -f ${NAME}

re:				fclean all

project_logo:
				@echo "${LIGHT_GREEN}                       ######   ####### ${NC}"
				@echo "${CYAN} #    #  #  #    #  #  #     #     #    ${NC}"
				@echo "${LIGHT_CYAN} ##  ##  #  ##   #  #  #     #     #    ${NC}"
				@echo "${YELLOW} # ## #  #  # #  #  #  ######      #    ${NC}"
				@echo "${LIGHT_YELLOW} #    #  #  #  # #  #  #   #       #    ${NC}"
				@echo "${RED} #    #  #  #   ##  #  #    #      #    ${NC}"
				@echo "${LIGHT_RED} #    #  #  #    #  #  #     #     #    ${NC}"
				@echo "\n              Henri Lauren, Théo Zanchi"
				
entry_message:
				@echo "${CYAN}\nCOMPILING $$(echo ${NAME} | tr '[:lower:]' '[:upper:]')\n${NC}${BOLD}Compiling necessary .o files${NC}"

.PHONY:			all clean fclean re project_logo entry_message