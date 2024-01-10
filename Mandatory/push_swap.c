/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:01:49 by zelabbas          #+#    #+#             */
/*   Updated: 2024/01/10 21:45:21 by zelabbas         ###   ########.fr       */
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
		ft_putstr("Error\n");
		exit(-1);
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

void	start_handling(t_stack **a, t_stack **b, int ac, char **argv)
{
	char	*str;
	char	*tmp;
	int		i;

	check_empty_string(argv + 1);
	str = ft_strdup("");
	if (!str)
		ft_error();
	i = 1;
	while (i < ac)
	{
		tmp = str;
		str = ft_strjoin(str, argv[i++]);
		if (!str)
			return (free(tmp), ft_error());
		free(tmp);
	}
	argv = ft_split(str, ' ');
	free(str);
	if (!argv)
		ft_error();
	init_stack_a(a, argv);
	if (!stack_is_sorted(*a))
		sort_stack(a, b, size_stack(*a));
	return (ft_free_arg(argv), ft_free_stack(a, false));
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	start_handling(&stack_a, &stack_b, argc, argv);
	return (0);
}
