/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_func2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 19:43:27 by blee              #+#    #+#             */
/*   Updated: 2018/03/22 15:04:41 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		bt_cmpmtime(t_btree *t1, t_btree *t2)
{
	t_file	*n1;
	t_file	*n2;

	n1 = (t_file*)t1->data;
	n2 = (t_file*)t2->data;
	if (n1->mtime.tv_sec == n2->mtime.tv_sec)
		return (n2->mtime.tv_nsec - n1->mtime.tv_nsec);
	else
		return (n2->mtime.tv_sec - n1->mtime.tv_sec);
}

int		bt_cmpmtime_r(t_btree *t1, t_btree *t2)
{
	t_file	*n1;
	t_file	*n2;

	n1 = (t_file*)t1->data;
	n2 = (t_file*)t2->data;
	if (n1->mtime.tv_sec == n2->mtime.tv_sec)
		return (n1->mtime.tv_nsec - n2->mtime.tv_nsec);
	else
		return (n1->mtime.tv_sec - n2->mtime.tv_sec);
}
