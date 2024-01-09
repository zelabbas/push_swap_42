/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_to_sort_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:57:14 by zelabbas          #+#    #+#             */
/*   Updated: 2024/01/08 10:20:19 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push.h"

void	set_target_node(t_stack *a, t_stack *b)
{
	int		optimal_match_index;
	t_stack	*target_node;
	t_stack	*tmp;

	while (b)
	{
		optimal_match_index = INT_MAX;
		tmp = a;
		while (tmp)
		{
			if (tmp->data > b->data && tmp->data < optimal_match_index)
			{
				optimal_match_index = tmp->data;
				target_node = tmp;
			}
			tmp = tmp->next;
		}
		if (optimal_match_index == INT_MAX)
			target_node = find_min(a);
		b->target_node = target_node;
		b = b->next;
	}
}

void	ft_set_postion(t_stack *x)
{
	int	i;
	int	medium;

	if (!x)
		return ;
	medium = size_stack(x) / 2;
	i = 0;
	while (x)
	{
		x->index = i;
		if (i <= medium)
			x->above_median = true;
		else
			x->above_median = false;
		i++;
		x = x->next;
	}
}

void	ft_set_price(t_stack *a, t_stack *b)
{
	int	len_stack_a;
	int	len_stack_b;

	len_stack_a = size_stack(a);
	len_stack_b = size_stack(b);
	while (b)
	{
		b->set_price = b->index;
		if (!(b->above_median))
			b->set_price = len_stack_b - (b->index);
		if (b->target_node->above_median)
			b->set_price += b->target_node->index;
		else
			b->set_price += len_stack_a - (b->target_node->index);
		b = b->next;
	}
}

void	ft_set_cheapest(t_stack *b, bool five)
{
	int		min_moves;
	t_stack	*tmp;

	if (!b)
		return ;
	min_moves = INT_MAX;
	while (b)
	{
		if (five && b->set_price <= min_moves)
		{
			min_moves = b->set_price;
			tmp = b;
		}
		else if (b->set_price < min_moves)
		{
			min_moves = b->set_price;
			tmp = b;
		}
		b = b->next;
	}
	tmp->cheapest = true;
}

t_stack	*find_cheapest(t_stack *b)
{
	while (b)
	{
		if (b->cheapest == true)
			return (b);
		b = b->next;
	}
	return (NULL);
}
