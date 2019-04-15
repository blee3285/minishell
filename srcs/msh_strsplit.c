/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_strsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:43:25 by blee              #+#    #+#             */
/*   Updated: 2019/04/15 16:29:02 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//string split that also handles quotation marks and split by spaces/tabs/etc

int		cpy_to_char(char **dest, char *src, int st, char c)
{
	char	*temp;
	int		i;

	temp = *dest;
	i = st;
	while(*src || *src != c)
	{
		temp[i] = *src;
		src++;
		i++;
	}
	return (i - st);
}

char	*dup_substr(char *str, int st, int end)
{
	char	*new;
	int		i;
	int		size;
	int		jump;

	size = end - st + 1;
	i = 0;
	jump = 0;
	new = ft_strnew(size);
	while (st <=  end)
	{
		if (str[st] == '\\' && (str[st + 1] == '\"' || str[st + 1] == '\''))
				st++;
		else if (str[st] == '\"' || str[st] == '\'')
		{
			jump = cpy_to_char(&new, &str[st], i, str[st]);
			st += jump;
			i += jump;
		}
		new[i] = str[st];
		st++;
		i++;
	}
	return (new);
}

/*
int		skip_substr(char *str, char type)
{
	int		i;

	i = 0;
	if (type == '\"')
	{
		i++;
		while (str[i] && ((str[i] != '\"') || (str[i] != '\'')))
			i++;
	}
	else if (type == ' ')
	{
		while (str[i] && str[i] <= 32)
			i++;
	}
	return (i);
}
*/

int		skip_to_c(char *str, char c)
{
	int		i;

	i = 1;
	if (c == ' ')
	{
		while (str[i] && str[i] > 32)
			i++;
	}
	else
	{
		while (str[i] && str[i] != c)
			i++;
	}
	return (i);
}

int		substr_len(char *str)
{
	int		i;

	i = 0;
	while (str[i] > 32)
	{
		if (str[i] == '\\' && (str[i + 1] == '\'' || str[i + 1] == '\"'))
			i++;
		else if (str[i] == '\'' || str[i] == '\"')
			i += (skip_to_c(&str[i], str[i]) - 1);
		i++;
	}
	return (i - 1);
}

int		split_count(char *str)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\\')
		{
			if (str[i + 1] == '\"' || str[i + 1] == '\'')
				i += 2;
		}
		else if (str[i] == '\"' || str[i] == '\'')
			i += skip_to_c(&str[i], str[i]);
		if ((str[i] <= 32) && (str[i + 1] > 32))
			count++;
		if (str[i])
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
	ft_printf("Found %d inputs\n", splits);
	out = (char**)malloc(sizeof(char*) * (splits + 1));
	ft_bzero(out, (sizeof(char*) * (splits + 1)));
	while (i < splits)
	{
		while(str[si] <= ' ')
			si++;
		out[i] = dup_substr(str, si, substr_len(&str[si]));
		i++;
	}
	return (out);
}

//still need to handle both types of quotes and to properly skip over them if needed
