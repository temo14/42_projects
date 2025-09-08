/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:01:17 by tbaindur          #+#    #+#             */
/*   Updated: 2025/09/08 20:37:31 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*data;
	int	length;
}		t_stack;

void	swap_top_two(t_stack *stack);
void	move_top(t_stack *to, t_stack *from);
void	rotate_up(t_stack *stack);
void	rotate_down(t_stack *stack);
void	error(int free_stacks, t_stack *stack_a, t_stack *stack_b);
void	apply_indexes(t_stack *stack_a, t_stack *stack_b);
void	radix_sort(t_stack *stack_a, t_stack *stack_b);
void	sort_two(t_stack *stack_a);
void	sort_three(t_stack *stack_a);
void	sort_small(t_stack *stack_a, t_stack *stack_b);
int		is_sorted(t_stack *stack_a);
void	create_stack(char **string_stack, int size);
void	free_stack(t_stack *stack);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
char	**fill_words(char **result, char const *s, char c);
size_t	count_words(char const *s, char c);
int		parse_num(char *str, t_stack *stack_a, t_stack *stack_b);
void	quick_sort(int *arr, int start, int end);
char	*ft_substr(char const *s, unsigned int start, size_t len);

void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

#endif
