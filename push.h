/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:29:42 by zelabbas          #+#    #+#             */
/*   Updated: 2024/01/06 21:29:43 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

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

int		ft_add_to_stack(t_stack **list, int data);
void	ft_last_node(t_stack **x, t_stack **ptr);
char	**ft_split(char const *str, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	check_empty_string(char **argv);
int		check_syntax(const char *str);
int		check_duplicate(t_stack **x, int n);
int		stack_is_sorted(t_stack *x);
int		size_stack(t_stack *x);
void	sort_stack(t_stack **x, t_stack **y, int size);
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

#endif