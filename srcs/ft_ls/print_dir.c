/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 19:09:02 by blee              #+#    #+#             */
/*   Updated: 2018/04/20 15:01:21 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	indent_dir(t_param *old, t_param *new, t_file *file)
{
	int		file_count;

	file_count = old->count - old->dir_count;
	if (file_count || old->firstdir == 0)
	{
		if (old->flags[0] == 'l')
			ft_printf("\n");
		else
			ft_printf("\n\n");
	}
	if (old->dir_count > 1 || file_count)
		ft_printf("%s:\n", file->path);
	if ((old->flags[0] == 'l') && (old->dir_count > 0))
		ft_printf("total %ld\n", new->blocks);
}

void	print_dir(t_btree *node, t_param *param)
{
	t_file	*file;
	t_param	*new_dir;

	file = node->data;
	new_dir = NULL;
	if (param->flags[1] == 'R')
		if (!ft_strcmp(file->name, ".") || !ft_strcmp(file->name, ".."))
			return ;
	if (file->type == 'd')
	{
		new_dir = new_param_dir(file->path, param);
		indent_dir(param, new_dir, file);
		ft_ls(new_dir);
		param->firstdir = 0;
	}
}

void	print_first_dir(t_btree *node, t_param *param)
{
	t_file	*file;
	t_param	*new_dir;

	file = node->data;
	new_dir = NULL;
	if (file->type == 'd')
	{
		new_dir = new_param_dir(file->path, param);
		indent_dir(param, new_dir, file);
		ft_ls(new_dir);
		param->firstdir = 0;
	}
}
