/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 23:24:40 by unite             #+#    #+#             */
/*   Updated: 2020/07/04 03:25:34 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <errno.h>
# include <grp.h>
# include <limits.h>
# include <pwd.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <time.h>
# include <unistd.h>
# include "libftprintfgnl.h"

# if defined(__has_include)
#  if __has_include("sys/acl.h")
#   include <sys/acl.h>
#  endif
# endif

# if !defined(__APPLE__) && !defined(__NetBSD__) 
#  define st_atimespec st_atim
#  define st_ctimespec st_ctim
#  define st_mtimespec st_mtim
# endif

# if !defined(_DARWIN_FEATURE_64_BIT_INODE)
#  define st_birthtimespec st_ctim
# endif

# include "ansi_escape_codes.h"
# include "buffer_limits.h"
# include "environment.h"
# include "namstat.h"
# include "options.h"
# include "utils.h"

#endif
