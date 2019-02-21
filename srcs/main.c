/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:36:33 by blee              #+#    #+#             */
/*   Updated: 2019/02/20 18:51:33 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*new_env(char *str)
{
	t_env	*new;

	new = (t_env*)malloc(sizeof(t_env));
	new->str = ft_strdup(str);
	new->next = NULL;
	return (new);
}

t_env	*init_env(char **environ)
{
	int		i;
	t_env	*env;
	t_env	*out;

	i = 1;
	if (!environ)
		return (NULL);
	env = new_env(environ[0]);
	out = env;
	while (environ[i])
	{
		env->next = new_env(environ[i]);
		env = env->next;
		i++;
	}
	return (out);
}

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

int		main(void)
{
	char		*str;
	extern char	**environ;
	t_env		*env;

	env = init_env(environ);
	while (env)
	{
		ft_printf("%s\n", env->str);
		env = env->next;
	}
	while(1)
	{
		ft_putstr("$>");
		str = get_input();
		ft_printf("Input: %s\n", str);
		temp_ls(str);
		free(str);
	}
	return (0);
}
