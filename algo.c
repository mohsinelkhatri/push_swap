/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkhatr <melkhatr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:53:16 by melkhatr          #+#    #+#             */
/*   Updated: 2025/07/19 13:16:11 by melkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_init(t_stack **stack_a, t_stack **stack_b)
{
	int	total;
	int	push_count;
	int	count;

	total = get_stack_size(*stack_a);
	push_count = 0;
	count = 0;
	while (total > 6 && count < total && push_count < total / 2)
	{
		if ((*stack_a)->index <= total / 2)
		{
			pb(stack_a, stack_b);
			push_count++;
		}
		else
			ra(stack_a);
		count++;
	}
	while (total - push_count > 3)
	{
		pb(stack_a, stack_b);
		push_count++;
	}
}

static void	rotate_to_lowest(t_stack **stack_a)
{
	int	position_of_lowest;
	int	total;

	total = get_stack_size(*stack_a);
	position_of_lowest = position_lowest_index(stack_a);
	if (position_of_lowest > total / 2)
	{
		while (position_of_lowest < total)
		{
			rra(stack_a);
			position_of_lowest++;
		}
	}
	else
	{
		while (position_of_lowest > 0)
		{
			ra(stack_a);
			position_of_lowest--;
		}
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_init(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		cost(stack_a, stack_b);
		cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		rotate_to_lowest(stack_a);
}

static int	find_biggest_index(t_stack *stack)
{
	int	current_max;

	current_max = stack->index;
	while (stack)
	{
		if (stack->index > current_max)
			current_max = stack->index;
		stack = stack->next;
	}
	return (current_max);
}

void	sort_three(t_stack **stack_a)
{
	int	max_index;

	if (is_sorted(*stack_a))
		return ;
	max_index = find_biggest_index(*stack_a);
	if ((*stack_a)->index == max_index)
		ra(stack_a);
	else if ((*stack_a)->next->index == max_index)
		rra(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}
