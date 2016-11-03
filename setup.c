/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 14:16:16 by yaitalla          #+#    #+#             */
/*   Updated: 2015/04/20 16:47:57 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		sort_tab(char **tab)
{
	char		*temp;
	int			i;
	int			j;
	int			len;

	i = 1;
	j = 0;
	len = ft_tablen(tab);
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (ft_atoi(tab[j]) > ft_atoi(tab[i]))
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}

static void		setup_int(t_tab *tab)
{
	int			i;

	i = 0;
	tab->sort_int = (int *)malloc(sizeof(int) * tab->len);
	while (i < tab->len)
	{
		tab->sort_int[i] = ft_atoi(tab->sort[i]);
		i++;
	}
}

static void		save_a(char **av, char **tab_a, char **tab_sort, int len)
{
	int			i;
	int			j;

	i = 1;
	j = 0;
	while (i < len)
	{
		tab_a[j] = ft_strdup(av[i]);
		tab_sort[j] = ft_strdup(av[i]);
		j++;
		i++;
	}
	tab_a[j] = 0;
}

void			setup(char **av, t_tab *tab)
{
	int			len;

	len = ft_tablen(av);
	tab->a = (char **)malloc(sizeof(char *) * len);
	tab->b = (char **)malloc(sizeof(char *) * len);
	tab->sort = (char **)malloc(sizeof(char *) * len);
	save_a(av, tab->a, tab->sort, len);
	if (len > 3)
		sort_tab(tab->sort);
	else
	{
		if (ft_atoi(tab->a[0]) > ft_atoi(tab->a[1]))
			tab->sort = swap(tab->sort);
	}
	tab->max = 0;
	tab->moves = 0;
	tab->len = len - 1;
	tab->mid = len == 3 ? 1 : (ft_tablen(tab->sort) - 1) / 2;
	if (len > 3)
		setup_int(tab);
}

void			print_state(t_tab *tab)
{
	disp(tab->a, "A");
	ft_putchar('\n');
	putcolor("Status\t", YELLOW, 1, 0);
	putcolor("B", BOLD_CYAN, 1, 1);
	ft_putstr("     ");
	ft_putendl("empty");
}
