/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:01:31 by blee              #+#    #+#             */
/*   Updated: 2018/03/08 19:31:27 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_get_len(t_file *file, t_param *param)
{
	int	temp;

	temp = ft_strlen(file->name);
	if (temp > param->namelen)
		param->namelen = temp;
	temp = ft_numlen(file->links, 10);
	if (temp > param->linklen)
		param->linklen = temp;
	temp = ft_strlen(file->usr_name);
	if (temp > param->usrlen)
		param->usrlen = temp;
	temp = ft_strlen(file->grp_name);
	if (temp > param->grplen)
		param->grplen = temp;
	temp = ft_numlen(file->size, 10);
	if (temp > param->sizelen)
		param->sizelen = temp;
}
