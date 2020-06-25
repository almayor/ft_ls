# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: unite <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 02:09:26 by unite             #+#    #+#              #
#    Updated: 2020/06/25 08:57:32 by unite            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC_NAME = \
options/get_options.c \
namstat/print_namstats/print_namstats.c \
namstat/process_namstats.c \
namstat/getdir_namstats.c \
namstat/iterdir_namstats.c \
namstat/sort_namstats/cmp_mtime_namstats.c \
namstat/sort_namstats/cmp_alnum_namstats.c \
namstat/sort_namstats/sort_namstats.c \
namstat/recurse_namstats.c \
namstat/free_namstats.c \
namstat/get_namstat.c \
utils/get_basename.c \
utils/join_path.c \
utils/is_file.c \
utils/is_dir.c \
utils/free_tab.c \
utils/len_tab.c \
utils/count_files.c \
utils/sort_tab.c \
main.c \

################################################################################

CC = gcc
RM = rm
MKDIR = /bin/mkdir

################################################################################

PATHS = src
PATHO = obj
PATHL = libftprintfgnl
PATHI = include $(PATHL)

################################################################################

COMPILE = $(CC) -c
LINK = $(CC)

CFLAGS += -O3 -std=gnu11 -ffast-math -march=native
CFLAGS += -MMD
CFLAGS += $(foreach path, $(PATHI), -I$(path))

LIBS = -lftprintfgnl -L $(PATHL)

################################################################################

ifeq ($(DEBUG), 1) 
	COMPILE += -g
endif

################################################################################

SRC = $(patsubst %.c, $(PATHS)/%.c, $(SRC_NAME))
OBJ = $(patsubst %.c, $(PATHO)/%.o, $(SRC_NAME))
DEP += $(patsubst %.c, $(PATHO)/%.d, $(SRC_NAME))

$(NAME) : $(OBJ)
	$(LINK) $^ -o $@ $(LIBS)

$(PATHO)/%.o : $(PATHS)/%.c
	$(MKDIR) -p $(@D)
	$(COMPILE) $(CFLAGS) $< -o $@

-include $(DEP)

################################################################################

.DEFAULT_GOAL = all

.PHONY : all clean fclean re test

all : $(PATHL)/libftprintfgnl.a $(NAME)

fclean : clean
	$(RM) -f $(NAME)

clean :
	$(RM) -rf $(PATHO)
	$(MAKE) -C $(PATHL) fclean

re : fclean all

$(PATHL)/libftprintfgnl.a :
	$(MAKE) -C $(PATHL)

################################################################################
