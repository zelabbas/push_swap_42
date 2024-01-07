/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:28:17 by zelabbas          #+#    #+#             */
/*   Updated: 2024/01/05 17:16:46 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	ft_swap(t_stack **x)
{
	t_stack	*tmp;

	if (*x && (*x)->next)
	{
		tmp = (*x)->next;
		(*x)->next = tmp->next;
		if (tmp->next)
			tmp->next->prev = *x;
		tmp->next = *x;
		tmp->prev = (*x)->prev;
		(*x)->prev = tmp;
		*x = tmp;
	}
}

void	sa(t_stack **a)
{
	if (a && (*a))
	{
		ft_swap(a);
		write(1, "sa\n", 3);
	}
}

void	sb(t_stack **b)
{
	if (b && (*b))
	{
		ft_swap(b);
		write(1, "sb\n", 3);
	}
}

void	ss(t_stack **a, t_stack **b)
{
	if ((a && *a) || (b && (*b)))
	{
		if ((a && *a))
			ft_swap(a);
		if ((b && *b))
			ft_swap(b);
		write(1, "ss\n", 3);
	}
}
