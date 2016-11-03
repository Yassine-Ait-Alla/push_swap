/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 14:18:16 by yaitalla          #+#    #+#             */
/*   Updated: 2015/04/24 14:57:05 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				is_sort(t_tab *tab)
{
	int			i;
	int			len;

	i = 0;
	len = ft_tablen(tab->sort);
	if (len == 2)
	{
		if (recurcmp(tab->a[0], tab->sort[0]) == 0)
			return (1);
		else
			return (0);
	}
	else
	{
		while (i < len)
		{
			if (recurcmp(tab->a[i], tab->sort[i]) != 0)
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

void			fill_b(t_tab *tab)
{
	int			i;

	i = 0;
	while (recurcmp(tab->a[i], tab->sort[tab->max]) != 0)
		i++;
	if (i == 1)
		action("sa", tab);
	if (i > 1 && i < (tab->len / 2))
	{
		while (recurcmp(tab->a[0], tab->sort[tab->max]) != 0)
			action("ra", tab);
	}
	else if (i)
	{
		while (recurcmp(tab->a[0], tab->sort[tab->max]) != 0)
		{
			action("rra", tab);
			if (is_sort(tab))
				return ;
		}
	}
	tab->max++;
	action("pb", tab);
}

void			push_swap(t_tab *tab)
{
	if (tab->a[1] != NULL)
	{
		if (tab->a[0] && ft_atoi(tab->a[0]) > ft_atoi(tab->a[1]))
			action("sa", tab);
		if (is_sort(tab))
			return ;
	}
	while (tab->a[0])
		fill_b(tab);
	while (tab->max > 0)
	{
		action("pa", tab);
		tab->max--;
	}
	putcolor("GOOD", BOLD_DEFAULT, 1, 1);
	ft_putchar('\n');
}

void			push_swap3(t_tab *tab)
{
	if (ft_atoi(tab->a[0]) > ft_atoi(tab->a[1])
			&& ft_atoi(tab->a[1]) > ft_atoi(tab->a[2]))
	{
		action("ra", tab);
		action("sa", tab);
	}
	else if (ft_atoi(tab->a[0]) > ft_atoi(tab->a[1])
			&& ft_atoi(tab->a[1]) < ft_atoi(tab->a[2]))
	{
		if (ft_atoi(tab->a[0]) > ft_atoi(tab->a[2]))
			action("ra", tab);
		else
			action("sa", tab);
	}
	else if (ft_atoi(tab->a[0]) < ft_atoi(tab->a[1])
			&& ft_atoi(tab->a[0]) > ft_atoi(tab->a[2]))
		action("rra", tab);
	else if (ft_atoi(tab->a[0]) < ft_atoi(tab->a[2])
			&& ft_atoi(tab->a[2]) < ft_atoi(tab->a[1]))
	{
		action("sa", tab);
		action("ra", tab);
	}
}

void			mini_push_swap(t_tab *tab, int tablen)
{
	if (tablen == 2)
	{
		if (ft_atoi(tab->a[0]) > ft_atoi(tab->a[1]))
			action("sa", tab);
	}
	else if (tablen == 3)
		push_swap3(tab);
	else if (tablen == 4)
		push_swap4(tab);
	else if (tablen == 5)
		push_swap5(tab);
}
