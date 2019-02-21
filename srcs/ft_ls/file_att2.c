/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_att2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:45:51 by blee              #+#    #+#             */
/*   Updated: 2018/02/15 16:51:43 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*usr_name(uid_t uid)
{
	struct passwd	*info;

	info = getpwuid(uid);
	if (!info)
		return (NULL);
	else
		return (info->pw_name);
}

char	*grp_name(gid_t gid)
{
	struct group	*info;

	info = getgrgid(gid);
	if (!info)
		return (NULL);
	else
		return (info->gr_name);
}
