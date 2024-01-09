/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:18:39 by zelabbas          #+#    #+#             */
/*   Updated: 2024/01/09 13:25:18 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push.h"

void	ft_free_stack(t_stack **stack, bool quit)
{
	t_stack	*tmp;

	if (stack)
	{
		while (*stack)
		{
			tmp = *stack;
			*stack = (*stack)->next;
			free(tmp);
		}
	}
	if (quit)
	{
		ft_error();
		exit(-1);
	}
}

void	ft_free_list(t_command **list)
{
	t_command	*tmp;

	if (list)
	{
		while (*list)
		{
			tmp = *list;
			*list = (*list)->next;
			free(tmp->command);
			free(tmp);
		}
	}
}

void	ft_free_arg(char **argv)
{
	int	i;

	if (argv)
	{
		i = 0;
		while (argv[i])
			free(argv[i++]);
		free(argv);
	}
}

void	init_stack_a(t_stack **a, char **argv)
{
	int		i;
	long	n;

	if (a && argv)
	{
		i = -1;
		if (!argv[0])
			return (ft_free_arg(argv), ft_free_stack(a, true));
		while (argv[++i])
		{
			if (!check_syntax(argv[i]))
				return (ft_free_arg(argv), ft_free_stack(a, true));
			n = ft_atol(argv[i]);
			if (n > INT_MAX || n < INT_MIN)
				return (ft_free_arg(argv), ft_free_stack(a, true));
			if (!check_duplicate(a, n))
				return (ft_free_arg(argv), ft_free_stack(a, true));
			if (!ft_add_to_stack(a, n))
				return (ft_free_arg(argv), ft_free_stack(a, true));
		}
	}
	else
		ft_error();
}
