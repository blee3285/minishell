/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:37:31 by blee              #+#    #+#             */
/*   Updated: 2019/03/26 16:08:52 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"
# include "ft_ls.h"

typedef struct		s_env
{
	char			*str;
	struct s_env	*next;
}					t_env;

typedef struct		s_cmds
{
	char			*name;
	void			*ptr;
}					t_cmds;

typedef struct		s_msh
{
	t_env			*env;
	int				cmd_id;
}					t_msh;

int					msh_input(char **av);
void				msh_exec(char **av, t_env *env);
char				**msh_env_arr(t_env *env);
t_env				*msh_init_env(char **environ);
t_msh				*new_msh(char **environ);
void				msh_free_env(t_env *env);
void				msh_free_arr(char **arr);

#endif
