/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:07:56 by blee              #+#    #+#             */
/*   Updated: 2018/04/20 15:06:21 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <dirent.h>
# include <time.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <pwd.h>
# include <sys/xattr.h>
# include <stdio.h>

typedef struct		s_file
{
	char			*name;
	char			*path;
	char			type;
	char			*perm;
	long			links;
	char			*usr_name;
	char			*grp_name;
	long long		size;
	struct timespec	mtime;
}					t_file;

typedef struct		s_param
{
	t_btree			*files;
	char			*flags;
	int				firstls;
	int				firstdir;
	int				count;
	int				dir_count;
	int				namelen;
	int				linklen;
	int				usrlen;
	int				grplen;
	int				sizelen;
	long long		blocks;
}					t_param;

t_file				*new_file(char *str, t_param *param);
char				check_filetype(mode_t mode);
char				*get_perm(mode_t fmode);
char				*check_inputs(int ac, char **av);
int					ls_build_tree(int ac, char **av, t_param *param);
t_param				*new_param(int ac, char **av);
char				*usr_name(uid_t uid);
char				*grp_name(gid_t gid);
void				ls_get_len(t_file *file, t_param *param);

int					bt_cmpname(t_btree *t1, t_btree *t2);
int					bt_cmpname_r(t_btree *t1, t_btree *t2);
int					bt_cmpmtime(t_btree *t1, t_btree *t2);
int					bt_cmpmtime_r(t_btree *t1, t_btree *t2);

int					bt_dircheck(t_btree *node);
t_file				*new_dir_file(char *path, char *name, t_param *param);
t_param				*new_param_dir(char *dir_name, t_param *old);
int					ls_open_dir(char *dir_name, t_param *param);

void				bt_putstr(t_btree *node);
void				ls_btinfix(t_btree *r, t_param *p,
		void (*func)(t_btree*, t_param*));
void				ls_print(t_param *param);
void				print_file(t_btree *node, t_param *param);
void				print_dir(t_btree *node, t_param *param);
void				print_first_dir(t_btree *node, t_param *param);
void				print_all(t_btree *node, t_param *param);
void				print_long(t_file *file, t_param *param);

void				free_ls_tree(t_btree *node);
void				free_ls_param(t_param *param);
void				free_file(t_file *file);

int					ft_ls(t_param *param);

#endif
