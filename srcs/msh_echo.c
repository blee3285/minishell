/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 18:31:55 by blee              #+#    #+#             */
/*   Updated: 2019/04/24 14:58:19 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		msh_putstr(char *str, t_msh *msh)
{
	char	*temp;

	while (*str)
	{
		if (*str == '$')
		{
			temp = msh_get_value(str + 1, msh->env);
			ft_printf(temp);
			free(temp);
			while (*str)
				str++;
		}
		else if (*str == '~')
		{
			temp = msh_get_value("HOME", msh->env);
			ft_printf(temp);
			free(temp);
		}
		else
			ft_putchar(*str);
		if (*str)
			str++;
	}

	return (0);
}
/*
char	*get_expan(char *str, t_msh *msh)
{
	char	*out;

	while (*str)
	{
		if (*str == '$')
		{
			out = msh_get_value(str + 1, msh->env);
			return (out);
		}
		else if (*str == '~' && (*(str + 1) == 0 || *(str + 1) == '\'))
		{
			out = msh_get_value("HOME", msh->env);
			return (out);
		}
		str++;
	}
	return (NULL);
}

char	*msh_get_str(char *str, t_msh *msh)
{
	int		i;
	char	*out;
	char	*exp;
	char	*temp;

	out = ft_strnew(sizeof(char) * ft_strlen(str));
	exp = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == '$' || str[i] == '~')
		{
			exp = get_expan(str, msh);
			while (str[i + 1])
				i++;
		}
		else
			out[i] = str[i];
		i++;
	}
	if (exp)
	{
		temp = ft_strjoin(out, exp);
		free(out);
		free(exp);
		return (temp);
	}
	return (out);
}
*/
int		msh_print_arr(char **av, t_msh *msh)
{
	int		i;

	i = 2;
	if (av[1])
		msh_putstr(av[1], msh);
	while (av[i])
	{
		ft_putchar(' ');
		msh_putstr(av[i], msh);
		i++;
	}
	ft_putchar('\n');
	return (0);
}

int		msh_echo(char **av, t_msh *msh)
{
	if (!av[1])
	{
		ft_printf("\n");
		return (0);
	}
	msh_print_arr(av, msh);
	return (0);
}
