#include <stdio.h>
#include "push.h"

void	ft_free_stack(t_stack **stack, bool quit)
{
	t_stack *tmp;

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
	int i;

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
			return(ft_free_arg(argv), ft_free_stack(a, true));
		while (argv[++i])
		{
			if (!check_syntax(argv[i]))
				return(ft_free_arg(argv), ft_free_stack(a, true));
			n = ft_atol(argv[i]);
			if (n > INT_MAX || n < INT_MIN)
				return(ft_free_arg(argv), ft_free_stack(a,true));
			if (!check_duplicate(a, n))
				return(ft_free_arg(argv), ft_free_stack(a, true));
			if (!ft_add_to_stack(a, n))
				return (ft_free_arg(argv), ft_free_stack(a, true));
		}
	}
	else
		ft_error();
}

void	ft_disply_stack(t_stack *a)
{
	if (!a)
	{
		printf("stack khawi atbi");
	}
	t_stack *tmp = a;
	while (tmp)
	{
		printf("%d-->", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	// t_stack	*stack_tmp;
	char *str;
	int i;
	if (argc == 1)
		return 0;
	stack_a = NULL;
	stack_b = NULL;
	str = "";
	i = 1;
	check_empty_string(argv + 1);
	while (i < argc)
		str = ft_strjoin(str, argv[i++]);
	argv = ft_split(str, ' ');
	init_stack_a(&stack_a, argv);
	if (!stack_is_sorted(stack_a))
		sort_stack(&stack_a, &stack_b, size_stack(stack_a));
	else
		return (ft_free_arg(argv), ft_free_stack(&stack_a, false), 0);
}
