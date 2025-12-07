/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkhatr <melkhatr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 10:12:54 by melkhatr          #+#    #+#             */
/*   Updated: 2025/07/25 08:05:19 by melkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		sa(stack_a);
	else if (stack_size == 3)
		sort_three(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

void	handle_error(char **param, t_stack **stack_a, int free_stack_flag)
{
	if (param)
		free_param(param);
	if (free_stack_flag && stack_a)
		free_stack(stack_a);
	check_error(NULL, NULL);
}

void	get_numbers(char *av, t_stack **stack_a)
{
	char		**param;
	long int	n;
	int			i;

	param = ft_split(av, ' ');
	if (!param)
		handle_error(NULL, stack_a, 1);
	i = 0;
	while (param[i] != NULL)
	{
		if (!check_input(param[i]))
			handle_error(param, stack_a, 1);
		n = ft_atoi(param[i]);
		if (n > INT_MAX || n < INT_MIN)
			handle_error(param, stack_a, 1);
		stack_add(stack_a, stack_new(n));
		i++;
	}
	free_param(param);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
	int		i;

	i = 1;
	stack_b = NULL;
	stack_a = NULL;
	while (i < ac)
	{
		get_numbers(av[i], &stack_a);
		i++;
	}
	if (is_duplicate(stack_a))
		check_error(&stack_a, NULL);
	stack_size = get_stack_size(stack_a);
	get_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
