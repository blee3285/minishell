/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:17:19 by blee              #+#    #+#             */
/*   Updated: 2019/02/20 18:45:47 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		flag_id(char c, char *flags)
{
	int		i;

	i = 0;
	while (flags[i])
	{
		if (c == flags[i])
			return (i);
		i++;
	}
	return (-1);
}

int		parse_inputs(char *input, char **flags)
{
	char	*temp;
	int		id;

	id = 0;
	temp = *flags;
	input++;
	while (*input)
	{
		if ((id = flag_id(*input, "lRart")) != -1)
			temp[id] = *input;
		else
		{
			ft_printf("ft_ls: illegal option -- %c\n", *input);
			ft_printf("usage: ls [-Ralrt] [file ...]\n");
			return (0);
		}
		input++;
	}
	return (1);
}

char	*check_inputs(int ac, char **av)
{
	int		i;
	int		valid;
	char	*flags;

	i = 0;
	valid = 0;
	flags = ft_strnew(8);
	ft_memset(flags, '-', 6);
	while ((i < ac) && (av[i][0] == '-'))
	{
		valid = parse_inputs(av[i], &flags);
		if (!valid)
		{
			free(flags);
			return (NULL);
		}
		i++;
	}
	return (flags);
}
