/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_reverse_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:31:57 by zelabbas          #+#    #+#             */
/*   Updated: 2024/01/08 13:03:39 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push.h"

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

void	ft_reverse_stack(t_stack **x)
{
	t_stack	*last;

	if ((*x)->next)
	{
		ft_last_node(x, &last);
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = (*x);
		(*x)->prev = last;
		(*x) = last;
	}
}

void	rra(t_stack **a)
{
	if (a && (*a))
	{
		ft_reverse_stack(a);
	}
}

void	rrb(t_stack **b)
{
	if (b && (*b))
	{
		ft_reverse_stack(b);
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	if ((a && (*a)) || (b && (*b)))
	{
		if (a && (*a))
			ft_reverse_stack(a);
		if (b && (*b))
			ft_reverse_stack(b);
	}
}
