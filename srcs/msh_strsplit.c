/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_strsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:43:25 by blee              #+#    #+#             */
/*   Updated: 2019/04/08 18:55:36 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//string split that also handles quotation marks and split by spaces/tabs/etc

char	*dup_substr(char *str, int start, int end)
{
	char	*new;
	int		i;
	int		size;

	size = end - start + 1;
	i = 0;
	new = ft_strnew(size);
	while (start <= end)
	{
		if (str[start] == '\"' && start == 0)
			start++;
		else if (str[start] == '\"' && str[start - 1] != '\')
			start++;
		new[i] = str[start];
		start++;
		i++;
	}
	return (new);
}

int		skip_substr(char *str, char type)
{
	int		i;

	i = 0;
	if (type == '\"')
	{
		i++;
		while (str[i] && (str[i] != '\"'))
			i++;
	}
	else if (type == ' ')
	{
		while (str[i] && str[i] <= 32)
			i++;
	}
	else if (type == 'a')
	{
		while (str[i] && str[i] > 32 && str[i] != '\"')
			i++;
		if (str[i] == '\"')
			i--;
	}
	return (i);
}

int		split_count(char *str)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			i += skip_substr(&str[i], '\"');
		if ((str[i] <= 32) && (str[i + 1] > 32))
			count++;
		i++;
	}
	return (count + 1);
}

char	**msh_strsplit(char *str)
{
	int		i;
	int		si;
	int		splits;
	char	**out;

	i = 0;
	si = 0;
	splits = split_count(str);
	out = (char**)malloc(sizeof(char*) * splits + 1);
	ft_bzero(out, (sizeof(char*) * splits + 1));
	while (i < splits)
	{
		si += skip_substr(&str[si], ' ');

		i++;
	}
}

//still need to handle both types of quotes and to properly skip over them if needed
