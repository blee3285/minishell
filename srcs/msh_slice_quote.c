/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_slice_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:28:27 by blee              #+#    #+#             */
/*   Updated: 2019/07/03 18:22:03 by blee             ###   ########.fr       */
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

void	msh_new_slice(char *str, int st, int ed, t_env **sli)
{
	msh_add_env(sli, msh_new_env(msh_slice(str, st, ed)));
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
				msh_new_slice(str, *sta, i, slices);
			*sta = i;
			while (str[i] && str[i] != ' ' && str[i] != '\"')
				i++;
			msh_new_slice(str, *sta, i, slices);
			*sta = i;
			i--;
		}
		i++;
	}
	if (*sta != i)
		msh_new_slice(str, *sta, i, slices);
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
		msh_new_slice(str, *s, *e, sli);
	}
	else if (str[i] == '\"')
		dbl_quote(str, s, e, sli);
	*s = *e;
}

void	msh_slice_ex(char *str, int *s, int *e, t_env **sli)
{
	int		i;

	i = *s;
	if (!str || str[i] != '$')
		return ;
	i++;
	while (str[i] && (str[i] != '\"' || str[i] != '\''))
		i++;
	*e = i;
	msh_new_slice(str, *s, *e, sli);
	*s = *e;
}
