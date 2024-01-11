/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:46:41 by zelabbas          #+#    #+#             */
/*   Updated: 2024/01/11 10:17:25 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push.h"

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

void	start_commands(t_command *list_comnds, t_stack **a, t_stack **b)
{
	while (list_comnds->command)
	{
		handl_oprts(list_comnds->command, a, b);
		list_comnds = list_comnds->next;
	}
}

void	get_commnds(char **argv, t_stack **a, t_stack **b)
{
	t_command	*list_commands;
	char		*line;

	init_stack_a(a, argv);
	ft_free_arg(argv);
	line = "";
	list_commands = NULL;
	while (line)
	{
		line = get_next_line(0);
		if (!check_oprts(line))
			return (free(line), ft_free_list(&list_commands)
				, ft_free_stack(a, true));
		if (!ft_add_comand_to_back(&list_commands, line))
			return (free(line), ft_free_list(&list_commands)
				, ft_free_stack(a, true));
	}
	start_commands(list_commands, a, b);
	ft_free_list(&list_commands);
}

void	start_handling(t_stack **a, t_stack **b, int ac, char **argv)
{
	char	*str;
	int		i;
	char	*tmp;

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
		{
			free(tmp);
			ft_error();
		}
		free(tmp);
	}
	argv = ft_split(str, ' ');
	free(str);
	if (!argv)
		ft_error();
	get_commnds(argv, a, b);
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
	if (stack_is_sorted(stack_a) && size_stack(stack_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_stack(&stack_a, false);
	ft_free_stack(&stack_b, false);
	return (0);
}
