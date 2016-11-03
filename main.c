/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 14:18:16 by yaitalla          #+#    #+#             */
/*   Updated: 2015/04/24 14:57:13 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				disp(char **tab, char *name)
{
	int			i;
	int			len;

	i = 0;
	putcolor("Status\t", YELLOW, 1, 0);
	putcolor(name, BOLD_CYAN, 1, 1);
	len = ft_tablen(tab);
	while (i < len)
	{
		if (tab[i])
		{
			ft_putstr("\t");
			ft_putendl(tab[i]);
		}
		i++;
	}
}

static void			print_result(t_tab *tab)
{
	char		*len;
	char		*moves;

	len = ft_itoa(tab->len);
	moves = ft_itoa(tab->moves);
	putcolor("push_swap [DONE] [", BOLD_RED, 1, 0);
	putcolor(len, BOLD_RED, 1, 0);
	putcolor(" in] | [", BOLD_RED, 1, 0);
	putcolor(moves, BOLD_RED, 1, 0);
	putcolor(" moves].", BOLD_RED, 1, 1);
	free(len);
	free(moves);
}

static void			result(t_tab *tab, int tablen)
{
	ft_putchar('\n');
	if (tablen < 20)
	{
		putcolor("==========\n   Result:\n==========", BOLD_BROWN, 1, 1);
		print_state(tab);
	}
	print_result(tab);
}

static void			check_all(t_tab *tab, char **av)
{
	setup(av, tab);
	if (tab->len > 3 && check_case(tab) == 1)
	{
		brute_force(tab);
		result(tab, tab->len);
		free_tab(tab);
		return ;
	}
	else if (tab->len > 5)
	{
		push_swap(tab);
		result(tab, tab->len);
		free_tab(tab);
		return ;
	}
	else
	{
		mini_push_swap(tab, tab->len);
		result(tab, tab->len);
		free_tab(tab);
		return ;
	}
}

int					main(int ac, char **av)
{
	t_tab		*tab;

	if (ac == 1)
		return (0);
	tab = (t_tab *)malloc(sizeof(t_tab));
	if (check_error(ac, av))
		return (1);
	else
		check_all(tab, av);
	return (0);
}
