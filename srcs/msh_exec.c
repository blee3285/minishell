/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 16:45:18 by blee              #+#    #+#             */
/*   Updated: 2019/03/18 17:39:46 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	msh_exec(char **av, t_env *env)
{
	pid_t	pid;
	char	**env_arr;

	if (access(av[0], X_OK) != 0)
	{
		ft_printf("Permission Denied\n");
		return ;
	}
	env_arr = msh_env_arr(env);
	pid = fork();
	if (pid == 0)
	{
		execve(av[0], av, env_arr);
	}
	wait(&pid);
}
