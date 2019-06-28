/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_expan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:58:57 by blee              #+#    #+#             */
/*   Updated: 2019/06/27 18:34:11 by blee             ###   ########.fr       */
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
*/

int		check_quote(char *str, int idx)
{
	char	quote;

	if (str[idx] != '\'' || str[idx] != '\"')
		return (0);
	quote = str[idx];
	idx++;
	while (str[idx])
	{
		if (str[idx] == quote)
			return (1);
		idx++;
	}
	return (-1);
}

t_env	*get_slice(char *str, t_msh *msh)
{
	t_env	*slices;
	int		st;
	int		ed;

	st = 0;
	ed = 0;
	while (str[ed])
	{
		while (find_match(str[ed], "\"\'$") == 0 && str[ed])
			ed++;
		if (st < ed)
			msh_new_slice(str, st, ed, &slices);
		st = ed;
		//add functions here to handle quotes or $
		//if quotes, call the slice quote function
		//if $, check if the expansion is found, add exp to slices if found, otherwise add a empty str?
		ed++;
	}
	return (slices);
}

int		msh_expan(char **av, t_msh *msh)
{
	int		i;

	i = 0;
	//check for quote pairs here?
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
