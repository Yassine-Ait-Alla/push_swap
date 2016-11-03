/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 14:18:16 by yaitalla          #+#    #+#             */
/*   Updated: 2015/04/24 14:57:10 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		free_tab(t_tab *tab)
{
	free(tab);
}

int			check_error(int ac, char **av)
{
	if (ac < 2)
		return (1);
	if (is_error(av))
		return (1);
	if (ac == 2)
	{
		on_param();
		return (1);
	}
	return (0);
}

void		push_swap5(t_tab *tab)
{
	if (ft_atoi(tab->a[0]) > ft_atoi(tab->a[1]))
	{
		action("sa", tab);
		if (is_sort(tab))
			return ;
	}
	fill_b(tab);
	fill_b(tab);
	push_swap3(tab);
	action("pa", tab);
	action("pa", tab);
}

void		print_move(char *move)
{
	putcolor(move, BROWN, 1, 0);
	ft_putstr(" ");
}
