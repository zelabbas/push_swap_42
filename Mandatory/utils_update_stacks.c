/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_update_stacks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:40:54 by zelabbas          #+#    #+#             */
/*   Updated: 2024/01/09 15:53:11 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push.h"

void	init_nodes(t_stack *a, t_stack *b, bool bolean)
{
	ft_set_postion(a);
	ft_set_postion(b);
	set_target_node(a, b);
	ft_set_price(a, b);
	ft_set_cheapest(b, bolean);
}

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rr(a, b);
	ft_set_postion(*a);
	ft_set_postion(*b);
}

void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rrr(a, b);
	ft_set_postion(*a);
	ft_set_postion(*b);
}

void	finish_rotation(t_stack **x,
						t_stack *cheapest_trg_node, char name_stack)
{
	while (*x != cheapest_trg_node)
	{
		if (name_stack == 'a')
		{
			if (cheapest_trg_node->above_median)
				ra(x);
			else
				rra(x);
		}
		else if (name_stack == 'b')
		{
			if (cheapest_trg_node->above_median)
				rb(x);
			else
				rrb(x);
		}
	}
}

void	move_to_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = find_cheapest(*b);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!cheapest_node->above_median
		&& !cheapest_node->target_node->above_median)
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target_node, 'a');
	pa(a, b);
}
