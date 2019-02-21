/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_att1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 15:22:13 by blee              #+#    #+#             */
/*   Updated: 2018/04/14 16:18:47 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	check_filetype(mode_t mode)
{
	int		i;

	i = mode & S_IFMT;
	if (i == S_IFDIR)
		return ('d');
	else if (i == S_IFCHR)
		return ('c');
	else if (i == S_IFBLK)
		return ('b');
	else if (i == S_IFIFO)
		return ('f');
	else if (i == S_IFLNK)
		return ('l');
	else if (i == S_IFSOCK)
		return ('s');
	else
		return ('-');
}

void	get_perm_usr(char **str, mode_t fmode)
{
	char	*temp;

	temp = *str;
	if (fmode & S_IRUSR)
		temp[0] = 'r';
	else
		temp[0] = '-';
	if (fmode & S_IWUSR)
		temp[1] = 'w';
	else
		temp[1] = '-';
	if (fmode & S_IXUSR)
		temp[2] = 'x';
	else
		temp[2] = '-';
}

void	get_perm_grp(char **str, mode_t fmode)
{
	char	*temp;

	temp = *str;
	if (fmode & S_IRGRP)
		temp[3] = 'r';
	else
		temp[3] = '-';
	if (fmode & S_IWGRP)
		temp[4] = 'w';
	else
		temp[4] = '-';
	if (fmode & S_IXGRP)
		temp[5] = 'x';
	else
		temp[5] = '-';
}

void	get_perm_oth(char **str, mode_t fmode)
{
	char	*temp;

	temp = *str;
	if (fmode & S_IROTH)
		temp[6] = 'r';
	else
		temp[6] = '-';
	if (fmode & S_IWOTH)
		temp[7] = 'w';
	else
		temp[7] = '-';
	if (fmode & S_IXOTH)
		temp[8] = 'x';
	else
		temp[8] = '-';
}

char	*get_perm(mode_t fmode)
{
	char	*new;

	new = ft_strnew(10);
	get_perm_usr(&new, fmode);
	get_perm_grp(&new, fmode);
	get_perm_oth(&new, fmode);
	return (new);
}
