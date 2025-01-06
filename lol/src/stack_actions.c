/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:01:39 by rodrigo           #+#    #+#             */
/*   Updated: 2025/01/06 22:24:15 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	log_action(char *action)
{
	ft_putendl_fd(action, 1);
}

void	swap_elements(char *action, int *stack, int size)
{
	int	first;
	int	second;

	if (size <= 1)
		return ;
	first = stack[0];
	second = stack[1];
	stack[0] = second;
	stack[1] = first;
	log_action(action);
}

void	rotate_stack(int *array, int size, char *direction, char *stack_name)
{
	if (size <= 1)
		return ;
	if (ft_strncmp(direction, "up", 2) == 0)
	{
		move_forward(array, size);
		write(1, "r", 1);
	}
	else if (ft_strncmp(direction, "down", 4) == 0)
	{
		move_backward(array, size);
		write(1, "rr", 2);
	}
	ft_putendl_fd(stack_name, 1);
}

void	push_element(char *action, t_stacks *stacks)
{
	int	value;

	if (!ft_strncmp(action, "pa", 2) && stacks->b_size > 0)
	{
		value = stacks->b[0];
		move_forward(stacks->b, stacks->b_size);
		stacks->b_size--;
		move_backward(stacks->a, stacks->a_size + 1);
		stacks->a[0] = value;
		stacks->a_size++;
		log_action(action);
	}
	else if (!ft_strncmp(action, "pb", 2) && stacks->a_size > 0)
	{
		value = stacks->a[0];
		move_forward(stacks->a, stacks->a_size);
		stacks->a_size--;
		move_backward(stacks->b, stacks->b_size + 1);
		stacks->b[0] = value;
		stacks->b_size++;
		log_action(action);
	}
} 