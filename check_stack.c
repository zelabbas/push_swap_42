/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:27:18 by zelabbas          #+#    #+#             */
/*   Updated: 2024/01/07 14:54:25 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	stack_is_sorted(t_stack *x)
{
	t_stack	*tmp;

	tmp = x;
	while (tmp && tmp->next)
	{
		if (tmp->data > tmp->next->data)
		{
			// printf("\n[%d] > [%d]\n", tmp->data , tmp->next->data);
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

int size_stack(t_stack *x)
{
	int count;
	t_stack *tmp;

	tmp = x;
	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

void	find_max(t_stack **x, int *n)
{
	t_stack	*tmp;
	tmp = (*x);
	*n = INT_MIN;
	while (tmp)
	{
		if (*n < tmp->data)
			*n = tmp->data;
		tmp = tmp->next;
	}
}

t_stack	*find_min(t_stack *x)
{
	t_stack	*min_node;
	int		min;

	min = INT_MAX;
	while (x)
	{
		if (min > x->data)
		{
			min = x->data;
			min_node = x;
		}
		x = x->next;
	}
	return (min_node);
}

void	ft_sort_two_node(t_stack **x)
{
	sa(x);
}

void	ft_sort_three(t_stack **x)
{
	int max;
	find_max(x, &max);
	if ((*x)->data == max)
		ra(x);
	else if ((*x)->next->data == max)
		rra(x);
	if ((*x)->data > (*x)->next->data)
			sa(x);
}

void	set_target_node(t_stack *a, t_stack *b)
{
	int		optimal_match_index;
	t_stack	*target_node;
	t_stack *tmp;

	while (b)
	{
		optimal_match_index = INT_MAX;
		tmp = a;
		while (tmp)
		{
			if(tmp->data > b->data && tmp->data < optimal_match_index)
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
	int medium;

	if (!x)
		return;
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
	t_stack *tmp;

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

void	finish_rotation(t_stack **x, t_stack *cheapest_trg_node, char name_stack)
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
	t_stack *cheapest_node;

	cheapest_node = find_cheapest(*b);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!cheapest_node->above_median && !cheapest_node->target_node->above_median)
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target_node, 'a');
	pa(a, b);
}

void	ft_more_node(t_stack **a, t_stack **b)
{
	t_stack *smallest;
	int	size = size_stack(*a);
	while (size-- > 3)
	{
			ft_set_postion(*a);
			ft_set_postion(*b);
			pb(a, b);
	}
	ft_sort_three(a);
	while ((*b))
	{
		init_nodes(*a, *b, false);
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
	{
		while (*a != smallest)
			rra(a);
	}
}

void	ft_five_node(t_stack **a, t_stack **b)
{
	t_stack *smallest;
	
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

void	sort_stack(t_stack **x, t_stack **y, int n)
{
	if (n == 2)
		ft_sort_two_node(x);
	else if ( n == 3)
		ft_sort_three(x);
	else if (n == 5)
		ft_five_node(x, y);
	else
		ft_more_node(x, y);
}
