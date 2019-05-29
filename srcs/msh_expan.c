/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_expan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:58:57 by blee              #+#    #+#             */
/*   Updated: 2019/05/28 17:53:28 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	temp = av[id]
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


/*
int		sp_char(char *str, int **quote)
{

}


t_env	*get_expan(char *str)
{
	int		i;
	int		quote[2];
	t_env	**lst;

	i = 0;
	quote[0] = 0;
	quote[1] = 0;
	lst = NULL;
	while (str[i])
	{
		if (str[i] == '\'')

		else if (str[i] == '\"')

		else if (str[i] == )
		i++;
	}
}

int		msh_expan()
{
	int		i;
	char	*new;
	t_env	*lst;

	//make a new string with the expansions expanded and storing it in msh as a linked list
	//scan string for valid $ and ~, store the expanded values in a linked list
	//get the length of str + expansions, and malloc new string, or use a combo of strcpy and strjoin?
	//cpy str with the expansions
	//free the old string and the expansions
	i = 0;
	lst = NULL;
	new = NULL;
	
	while (str[i])
	{
		if (str[i] == '\'')
			//ignore all special char within quotes
		else if (str[i] == '\"')i
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
*/
