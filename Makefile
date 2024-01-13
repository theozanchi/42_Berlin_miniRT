# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 15:19:38 by tzanchi           #+#    #+#              #
#    Updated: 2024/01/13 15:45:51 by tzanchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Compiler targets and libraries
# -fsanitize=address
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g -O3
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

SRC			=	0.0_utils/algebra_utils_0.c \
				0.0_utils/algebra_utils_1.c \
				0.0_utils/debugging_utils.c \
				0.0_utils/mlx_utils.c \
				\
				0.1_debugging_outputs/others.c \
				0.1_debugging_outputs/output_parse.c \
				\
				0.2_error_msg/wrong_arg.c \
				\
				1_parsing/get_file_fd.c \
				1_parsing/parse_environment.c \
				1_parsing/parse_objects.c \
				1_parsing/parse_scene.c \
				\
				2_ray_tracing/cyl_norm_vec.c \
				2_ray_tracing/hit_object.c \
				2_ray_tracing/light.c \
				2_ray_tracing/normal_vector.c \
				2_ray_tracing/render_scene.c \
				2_ray_tracing/viewport.c \
				\
				3_free/free.c \
				\
				keypress.c \
				main.c

SRCS		=	$(addprefix ${SRCS_DIR}, ${SRC})		
SRC_NR		=	${words ${SRCS}}

OBJS		=	${patsubst ${SRCS_DIR}%, ${OBJ_DIR}/%, ${SRCS:.c=.o}}

all:			project_logo ${OBJ_DIR}
				@make -s ${LIBFT}
				@make -s ${LIBMLX}
				@make -s ${NAME}

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
				@if [ ! -d "${OBJ_DIR}" ]; \
				then \
					echo "Repo already clean"; \
				else \
					echo "Removing all .o files"; \
					rm -r ${OBJ_DIR}; \
				fi

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
				@echo "${CYAN}\nCOMPILING $$(echo ${NAME} | tr '[:lower:]' '[:upper:]')\n${NC}${BOLD}Compiling necessary .o files out of $(SRC_NR) files${NC}"

.PHONY:			all clean fclean re project_logo entry_message