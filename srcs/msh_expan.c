/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_expan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:58:57 by blee              #+#    #+#             */
/*   Updated: 2019/06/11 17:51:43 by blee             ###   ########.fr       */
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

char	*msh_slice(char *str, int sta, int end)
{
	char	*out;
	int		len;
	int		i;

	i = 0;
	len = end - sta;
	out = ft_strnew(len);
	while(sta < end)
	{
		out[i] = str[sta];
		i++;	
		sta++;
	}
	return(out);
}

void	slice_quote(char *str, int *sta, int *end)
{
	int		i;
	int		quote;

	i = *sta + 1;
	quote = *sta;
	if (quote == '\'')
	{
		while (str[i] && str[i] != '\'')
			i++;
		*end = i;
	}
	else if (quote == '\"')
	{

	}
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
		//iterate till you hit a special char (", ', $, ~)
		//check if / in front of special char, skip if found
		//for ' skip till end quote
		//for " check for $, otherwise skip to end quote
		//if $ found, make a slice of everything before
		//skip to end of special char (either a space if in a double quote, another $, or end of str) and slice again
		//repeat still end of str
		//hanle ~ elsewhere	if (str[ed] == '\'')
		while (find_match(str[ed], "\"\'$") == 0 && str[ed])
			ed++;
		msh_add_env(&slices, msh_new_env(msh_slice(str, st, ed)));
		st = ed;
		if (str[ed] == '\'')

		ed++;
	}
	return (slices);
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
