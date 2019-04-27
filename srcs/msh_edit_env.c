/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_edit_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 18:10:23 by blee              #+#    #+#             */
/*   Updated: 2019/04/26 18:29:20 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		msh_add_env(t_env **dst, t_env *new)
{
	t_env	*env;

	env = *dst;
	if (!env)
	{
		*dst = new;
		return (1);
	}
	while (env->next)
		env = env->next;
	env->next = new;
	return (0);
}

int		msh_del_env(t_env **env, char *name)
{
	t_env	*temp;
	t_env	*prev;
	int		len;

	temp = *env;
	prev = NULL;
	len = ft_strlen(name);
	if (!temp)
		return (1);
	while (temp && (ft_strncmp(temp->str, name, len) != 0))
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp)
	{
		prev->next = temp->next;
		free(temp->str);
		free(temp);
	}
	return (0);
}
