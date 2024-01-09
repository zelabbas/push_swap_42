/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:13:37 by zelabbas          #+#    #+#             */
/*   Updated: 2024/01/09 14:47:36 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push.h"

t_stack	*ft_new_node(int data)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	node->data = data;
	return (node);
}

int	ft_add_to_stack(t_stack **list, int data)
{
	t_stack	*new_node;
	t_stack	*tmp;

	if (!list)
		return (0);
	new_node = ft_new_node(data);
	if (!new_node)
		return (0);
	else
	{
		tmp = *list;
		if (!(*list))
			*list = new_node;
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			new_node->prev = tmp;
			tmp->next = new_node;
		}
		return (1);
	}
}

t_command	*ft_new_command(char *line)
{
	t_command	*node;

	node = malloc(sizeof(t_command));
	if (!node)
		return (NULL);
	node->next = NULL;
	node->command = line;
	return (node);
}

int	ft_add_comand_to_back(t_command **list_command, char *line)
{
	t_command	*new_command;
	t_command	*tmp;

	if (!list_command)
		return (0);
	new_command = ft_new_command(line);
	if (!new_command)
		return (0);
	else
	{
		tmp = *list_command;
		if (!*list_command)
			*list_command = new_command;
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new_command;
		}
		return (1);
	}
}

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
