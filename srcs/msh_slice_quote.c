/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_slice_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:28:27 by blee              #+#    #+#             */
/*   Updated: 2019/06/25 17:34:02 by blee             ###   ########.fr       */
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

void	dbl_quote(char *str, int *sta, int *end, t_env **slices)
{
	int		i;

	i = *sta;
	i++;
	*sta = i;
	while (str[i] && str[i] != '\"')
	{
		if (str[i] == '$')
		{
			if (i > *sta)
				msh_add_env(slices, msh_new_env(msh_slice(str, *sta, i)));
			*sta = i;
			while (str[i] && str[i] != ' ' && str[i] != '\"')
				i++;
			msh_add_env(slices, msh_new_env(msh_slice(str, *sta, i)));
			*sta = i;
			i--;
		}
		i++;
	}
	if (*sta != i)
		msh_add_env(slices, msh_new_env(msh_slice(str, *sta, i)));
	*end = i;
}

void	msh_slice_quote(char *str, int *s, int *e, t_env **sli)
{
	int		i;

	i = *s;
	if (!str || str[i] != '\'')
		if (str[i] != '\"')
			return ;
	if (str[i] == '\'')
	{
		i++;
		*s = i;
		while (str[i] && str[i] != '\'')
			i++;
		*e = i;
		msh_add_env(sli, msh_new_env(msh_slice(str, *s, *e)));
	}
	else if (str[i] == '\"')
		dbl_quote(str, s, e, sli);
	*s = *e;
}
