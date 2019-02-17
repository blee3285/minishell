/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:37:31 by blee              #+#    #+#             */
/*   Updated: 2019/02/16 15:16:53 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"

typedef struct			s_env
{
	char			*str;
	struct s_env	*next;
}						t_env;

typedef struct			s_cmds
{
	char	*name;
	void	*ptr;
}						t_cmds;

#endif
