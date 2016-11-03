/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 22:17:29 by yaitalla          #+#    #+#             */
/*   Updated: 2015/04/24 14:49:11 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			is_number(char **arg)
{
	int			i;
	int			j;

	i = 1;
	if (ft_strcmp(arg[i], "-v") == 0)
		i++;
	while (arg[i])
	{
		j = 0;
		if (arg[i][j] == '-' || arg[i][j] == '+')
			j++;
		while (arg[i][j])
		{
			if (ft_isdigit(arg[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int			is_good(char *arg)
{
	int			i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if ((i == 0 && ft_strlen(arg) > 10) || (i && ft_strlen(arg) > 11))
		return (0);
	else if (!i && ft_strlen(arg) == 10)
	{
		if (ft_strcmp("2147483647", arg) < 0)
			return (0);
	}
	else if (i && ft_strlen(arg) == 11)
	{
		if ((arg[0] == '-' && ft_strcmp("-2147483648", arg) < 0)
				|| (arg[0] == '+' && ft_strcmp("+2147483647", arg) < 0))
			return (0);
	}
	return (1);
}

static int			c_duplicate(char **arg, char **copy)
{
	int			i;
	int			j;

	i = 1;
	if (ft_strcmp(arg[i], "-v") == 0)
		i++;
	if (copy[1] && ft_strcmp(copy[0], copy[1]) == 0)
		return (1);
	while (arg[i])
	{
		j = i;
		while (copy[j])
		{
			if (ft_strcmp(arg[i], copy[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int			is_double(char **arg)
{
	int			i;
	int			j;
	char		**copy;

	copy = (char **)malloc(sizeof(char *) * ft_tablen(arg) + 1);
	i = 1;
	if (ft_strcmp(arg[i], "-v") == 0)
		i++;
	j = 0;
	while (arg[i])
	{
		copy[j] = ft_strdup(arg[i]);
		i++;
		j++;
	}
	copy[j] = NULL;
	if (c_duplicate(arg, copy))
	{
		free(copy);
		return (1);
	}
	free(copy);
	return (0);
}

int					is_error(char **arg)
{
	int			i;

	i = 1;
	if (is_double(arg) || !is_number(arg))
	{
		putcolor("Error", BOLD_RED, 2, 1);
		return (1);
	}
	if (ft_strcmp(arg[i], "-v") == 0)
		i++;
	while (arg[i])
	{
		if (is_good(arg[i]) == 0)
		{
			putcolor("Error", BOLD_RED, 2, 1);
			return (1);
		}
		i++;
	}
	return (0);
}
