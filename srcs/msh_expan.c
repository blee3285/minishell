/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_expan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:03:25 by blee              #+#    #+#             */
/*   Updated: 2019/03/26 18:41:02 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*msh_get_value(char *name, t_env *env)
{
	char	*value;
	int		i;

	i = ft_strlen(name);
	while (env && (ft_strncmp(env->str, name, i) != 0))
		env = env->next;
	value = ft_strdup(&(env->str[i + 1]));
	return (value);
}
