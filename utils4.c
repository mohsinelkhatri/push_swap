/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkhatr <melkhatr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:07:40 by melkhatr          #+#    #+#             */
/*   Updated: 2025/07/21 13:19:02 by melkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	check_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a != NULL && *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b != NULL && *stack_b != NULL)
		free_stack(stack_b);
	free_stack(stack_a);
	write(2, "Error\n", 6);
	exit(1);
}

long int	ft_atoi(const char *nptr)
{
	int		i;
	long	result;
	int		sig;

	i = 0;
	if (!nptr)
		return (0);
	sig = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sig = -sig;
		i++;
	}
	result = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = result * 10 + nptr[i++] - '0';
	return (sig * result);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}
