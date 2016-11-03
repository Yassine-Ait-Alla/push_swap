/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 13:34:01 by yaitalla          #+#    #+#             */
/*   Updated: 2015/04/24 14:57:07 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void				push_a(t_tab *tab)
{
	int			i;

	i = 0;
	if (tab->a && tab->a[i])
	{
		while (tab->a[i])
			i++;
	}
	while (i)
	{
		tab->a[i] = tab->a[i - 1];
		i--;
	}
	tab->a[0] = ft_strdup(tab->b[0]);
	if (ft_tablen(tab->a) == tab->len)
		return ;
	if (tab->b && tab->b[0] && tab->b[1])
	{
		tab->b = rotate(tab->b);
		i = 0;
		while (tab->b[i])
			i++;
		i--;
		tab->b[i] = NULL;
	}
}

static void				double_action(char *move, t_tab *tab)
{
	if (recurcmp(move, "ss") == 0)
	{
		tab->a = swap(tab->a);
		tab->b = swap(tab->b);
	}
	else if (recurcmp(move, "rr") == 0)
	{
		tab->a = rotate(tab->a);
		tab->b = rotate(tab->b);
	}
	else if (recurcmp(move, "rrr") == 0)
	{
		tab->a = rotate_r(tab->a);
		tab->b = rotate_r(tab->b);
	}
}

void					action(char *move, t_tab *tab)
{
	if (recurcmp(move, "rrr") == 0)
		double_action(move, tab);
	else if (recurcmp(move, "rr") == 0)
		double_action(move, tab);
	else if (recurcmp(move, "ss") == 0)
		double_action(move, tab);
	else if (recurcmp(move, "sa") == 0)
		tab->a = swap(tab->a);
	else if (recurcmp(move, "sb") == 0)
		tab->a = swap(tab->b);
	else if (recurcmp(move, "pa") == 0)
		push_a(tab);
	else if (recurcmp(move, "pb") == 0)
		push_b(tab);
	else if (recurcmp(move, "ra") == 0)
		tab->a = rotate(tab->a);
	else if (recurcmp(move, "rb") == 0)
		tab->b = rotate(tab->b);
	else if (recurcmp(move, "rra") == 0)
		tab->a = rotate_r(tab->a);
	else if (recurcmp(move, "rrb") == 0)
		tab->b = rotate_r(tab->b);
	if (tab->len < 45)
		print_move(move);
	tab->moves++;
}

int						recurcmp(char *s1, char *s2)
{
	return ((*s1 == *s2) && *s1 ? recurcmp(s1 + 1, s2 + 1) : *s1 - *s2);
}

void					brute_force(t_tab *tab)
{
	action("rra", tab);
	action("rra", tab);
	action("sa", tab);
	action("ra", tab);
	action("ra", tab);
}
