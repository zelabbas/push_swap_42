/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_reverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:31:57 by zelabbas          #+#    #+#             */
/*   Updated: 2024/01/08 10:19:51 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push.h"

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
		write(1, "rra\n", 4);
	}
}

void	rrb(t_stack **b)
{
	if (b && (*b))
	{
		ft_reverse_stack(b);
		write(1, "rrb\n", 4);
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
		write(1, "rrr\n", 4);
	}
}
