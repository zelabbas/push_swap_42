/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:11:56 by zelabbas          #+#    #+#             */
/*   Updated: 2024/01/05 17:05:40 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	check_syntax(const char *str)
{
	int	check;

	if (!str || !*str)
		return (0);
	while (*str && *str == 32)
		str++;
	if (*str == '+' || *str == '-')
		str++;
	check = 0;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		else
			check = 1;
		str++;
	}
	if (!check)
		return (0);
	return (1);
}

int	check_duplicate(t_stack **x, int n)
{
	t_stack	*tmp;

	if (!x)
		return (0);
	tmp = (*x);
	while (tmp)
	{
		if (tmp->data == n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_error(void)
{
	ft_putstr("Error\n");
	exit(-1);
}

void	check_empty_string(char **argv)
{
	int	j;
	int	i;
	int	check;

	i = 0;
	while (argv[i])
	{
		check = 0;
		j = 0;
		if (argv[i][0] == '\0')
			ft_error();
		while (argv[i][j])
		{
			if (argv[i][j] != ' ')
				check = 1;
			if (argv[i][j] == '\t')
				ft_error();
			j++;
		}
		if (!check)
			ft_error();
		i++;
	}
}
