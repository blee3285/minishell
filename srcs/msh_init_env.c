/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_init_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:34:19 by blee              #+#    #+#             */
/*   Updated: 2019/04/26 18:32:46 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*msh_new_env(char *str)
{
	t_env	*new;

	new = (t_env*)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->str = ft_strdup(str);
	if (!(new->str))
		return (NULL);
	new->next = NULL;
	return (new);
}

t_env	*msh_init_env(char **environ)
{
	int		i;
	t_env	*temp;
	t_env	*env;

	i = 1;
	if (!environ)
		return (NULL);
	temp = msh_new_env(environ[0]);
	if (!temp)
		return (NULL);
	env = temp;
	while (environ[i])
	{
		temp->next = msh_new_env(environ[i]);
		if (!(temp->next))
		{
			msh_free_env(env);
			return (NULL);
		}
		temp = temp->next;
		i++;
	}
	return (env);
}

t_msh	*new_msh(char **environ)
{
	t_msh	*msh;

	msh = (t_msh*)malloc(sizeof(t_msh));
	if (!msh)
		return (NULL);
	msh->env = msh_init_env(environ);
	msh->cmd_id = -1;
	return (msh);
}
