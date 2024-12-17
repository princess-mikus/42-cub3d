/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:53:43 by mikus             #+#    #+#             */
/*   Updated: 2024/12/17 12:33:08 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_fflst	*c3d_lstnew(int y, int x)
{
	t_fflst	*node;

	node = (t_fflst *)malloc(sizeof(t_fflst));
	if (node == NULL)
		return (NULL);
	node->x = x;
	node->y = y;
	node->next = NULL;
	return (node);
}

void	c3d_lstadd_front(t_fflst **lst, t_fflst *new)
{
	if (lst)
	{
		new->next = *lst;
		*lst = new;
	}
}

t_fflst	*c3d_lstlast(t_fflst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	c3d_lstadd_back(t_fflst **lst, t_fflst *new)
{
	t_fflst	*node;

	node = c3d_lstlast(*lst);
	if (node)
		node->next = new;
	else
		c3d_lstadd_front(lst, new);
}
