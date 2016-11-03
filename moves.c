/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 15:09:34 by yaitalla          #+#    #+#             */
/*   Updated: 2015/04/20 16:41:46 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char				**swap(char **line)
{
	char		*temp;

	temp = line[0];
	line[0] = line[1];
	line[1] = temp;
	return (line);
}

void				push_b(t_tab *tab)
{
	int			i;

	i = 0;
	while (tab->b[i])
		i++;
	while (i)
	{
		tab->b[i] = tab->b[i - 1];
		i--;
	}
	tab->b[0] = ft_strdup(tab->a[0]);
	tab->a = rotate(tab->a);
	i = 0;
	while (tab->a[i])
		i++;
	i--;
	tab->a[i] = NULL;
}

char				**rotate(char **tab)
{
	int			i;
	char		*temp;
	int			len;

	i = 0;
	len = ft_tablen(tab) - 1;
	while (i < len)
	{
		temp = tab[i];
		tab[i] = tab[i + 1];
		tab[i + 1] = temp;
		i++;
	}
	return (tab);
}

char				**rotate_r(char **tab)
{
	int			i;
	char		*tempzero;
	int			len;

	i = 0;
	len = ft_tablen(tab) - 1;
	i = len;
	tempzero = tab[i];
	while (i)
	{
		tab[i] = tab[i - 1];
		i--;
	}
	tab[i] = tempzero;
	return (tab);
}

void				on_param(void)
{
	putcolor("push_swap [DONE] [", BOLD_RED, 1, 0);
	putcolor("1", BOLD_RED, 1, 0);
	putcolor(" in] | [", BOLD_RED, 1, 0);
	putcolor("0", BOLD_RED, 1, 0);
	putcolor(" moves].", BOLD_RED, 1, 1);
}
