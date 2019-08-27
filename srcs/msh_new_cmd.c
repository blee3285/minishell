/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_new_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 17:10:25 by blee              #+#    #+#             */
/*   Updated: 2019/08/26 18:12:45 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char        *msh_flags(char **av)
{
    char    *flags;
    int     i;

    flags = NULL;
    i = 1;
    while (av[i])
    {
        if (av[i][0] == '-')

        i++;
    }
}

t_cmds      *msh_new_cmd(char **av)
{
    t_cmds      *cmd;

    cmd = (t_cmds*)malloc(sizeof(t_cmds));
    cmd->cmd_id = msh_cmd_id(av);
    cmd->name = ft_strdup(av[0]);
}
