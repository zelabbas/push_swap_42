/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:32:06 by zelabbas          #+#    #+#             */
/*   Updated: 2024/01/08 11:29:13 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push.h"

t_stack	*ft_new_node(int data)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	node->data = data;
	return (node);
}

int	ft_add_to_stack(t_stack **list, int data)
{
	t_stack	*new_node;
	t_stack	*tmp;

	if (!list)
		return (0);
	new_node = ft_new_node(data);
	if (!new_node)
		return (0);
	else
	{
		tmp = *list;
		if (!(*list))
		{
			*list = new_node;
		}
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			new_node->prev = tmp;
			tmp->next = new_node;
		}
		return (1);
	}
}

void	ft_last_node(t_stack **x, t_stack **ptr)
{
	t_stack	*tmp;

	if (x && (*x))
	{
		tmp = *x;
		while (tmp->next)
			tmp = tmp->next;
		(*ptr) = tmp;
	}
}
