/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:43:28 by blee              #+#    #+#             */
/*   Updated: 2019/03/18 15:49:51 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**msh_env_arr(t_env *env)
{
	int		i;
	t_env	*temp;
	char	**env_arr;

	i = 0;
	temp = env;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	temp = env;
	env_arr = (char**)malloc(sizeof(char*) * (i + 1));
	ft_bzero(env_arr, sizeof(char*) * (i + 1));
	i = 0;
	while (temp)
	{
		env_arr[i] = ft_strdup(temp->str);
		i++;
		temp = temp->next;
	}
	return (env_arr);
}
