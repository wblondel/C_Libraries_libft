# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/29 22:47:41 by wblondel     #+#   ##    ##    #+#        #
#    Updated: 2018/04/19 18:13:17 by wblondel    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

# Compiler configuration
CC = gcc
CFLAGS = -Wall -Wextra -Werror

## Flags for the C preprocessor
CPPFLAGS = -I$(INC_PATH)

## Name of the library
NAME = libft.a

# Project related variables
SRC_PATH = src
SRC_NAME =\
    basics/chars/check/ft_isalnum.c\
    basics/chars/check/ft_isalpha.c\
    basics/chars/check/ft_isascii.c\
    basics/chars/check/ft_isblank.c\
    basics/chars/check/ft_iscntrl.c\
    basics/chars/check/ft_isdigit.c\
    basics/chars/check/ft_isgraph.c\
    basics/chars/check/ft_islower.c\
    basics/chars/check/ft_isprint.c\
    basics/chars/check/ft_ispunct.c\
    basics/chars/check/ft_isspace.c\
    basics/chars/check/ft_isupper.c\
    basics/chars/output/ft_putchar_fd.c\
    basics/chars/output/ft_putchar.c\
    basics/chars/transform/ft_tolower.c\
    basics/chars/transform/ft_toupper.c\
    basics/maths/ft_abs.c\
    basics/maths/ft_factorial.c\
    basics/maths/ft_gcd.c\
    basics/maths/ft_labs.c\
    basics/maths/ft_lcm.c\
    basics/maths/ft_sqrt.c\
    basics/memory/create/ft_memalloc.c\
    basics/memory/delete/ft_memdel.c\
    basics/memory/iterate/ft_memchr.c\
    basics/memory/iterate/ft_memcmp.c\
    basics/memory/transform/ft_bzero.c\
    basics/memory/transform/ft_memccpy.c\
    basics/memory/transform/ft_memcpy.c\
    basics/memory/transform/ft_memmove.c\
    basics/memory/transform/ft_memset.c\
    basics/memory/transform/ft_swap_c.c\
    basics/memory/transform/ft_swap_i.c\
    basics/memory/transform/ft_swap.c\
    basics/numbers/convers/ft_atoi.c\
    basics/numbers/convers/ft_itoa.c\
    basics/numbers/maths/ft_intlen.c\
    basics/numbers/output/integers/ft_putnbr_fd.c\
    basics/numbers/output/integers/ft_putnbr.c\
    basics/strings/create/ft_strdup.c\
    basics/strings/create/ft_strjoin.c\
    basics/strings/create/ft_strmap.c\
    basics/strings/create/ft_strmapi.c\
    basics/strings/create/ft_strndup.c\
    basics/strings/create/ft_strnew.c\
    basics/strings/create/ft_strnjoin.c\
    basics/strings/create/ft_strsplit.c\
    basics/strings/create/ft_strsub.c\
    basics/strings/create/ft_strtrim.c\
    basics/strings/delete/ft_strdel.c\
    basics/strings/iterate/ft_str_endswith.c\
    basics/strings/iterate/ft_str_startswith.c\
    basics/strings/iterate/ft_strchr.c\
    basics/strings/iterate/ft_strcmp.c\
    basics/strings/iterate/ft_strcountwords.c\
    basics/strings/iterate/ft_strequ.c\
    basics/strings/iterate/ft_striter.c\
    basics/strings/iterate/ft_striteri.c\
    basics/strings/iterate/ft_strlen.c\
    basics/strings/iterate/ft_strncmp.c\
    basics/strings/iterate/ft_strnequ.c\
    basics/strings/iterate/ft_strnstr.c\
    basics/strings/iterate/ft_strrchr.c\
    basics/strings/iterate/ft_strstr.c\
    basics/strings/output/ft_putendl_fd.c\
    basics/strings/output/ft_putendl.c\
    basics/strings/output/ft_putstr_fd.c\
    basics/strings/output/ft_putstr.c\
    basics/strings/transform/ft_strcat.c\
    basics/strings/transform/ft_strclr.c\
    basics/strings/transform/ft_strcpy.c\
    basics/strings/transform/ft_strlcat.c\
    basics/strings/transform/ft_strmerge.c\
    basics/strings/transform/ft_strncat.c\
    basics/strings/transform/ft_strncpy.c\
    basics/strings/transform/ft_strrev.c\
    basics/strings/transform/ft_strtolower.c\
    basics/strings/transform/ft_strtoupper.c\
    containers/list/ft_lstadd.c\
    containers/list/ft_lstdel.c\
    containers/list/ft_lstdelone.c\
    containers/list/ft_lstiter.c\
    containers/list/ft_lstmap.c\
    containers/list/ft_lstnew.c\
	utils/file/ft_readline.c

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OBJS_DIRS = $(sort $(dir $(OBJ)))

INC_PATH = inc
INC_NAME =\
	libft/basics/booleans.h\
	libft/basics/chars.h\
	libft/basics/maths.h\
	libft/basics/memory.h\
	libft/basics/numbers.h\
	libft/basics/strings.h\
	libft/containers/list.h

HEADER = $(addprefix $(INC_PATH)/,$(INC_NAME))

# Entry point
all: $(NAME)

# Compiles libft
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Creates obj/ directory
# It's a prerequisite to compile any OBJ
$(OBJS_DIRS):
	mkdir -p $@

# Adds the dependency to create the directory
# before to compile an object
$(OBJ): | $(OBJS_DIRS)

# Compiles all the src into obj
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) -r $(OBJ_PATH)

.PHONY: fclean
fclean: clean
	$(RM) -r $(NAME) $(NAME).dSYM

.PHONY: re
re: fclean
	$(MAKE) all
