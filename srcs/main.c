/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:36:33 by blee              #+#    #+#             */
/*   Updated: 2019/02/12 17:59:51 by blee             ###   ########.fr       */
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

int		main(void)
{
	char		*str;
	extern char	**environ;

	ft_printf(environ[0]);
	while(1)
	{
		ft_putstr("$>");
		str = get_input();
		ft_printf("Input: %s\n", str);
		free(str);
	}
	return (0);
}
