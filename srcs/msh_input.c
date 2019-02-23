/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:29:12 by blee              #+#    #+#             */
/*   Updated: 2019/02/22 18:54:48 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		cmd_id(char *str, int max)
{
	int		id;
	int		i;

	id = 0;
	i = 0;
	while (str[i])
	{
		id += str[i];
		i++;
	}
	if (max == 0)
		return (0);
	return (id % max);
}

int		msh_input(char **av)
{
	int		id;

	id = cmd_id(av[0], 7);
	ft_printf("%d\n", id);
	return (id);
}
