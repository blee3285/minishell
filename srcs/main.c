/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:36:33 by blee              #+#    #+#             */
/*   Updated: 2019/04/22 16:45:02 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
void	temp_ls(char *input)
{
	char	**av;
	t_param	*param;
	int		i;

	i = 0;
	av = ft_strsplit(input, ' ');
	while (av[i])
	{
		ft_printf("%s\n", av[i]);
		i++;
	}
	param = new_param(i, av);
	ft_ls(param);
	//free av
}
*/

int		msh_read_cmd(char *str, t_msh *msh)
{
	char	**inputs;
	int		cmd_id;

	cmd_id = -1;
	inputs = ft_strsplit(str, ' ');
	cmd_id = msh_cmd_id(inputs);
	if (cmd_id == -1)
		msh_exec(inputs, msh->env);
	msh_free_arr(inputs);
	if (cmd_id == 6)
		return (1);
	return (0);
}

int		msh_input(char *str, t_msh *msh)
{
	char	**inputs;
	int		i;
	int		cmd;

	i = 0;
	cmd = -1;
	inputs = ft_strsplit(str, ';');
	while (inputs[i])
	{
		if (msh_read_cmd(inputs[i], msh))
		{
			msh_free_arr(inputs);
			return (1);
		}
		i++;
	}
	msh_free_arr(inputs);
	return (0);
}

int		main(void)
{
	char		*str;
	char		**av;
	extern char	**environ;
	int			cmd;
	t_msh		*msh;

	msh = new_msh(environ);
	while(1)
	{
		ft_putstr("$>");
		str = msh_get_input();
		av = msh_strsplit(str);
		//ft_printf("Input: |%s|\n", av[0]);
		cmd = msh_cmd_id(av);
		if (cmd == -1)
			msh_exec(av, msh->env);
		else if (cmd == 2)
			msh_echo(av, msh);
		free(str);
		msh_free_arr(av);
		if (cmd == 6)
			exit(0);
	}
}
