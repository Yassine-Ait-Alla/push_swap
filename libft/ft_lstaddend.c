#include "libft.h"

void			ft_lstaddend(t_list **alst, t_list *new)
{
	while ((*alst)->next)
		alst = &((*alst)->next);
	(*alst)->next = new;
}
