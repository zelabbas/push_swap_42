/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_oprts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:25:10 by zelabbas          #+#    #+#             */
/*   Updated: 2024/01/09 13:33:03 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push.h"

int	check_oprts(char *opr)
{
	if (!ft_strcmp(opr, "pa\n"))
		return (1);
	else if (!ft_strcmp(opr, "pb\n"))
		return (1);
	else if (!ft_strcmp(opr, "sa\n"))
		return (1);
	else if (!ft_strcmp(opr, "sb\n"))
		return (1);
	else if (!ft_strcmp(opr, "ss\n"))
		return (1);
	else if (!ft_strcmp(opr, "ra\n"))
		return (1);
	else if (!ft_strcmp(opr, "rb\n"))
		return (1);
	else if (!ft_strcmp(opr, "rr\n"))
		return (1);
	else if (!ft_strcmp(opr, "rra\n"))
		return (1);
	else if (!ft_strcmp(opr, "rrb\n"))
		return (1);
	else if (!ft_strcmp(opr, "rrr\n"))
		return (1);
	else
		return (0);
}

void	handl_oprts(char *opr, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(opr, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp(opr, "pb\n"))
		pb(a, b);
	else if (!ft_strcmp(opr, "sa\n"))
		sa(a);
	else if (!ft_strcmp(opr, "sb\n"))
		sb(b);
	else if (!ft_strcmp(opr, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(opr, "ra\n"))
		ra(a);
	else if (!ft_strcmp(opr, "rb\n"))
		rb(b);
	else if (!ft_strcmp(opr, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(opr, "rra\n"))
		rra(a);
	else if (!ft_strcmp(opr, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(opr, "rrr\n"))
		rrr(a, b);
}
