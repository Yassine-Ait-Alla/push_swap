/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 14:18:16 by yaitalla          #+#    #+#             */
/*   Updated: 2015/04/24 14:49:03 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				check_case(t_tab *tab)
{
	int		i;

	i = 0;
	putcolor("sorting in progress", BOLD_DEFAULT, 1, 1);
	while (recurcmp(tab->a[i], tab->sort[i]) == 0 && i < tab->len - 1)
	{
		i++;
	}
	if (tab->len > 3 && i == tab->len - 2)
		return (1);
	return (0);
}

static void		ps4_2(t_tab *tab, int t, char **temp)
{
	int			i;

	i = 0;
	while (i < 3)
	{
		tab->a[i + 1] = temp[i];
		i++;
	}
	tab->a[0] = ft_itoa(t);
	if (!is_sort(tab))
		action("ra", tab);
}

static void		push_swap4_3(char **temp, t_tab *tab)
{
	if (ft_atoi(temp[0]) > ft_atoi(temp[1])
			&& ft_atoi(temp[1]) > ft_atoi(temp[2]))
	{
		action("ra", tab);
		action("sa", tab);
	}
	else if (ft_atoi(temp[0]) > ft_atoi(temp[1])
			&& ft_atoi(temp[1]) < ft_atoi(temp[2]))
	{
		if (ft_atoi(temp[0]) > ft_atoi(temp[2]))
			action("ra", tab);
		else
			action("sa", tab);
	}
	else if (ft_atoi(temp[0]) < ft_atoi(temp[1])
			&& ft_atoi(temp[0]) > ft_atoi(temp[2]))
		action("rra", tab);
	else if (ft_atoi(temp[0]) < ft_atoi(temp[2])
			&& ft_atoi(temp[2]) < ft_atoi(temp[1]))
	{
		action("sa", tab);
		action("ra", tab);
	}
}

static void		ps4(t_tab *tab)
{
	int			i;
	int			j;
	char		*temp[3];

	i = 0;
	j = 0;
	if (is_sort(tab))
		return ;
	while (recurcmp(tab->a[i], tab->sort[0]) != 0)
		i++;
	if (recurcmp(tab->a[0], tab->sort[0]) && recurcmp(tab->a[3], tab->sort[0])
			&& recurcmp(tab->a[0], tab->sort[3])
			&& recurcmp(tab->a[3], tab->sort[3]))
		action("sa", tab);
	j = ft_atoi(tab->a[0]);
	i = 0;
	while (i < 3)
	{
		temp[i] = tab->a[i + 1];
		i++;
	}
	putcolor("pb ", BROWN, 1, 1);
	push_swap4_3(temp, tab);
	ps4_2(tab, j, temp);
}

void			push_swap4(t_tab *tab)
{
	if (ft_atoi(tab->a[0]) > ft_atoi(tab->sort[1])
			&& ft_atoi(tab->a[1]) > ft_atoi(tab->sort[1]))
	{
		if (ft_atoi(tab->a[0]) > ft_atoi(tab->a[1]))
			action("sa", tab);
		action("ra", tab);
		action("ra", tab);
		if (ft_atoi(tab->a[0]) > ft_atoi(tab->a[1]))
			action("sa", tab);
	}
	else if (ft_atoi(tab->a[0]) < ft_atoi(tab->sort[2])
			&& ft_atoi(tab->a[1]) < ft_atoi(tab->sort[2]))
	{
		if (ft_atoi(tab->a[0]) > ft_atoi(tab->a[1]))
			action("sa", tab);
		if (ft_atoi(tab->a[2]) > ft_atoi(tab->a[3]))
		{
			action("rra", tab);
			action("rra", tab);
			action("sa", tab);
			action("ra", tab);
			action("ra", tab);
		}
	}
	ps4(tab);
}
