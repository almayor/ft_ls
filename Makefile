# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: unite <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 02:09:26 by unite             #+#    #+#              #
#    Updated: 2020/06/28 11:24:56 by unite            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC_NAME = \
./environment/get_blocksize.c \
./environment/get_environment.c \
./environment/get_lscolors.c \
./main.c \
./namstat/free_namstats.c \
./namstat/get_namstat.c \
./namstat/getdir_namstats.c \
./namstat/is_namstat/is_blk_namstat.c \
./namstat/is_namstat/is_chr_namstat.c \
./namstat/is_namstat/is_dir_namstat.c \
./namstat/is_namstat/is_exe_namstat.c \
./namstat/is_namstat/is_fifo_namstat.c \
./namstat/is_namstat/is_lnk_namstat.c \
./namstat/is_namstat/is_reg_namstat.c \
./namstat/is_namstat/is_sock_namstat.c \
./namstat/is_namstat/is_wht_namstat.c \
./namstat/iterdir_namstats.c \
./namstat/nblocks_namstats.c \
./namstat/print_namstats/get_access_namstat.c \
./namstat/print_namstats/get_acl.namstat.c \
./namstat/print_namstats/get_color_namstat.c \
./namstat/print_namstats/get_group_namstat.c \
./namstat/print_namstats/get_ino_namstat.c \
./namstat/print_namstats/get_name_namstat.c \
./namstat/print_namstats/get_nlink_namstat.c \
./namstat/print_namstats/get_size_namstat.c \
./namstat/print_namstats/get_suffix_namstat.c \
./namstat/print_namstats/get_time_namstat.c \
./namstat/print_namstats/get_user_namstat.c \
./namstat/print_namstats/get_xattr_namstat.c \
./namstat/print_namstats/print_namstats.c \
./namstat/process_namstats.c \
./namstat/recurse_namstats.c \
./namstat/sort_namstats/cmp_alnum_namstats.c \
./namstat/sort_namstats/cmp_atime_namstats.c \
./namstat/sort_namstats/cmp_birthtime_namstats.c \
./namstat/sort_namstats/cmp_ctime_namstats.c \
./namstat/sort_namstats/cmp_mtime_namstats.c \
./namstat/sort_namstats/cmp_size_namstats.c \
./namstat/sort_namstats/sort_namstats.c \
./options/get_options.c \
./options/set_option_1.c \
./options/set_option_A_.c \
./options/set_option_F_.c \
./options/set_option_G_.c \
./options/set_option_P_.c \
./options/set_option_R_.c \
./options/set_option_S_.c \
./options/set_option_T_.c \
./options/set_option_U_.c \
./options/set_option_a.c \
./options/set_option_at.c \
./options/set_option_c.c \
./options/set_option_d.c \
./options/set_option_e.c \
./options/set_option_f.c \
./options/set_option_h.c \
./options/set_option_i.c \
./options/set_option_l.c \
./options/set_option_m.c \
./options/set_option_n.c \
./options/set_option_o.c \
./options/set_option_p.c \
./options/set_option_r.c \
./options/set_option_s.c \
./options/set_option_t.c \
./options/set_option_u.c \
./options/set_options_env.c \
./utils/basename_path.c \
./utils/free_tab.c \
./utils/ft_atoi2.c \
./utils/ft_ldtoa2.c \
./utils/ft_lltoa2.c \
./utils/ft_ulltoa2.c \
./utils/join_path.c \
./utils/len_tab.c \
./utils/sort_tab.c \

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

CFLAGS += -Werror
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

.PHONY : all clean fclean re re-shallow test

all : $(PATHL)/libftprintfgnl.a $(NAME)

fclean : clean
	$(RM) -f $(NAME)

clean :
	$(RM) -rf $(PATHO)
	$(MAKE) -C $(PATHL) fclean

re-shallow :
	$(RM) -f $(NAME)
	$(RM) -rf $(PATHO)
	$(MAKE) $(NAME)

re : fclean all

$(PATHL)/libftprintfgnl.a :
	$(MAKE) -C $(PATHL)

################################################################################
