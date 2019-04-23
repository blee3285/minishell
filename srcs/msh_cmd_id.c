/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cmd_id.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:29:12 by blee              #+#    #+#             */
/*   Updated: 2019/04/22 16:45:23 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	cmds[7][9] = {
	"ls", "cd", "echo", "env", "setenv", "unsetenv", "exit"
};

int		msh_cmd_id(char **av)
{
	int		id;
	int		i;

	i = 0;
	id = -1;
	while (i < 7)
	{
		if (ft_strcmp(av[0], cmds[i]) == 0)
			id = i;
		i++;
	}
	/*
	if (id >= 0)
		ft_printf("Command found: %s\n", cmds[id]);
	else
		ft_printf("Non-cmd found\n");
	*/
	return (id);
}

int		msh_flag_check(char **av)
{
	int		i;

	i = 0;
	while (av[i])
	{
		if (av[i][0] == '-')
			return (1);
		i++;
	}
	return (0);
}
