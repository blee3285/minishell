/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_get_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:24:26 by blee              #+#    #+#             */
/*   Updated: 2019/03/29 17:48:51 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*resize_str(char *str, int new_size)
{
	char	*new;

	new = ft_strnew(new_size);
	ft_strcpy(new, str);
	free(str);
	return (new);
}

char	*msh_get_input(void)
{
	char	*str;
	int		c;
	int		ret;
	int		i;
	int		size;

	size = 5;
	i = 0;
	ret = 0;
	str = ft_strnew(size);
	while ((ret = read(0, &c, 1)) && c != '\n')
	{
		if (i == (size - 1))
		{
			size = size * 2;
			str = resize_str(str, size);
		}
		str[i] = c;
		i++;
	}
	return (str);
}
