/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 18:31:55 by blee              #+#    #+#             */
/*   Updated: 2019/04/01 18:47:34 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		msh_putstr(char *str, t_msh *msh)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			//look in msh->env for value;
		}
		else if (str[i] == '~')
		{
			//look in msh->env home for value;
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	return (0);
}

int		msh_print_arr(char **av, t_msh *msh)
{
	int		i;

	i = 1;
	if (av[0])
		msh_putstr(av[0], msh);
	while (av[i])
	{
		ft_putchar(' ');
		msh_putstr(av[i]);
		i++;
	}
	ft_putchar('\n');
	return (0);
}

int		msh_echo(char **av, t_msh *msh)
{
	if (!av[0])
	{
		ft_printf("\n");
		return (0);
	}
	msh_print_arr(av, msh);
	return (0);
}
