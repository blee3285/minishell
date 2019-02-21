/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:05:56 by blee              #+#    #+#             */
/*   Updated: 2018/04/14 16:46:59 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		bt_cmpname(t_btree *t1, t_btree *t2)
{
	t_file *node1;
	t_file *node2;

	node1 = (t_file*)t1->data;
	node2 = (t_file*)t2->data;
	return (ft_strcmp(node1->name, node2->name));
}

int		bt_cmpname_r(t_btree *t1, t_btree *t2)
{
	t_file *node1;
	t_file *node2;

	node1 = (t_file*)t1->data;
	node2 = (t_file*)t2->data;
	return (ft_strcmp(node2->name, node1->name));
}

int		bt_dircheck(t_btree *node)
{
	t_file	*file;

	file = node->data;
	if (file->type == 'd')
		return (1);
	else
		return (0);
}

void	ls_btinfix(t_btree *r, t_param *p, void (*func)(t_btree*, t_param*))
{
	if (r)
	{
		ls_btinfix(r->left, p, func);
		func(r, p);
		ls_btinfix(r->right, p, func);
	}
}
