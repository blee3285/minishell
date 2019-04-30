/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_expan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:58:57 by blee              #+#    #+#             */
/*   Updated: 2019/04/29 18:18:46 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
char	*strdup_sp(char *str)
{
	int		i;
	char	*out;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	out = ft_strnew(i + 1);
	ft_strncpy(out, str, i);
	return (out);
}

int		sub_home(char *str, t_msh *msh, int a)
{
	char	*temp;

}

int		sub_other(char *str, t_msh *msh, int a)
{
	char	*temp;

}

int		sub_exp(char **av, t_msh *msh, int id)
{
	int		i;
	char	*temp;
	char	*exp;

	i = 0;
	exp = NULL;
	temp = av[i]
	while (temp[i])
	{
		if (temp[i] == '\'')

		else if (temp[i] == '\\')
		
		else if (temp[i] == '~')
		{
			exp = sub_home(temp, msh, i);
		}
		else if (temp[i] == '$')
		{
			exp = sub_other(temp, msh, i);
		}
		i++;
	}
}

int		msh_expan(char **av, t_msh *msh)
{
	int		i;

	i = 0;
	while (av[i])
	{
		sub_exp(av, msh, i);
		i++;
	}
}
*/

int		msh_expan(char *str, t_msh *msh)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			//skip to end of quote
		else if (str[i] == '\"')
			//ignore ~ within quotes
		else if (str[i] == '\')
			//ignore special char after it
		else if (str[i] == '~')
			//add $HOME to exp, not going to check for users
		else if (str[i] == '$')
			//add var to exp if found, otherwise add empty str
		i++;
	}
}