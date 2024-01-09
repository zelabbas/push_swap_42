/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:27:18 by zelabbas          #+#    #+#             */
/*   Updated: 2024/01/08 10:19:44 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push.h"

int	stack_is_sorted(t_stack *x)
{
	t_stack	*tmp;

	tmp = x;
	while (tmp && tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	size_stack(t_stack *x)
{
	int		count;
	t_stack	*tmp;

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

void	sort_stack(t_stack **x, t_stack **y, int n)
{
	if (n == 2)
		ft_sort_two_node(x);
	else if (n == 3)
		ft_sort_three(x);
	else if (n == 5)
		ft_five_node(x, y);
	else
		ft_more_node(x, y);
}
