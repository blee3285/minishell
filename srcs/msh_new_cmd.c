/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_new_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 17:10:25 by blee              #+#    #+#             */
/*   Updated: 2019/08/28 17:04:22 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char        **cpy_args(char **av)
{
    int     i;
    char    **args;

    i = 0;
    while (av[i])
        i++;
    args = (char**)malloc(sizeof(char*) * i);
    i = 1;
    while (av[i])


}

t_cmds      *msh_new_cmd(char **av)
{
    t_cmds      *cmd;

    cmd = (t_cmds*)malloc(sizeof(t_cmds));
    cmd->cmd_id = msh_cmd_id(av);
    cmd->name = ft_strdup(av[0]);

}
