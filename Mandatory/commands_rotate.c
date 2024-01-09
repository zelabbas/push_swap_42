/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:30:17 by zelabbas          #+#    #+#             */
/*   Updated: 2024/01/08 10:19:54 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push.h"

void	ft_rotate(t_stack **x)
{
	t_stack	*tmp;
	t_stack	*last;

	if (((*x)->next))
	{
		ft_last_node(x, &last);
		tmp = (*x)->next;
		(*x)->next = NULL;
		(*x)->prev = last;
		tmp->prev = NULL;
		last->next = (*x);
		(*x) = tmp;
	}
}

void	ra(t_stack **a)
{
	if (a && (*a))
	{
		ft_rotate(a);
		write(1, "ra\n", 3);
	}
}

void	rb(t_stack **b)
{
	if (b && (*b))
	{
		ft_rotate(b);
		write(1, "rb\n", 3);
	}
}

void	rr(t_stack **a, t_stack **b)
{
	if ((a && (*a)) || (b && (*b)))
	{
		if (a && (*a))
			ft_rotate(a);
		if (b && (*b))
			ft_rotate(b);
		write(1, "rr\n", 3);
	}
}
