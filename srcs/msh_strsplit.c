/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_strsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:43:25 by blee              #+#    #+#             */
/*   Updated: 2019/04/17 17:21:06 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//string split that also handles quotation marks and split by spaces/tabs/etc

int		cpy_to_c(char *dst, char *src, int *i, int *st, char c)
{
	int		size;

	size = *i;
	*st = *st + 1;
	while(src[*st] && src[*st] != c)
	{
		dst[*i] = src[*st];
		*st = *st + 1;
		*i = *i + 1;
	}
	return (*i - size);
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
	while (st < end)
	{
		if (str[st] == '\\' && (str[st + 1] == '\"' || str[st + 1] == '\''))
			st++;
		if (str[st] == '\'' || str[st] == '\"')
			cpy_to_c(new, str, &i, &st, str[st]);
		else
		{
			new[i] = str[st];
			i++;
		}
		st++;
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
			i += skip_to_c(&str[i], str[i]);
		i++;
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
	int		substr;
	int		splits;
	char	**out;

	i = 0;
	si = 0;
	substr = 0;
	splits = split_count(str);
	ft_printf("Found %d inputs\n", splits);
	out = (char**)malloc(sizeof(char*) * (splits + 1));
	ft_bzero(out, (sizeof(char*) * (splits + 1)));
	while (i < splits)
	{
		while(str[si] <= ' ')
			si++;
		substr = substr_len(&str[si]);
		ft_printf("Copying length: %d\n", substr);
		out[i] = dup_substr(str, si, substr + si);
		si += substr;
		i++;
	}
	return (out);
}

//still need to handle both types of quotes and to properly skip over them if needed
