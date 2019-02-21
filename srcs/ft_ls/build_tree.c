/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:50:27 by blee              #+#    #+#             */
/*   Updated: 2019/02/20 18:53:36 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		(*ls_cmpf(char *flags))(t_btree*, t_btree*)
{
	int	(*cmpf)(t_btree*, t_btree*);

	cmpf = NULL;
	if (flags[3] == 'r')
		if (flags[4] == 't')
			cmpf = &bt_cmpmtime_r;
		else
			cmpf = &bt_cmpname_r;
	else if (flags[4] == 't')
		cmpf = &bt_cmpmtime;
	else
		cmpf = &bt_cmpname;
	return (cmpf);
}

int		ls_btadd(char *name, t_param *param)
{
	t_file	*file;
	int		(*cmpf)(t_btree*, t_btree*);

	cmpf = ls_cmpf(param->flags);
	file = new_file(name, param);
	if (!file)
	{
		ft_printf("ft_ls: %s: No such file or directory\n", name);
		return (0);
	}
	ft_btadd(&(param->files), ft_btnew(file, sizeof(t_file)), *cmpf);
	param->count++;
	if (file->type == 'd')
		param->dir_count++;
	free(file);
	return (1);
}

int		ls_btadd_dir(char *path, char *name, t_param *param)
{
	t_file	*file;
	int		(*cmpf)(t_btree*, t_btree*);

	cmpf = ls_cmpf(param->flags);
	file = new_dir_file(path, name, param);
	ft_btadd(&(param->files), ft_btnew(file, sizeof(t_file)), *cmpf);
	param->count++;
	if (file->type == 'd')
		param->dir_count++;
	free(file);
	return (0);
}

int		ls_build_tree(int ac, char **av, t_param *param)
{
	int			i;
	int			valid;

	i = 0;
	while ((i < ac) && (av[i][0] == '-'))
		i++;
	if (i == ac)
		valid = ls_btadd(".", param);
	else
		while (i < ac)
		{
			valid = ls_btadd(av[i], param);
			i++;
			if (!valid)
				return (0);
		}
	if (!valid)
		return (0);
	return (1);
}

int		ls_open_dir(char *dir_name, t_param *param)
{
	t_file			*file;
	DIR				*dir;
	struct dirent	*sd;
	char			*pre_dir;

	file = NULL;
	pre_dir = ft_strjoin(dir_name, "/");
	if (!(dir = opendir(dir_name)))
		return (0);
	while ((sd = readdir(dir)) != NULL)
	{
		if (sd->d_name[0] != '.' || (param->flags[2] == 'a'))
			ls_btadd_dir(pre_dir, sd->d_name, param);
	}
	closedir(dir);
	free(pre_dir);
	return (1);
}
