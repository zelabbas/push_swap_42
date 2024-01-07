/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:26:09 by zelabbas          #+#    #+#             */
/*   Updated: 2024/01/06 21:26:40 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	ft_push(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *b;
	(*b) = tmp->next;
	if (*b)
		(*b)->prev = NULL;
	tmp->next = (*a);
	if ((*a))
		(*a)->prev = tmp;
	tmp->prev = NULL;
	(*a) = tmp;
}

void	pa(t_stack **a, t_stack **b)
{
	if (b && (*b))
	{
		ft_push(a, b);
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack **a, t_stack **b)
{
	if (a && (*a))
	{
		ft_push(b, a);
		write(1, "pb\n", 3);
	}
}
