/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_expan2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 17:41:59 by blee              #+#    #+#             */
/*   Updated: 2019/07/29 18:06:49 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *msh_sub_slice(char *str, t_msh *msh)
{
    int     i;
    int     size;
    char    *value;
    char    *head;
    char    *out;

    i = 0;
    size = 0;
    head = NULL;
    while (str[i] && str[i] != '$')
        i++;
    if (i > 0)
    {
        size += i;
        head = msh_slice(str, 0, i);
    }
    value = msh_get_value(&str[i], msh->env);
    if (head)
    {
        out = ft_strjoin(head, value);
        free(head);
    }
    else
        out = ft_strdup(value);
    free(value);
    return (out);
}
