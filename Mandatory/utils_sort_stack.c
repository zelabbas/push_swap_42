/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:25:15 by zelabbas          #+#    #+#             */
/*   Updated: 2024/01/08 10:20:16 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push.h"

void	ft_sort_two_node(t_stack **x)
{
	sa(x);
}

void	ft_sort_three(t_stack **x)
{
	int	max;

	find_max(x, &max);
	if ((*x)->data == max)
		ra(x);
	else if ((*x)->next->data == max)
		rra(x);
	if ((*x)->data > (*x)->next->data)
		sa(x);
}

void	ft_five_node(t_stack **a, t_stack **b)
{
	t_stack	*smallest;

	pb(a, b);
	pb(a, b);
	ft_sort_three(a);
	while ((*b))
	{
		init_nodes(*a, *b, true);
		move_to_a(a, b);
	}
	ft_set_postion(*a);
	smallest = find_min(*a);
	if (smallest->above_median)
	{
		while (*a != smallest)
			ra(a);
	}
	else
		while (*a != smallest)
			rra(a);
}

void	ft_start_sort(t_stack **a, t_stack **b)
{
	int		mid;
	int		max;
	int		size;

	find_max(a, &max);
	mid = (find_min(*a)->data + max) / 2;
	size = size_stack(*a);
	while (size-- > 3)
	{
		pb(a, b);
		if ((*b)->data > mid)
			rb(b);
	}
	ft_sort_three(a);
	while ((*b))
	{
		init_nodes(*a, *b, false);
		move_to_a(a, b);
	}
}

void	ft_more_node(t_stack **a, t_stack **b)
{
	t_stack	*smallest;

	ft_start_sort(a, b);
	ft_set_postion(*a);
	smallest = find_min(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a);
	else
		while (*a != smallest)
			rra(a);
}
