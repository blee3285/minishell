/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:36:33 by blee              #+#    #+#             */
/*   Updated: 2019/03/26 16:11:42 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_input(void)
{
	int		ret;
	char	buff;
	char	*temp;
	char	*temp2;
	char	*str;

	str = ft_strnew(1);
	temp = ft_strnew(1);
	ret = 0;
	while ((ret = read(0, &buff, 1)) && buff != '\n')
	{
		temp[0] = buff;
		temp2 = str;
		str = ft_strjoin(temp2, temp);
		free(temp2);
	}
	free(temp);
	return (str);
}
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
		str = get_input();
		av = ft_strsplit(str, ' ');
		ft_printf("Input: |%s|\n", str);
		cmd = msh_input(av);
		if (cmd == -1)
			msh_exec(av, msh->env);
		free(str);
		msh_free_arr(av);
		if (cmd == 6)
			exit(0);
	}
}
