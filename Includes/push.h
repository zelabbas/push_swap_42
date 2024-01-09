/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:29:42 by zelabbas          #+#    #+#             */
/*   Updated: 2024/01/09 17:53:05 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include "get_next_line.h"

typedef struct s_stack
{
	int				data;
	int				index;
	int				set_price;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_command
{
	char				*command;
	struct s_command	*next;
}	t_command;

int		ft_add_to_stack(t_stack **list, int data);
int		ft_add_comand_to_back(t_command **list_command, char *line);
void	ft_last_node(t_stack **x, t_stack **ptr);
char	**ft_split(char const *str, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	check_empty_string(char **argv);
int		check_syntax(const char *str);
int		check_duplicate(t_stack **x, int n);
int		stack_is_sorted(t_stack *x);
int		size_stack(t_stack *x);
void	sort_stack(t_stack **x, t_stack **y, int size);
void	find_max(t_stack **x, int *n);
t_stack	*find_min(t_stack *x);
t_stack	*find_cheapest(t_stack *b);
void	ft_putstr(const char *str);
long	ft_atol(const char *str);
void	sa(t_stack **a);
void	sb(t_stack **a);
void	ss(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
long	ft_atol(const char *str);
void	ft_error(void);
void	ft_sort_two_node(t_stack **x);
void	ft_sort_three(t_stack **x);
void	ft_five_node(t_stack **a, t_stack **b);
void	ft_more_node(t_stack **a, t_stack **b);
void	init_nodes(t_stack *a, t_stack *b, bool bolean);
void	set_target_node(t_stack *a, t_stack *b);
void	move_to_a(t_stack **a, t_stack **b);
void	ft_set_postion(t_stack *x);
void	ft_set_cheapest(t_stack *b, bool five);
void	ft_set_price(t_stack *a, t_stack *b);
void	init_stack_a(t_stack **a, char **argv);
void	ft_free_arg(char **argv);
int		check_oprts(char *opr);
void	handl_oprts(char *opr, t_stack **a, t_stack **b);
void	ft_free_stack(t_stack **stack, bool quit);
void	ft_free_list(t_command **list);

#endif