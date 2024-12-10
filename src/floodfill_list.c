/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:53:43 by mikus             #+#    #+#             */
/*   Updated: 2024/12/10 18:53:45 by mikus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ff_list	*c3d_lstnew(int y, int x)
{
	t_ff_list	*node;

	node = (t_ff_list *)malloc(sizeof(t_ff_list));
	if (node == NULL)
		return (NULL);
	node->x = x;
	node->y = y;
	node->next = NULL;
	return (node);
}

void	c3d_lstadd_front(t_ff_list **lst, t_ff_list *new)
{
	if (lst)
	{
		new->next = *lst;
		*lst = new;
	}
}

t_ff_list	*c3d_lstlast(t_ff_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	c3d_lstadd_back(t_ff_list **lst, t_ff_list *new)
{
	t_ff_list	*node;

	node = c3d_lstlast(*lst);
	if (node)
		node->next = new;
	else
		c3d_lstadd_front(lst, new);
}
