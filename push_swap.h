/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 14:21:39 by yaitalla          #+#    #+#             */
/*   Updated: 2015/04/24 13:40:17 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "colors.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_tab
{
	int				max;
	int				moves;
	int				len;
	int				mid;
	char			**a;
	char			**b;
	char			**sort;
	int				*sort_int;
}					t_tab;

int					recurcmp(char *s1, char *s2);
void				action(char *move, t_tab *tab);
void				print_move(char *move);
char				**tab_plus1(char **tab, char *plus1);
char				**rotate(char **tab);
char				**rotate_r(char **tab);
void				setup(char **av, t_tab *tab);
void				print_state(t_tab *tab);
char				**swap(char **tab);
void				disp(char **tab, char *name);
void				on_param(void);
int					check_error(int	ac, char **av);
void				push_b(t_tab *tab);
int					is_error(char **arg);
int					is_sort(t_tab *tab);
int					check_case(t_tab *tab);
void				free_tab(t_tab *tab);
void				fill_b(t_tab *tab);
void				brute_force(t_tab *tab);
void				push_swap(t_tab *tab);
void				push_swap3(t_tab *tab);
void				push_swap4(t_tab *tab);
void				push_swap5(t_tab *tab);
void				mini_push_swap(t_tab *tab, int tablen);

#endif
