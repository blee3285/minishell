/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:50:42 by blee              #+#    #+#             */
/*   Updated: 2019/03/18 16:07:13 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	msh_free_env(t_env *env)
{
	t_env	*last;

	last = env;
	while(env)
	{
		free(env->str);
		env = env->next;
		if (last)
			free(last);
		last = env;
	}
}

void	msh_free_arr(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free(i);
		i++;
	}
	free(arr);
}
