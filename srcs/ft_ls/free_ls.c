/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:35:53 by blee              #+#    #+#             */
/*   Updated: 2018/04/18 18:46:41 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_file(t_file *file)
{
	free(file->name);
	free(file->path);
	free(file->perm);
	free(file);
}

void	free_ls_tree(t_btree *node)
{
	t_file	*file;

	file = node->data;
	free(file->name);
	free(file->path);
	free(file->perm);
	free(file);
	free(node);
}

void	free_ls_param(t_param *param)
{
	ft_btsuffix(param->files, free_ls_tree);
	free(param->flags);
	free(param);
}
