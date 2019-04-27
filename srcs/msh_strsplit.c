/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_strsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:43:25 by blee              #+#    #+#             */
/*   Updated: 2019/04/26 14:44:46 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		cpy_to_c(char *dst, char *src, int *i, int *st, char c)
{
	int		size;

	size = *i;
	while(src[*st] && src[*st] != c)
	{
		dst[*i] = src[*st];
		*st = *st + 1;
		*i = *i + 1;
	}
	dst[*i] = src[*st];
	*i = *i + 1;
	return (*i - size);
}

char	*dup_substr(char *str, int st, int end)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_strnew(end - st + 1);
	while (st < end)
	{
		if (str[st] == '\\' && (str[st + 1] == '\"' || str[st + 1] == '\''))
		{
			st++;
			new[i] = str[st];
			i++;
		}
		
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
	out = (char**)malloc(sizeof(char*) * (splits + 1));
	ft_bzero(out, (sizeof(char*) * (splits + 1)));
	while (i < splits)
	{
		while(str[si] <= ' ')
			si++;
		substr = substr_len(&str[si]);
		out[i] = dup_substr(str, si, substr + si);
		si += substr;
		i++;
	}
	return (out);
}
