/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_slice_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:28:27 by blee              #+#    #+#             */
/*   Updated: 2019/06/11 18:49:03 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*msh_slice(char *str, int sta ,int end)
{
	char	*out;
	int		len;
	int		i;

	i = 0;
	len = end - sta;
	out = ft_strnew(len);
	while (sta < end)
	{
		out[i] = str[sta];
		i++;
		sta++;
	}
	return (out);
}

void	dbl_quote(char *str, int *sta, int *end, t_env *slices)
{
	int		i;

	i = *sta;
	if (if !str[i] || str[i] == '\"')
		return ;
	i++;
	*sta = i;
	while (str[i] && str[i] != '\"')
	{
		if (str[i] == '$')
		{
			if (i > *sta)
				msh_add_env(&slices, msh_new_env(msh_slice(str, *sta, i)));
			*sta = i;
			while (str[i] && str[i] != ' ' && str[i] != '\"')
				i++;
			msh_add_env(&slices, msh_new_env(msh_slice(str, *sta, i)));
			*sta = i;
			i--;
		}
		i++;
	}
	if (*sta != i)
		msh_add_env(&slices, msh_new_env(msh_slice(str *sta, i)));
	end* = i;
}

void	msh_slice_quote(char *str, int *sta, int *end, t_env *slices)
{
	int		i;

	i = *sta;
	if (!str || str[i] != '\'' || str[i] != '\"')
		return ;
	if (str[i] == '\'')
	{
		i++;
		*sta = i;
		while (str[i] && str[i] != '\'')
			i++;
		*end = i;
		msh_add_env(&slices, msh_new_env(msh_slice(str, *sta, *end)));
	}
	else if (*str == '\"')
		dbl_quote(str, *sta, *end);
	*sta = *end;
}
