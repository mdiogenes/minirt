# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 12:18:28 by msoler-e          #+#    #+#              #
#    Updated: 2022/10/27 13:01:29 by msoler-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_FILES		=	main.c \
					ft_error.c
SRCS_DIR		=	srcs
OBJS_DIR		=	obj
OBJS_SUBS		= 	obj
SRCS 			=	$(addprefix $(SRCS_DIR)/,$(SRCS_FILES))
OBJS			=	$(addprefix $(OBJS_DIR)/,$(SRCS_FILES:.c=.o))
LIB_DIR			=	libft
LIB 			=	libft.a
LEAKS			=	valgrind --quiet --leak-check=full --track-fds=yes --trace-children=yes -s -q
CC				=	gcc
RM				= 	rm -rf
CFLAGS			=	-Wall -Wextra -Werror
HEADER			=	minirt.h
HEADER_DIR		=	include
NAME			=	miniRT


all: $(OBJS_SUBS) libs $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIB_DIR)/$(LIB) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

libs:
	$(MAKE) -C ./$(LIB_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER_DIR)/$(HEADER)
	$(CC) $(CFLAGS) -I$(LIB_DIR)/inc -I$(HEADER_DIR) -c $< -o $@

$(OBJS_SUBS):
	-mkdir $(OBJS_SUBS)

clean:
	$(MAKE) -C ./$(LIB_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C ./$(LIB_DIR) fclean
	$(RM) $(NAME)
	$(RM) $(OBJS_SUBS)

leak: all
	$(LEAKS) ./$(NAME)

re:	fclean libs $(OBJS_SUBS) $(NAME)

.PHONY: all clean fclean re leak
