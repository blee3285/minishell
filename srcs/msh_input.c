/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:29:12 by blee              #+#    #+#             */
/*   Updated: 2019/02/25 18:40:27 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		cmd_id(char *str)
{
	int		id;
	int		i;

	id = 0;
	i = -1;
	while (str[++i])
		id += str[i];
	if (id == 223)
		return (0);//ls
	else if (id == 199)
		return (1);//cd
	else if (id == 415)
		return (2);//echo
	else if (id == 329)
		return (3);//env
	else if (id == 661)
		return (4);//setenv
	else if (id == 888)
		return (5);//unsetenv
	else if (id == 442)
		return (6);//exit
	return (-1);
}

int		msh_input(char **av)
{
	int		id;

	id = cmd_id(av[0]);
	ft_printf("%d\n", id);
	return (id);
}
