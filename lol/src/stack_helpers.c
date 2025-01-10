/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:02:18 by rodrigo           #+#    #+#             */
/*   Updated: 2025/01/09 21:02:24 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_max_position(int *stack, int size)
{
	int	i;
	int	max_pos;
	int	max_value;

	i = 0;
	max_pos = 0;
	max_value = stack[0];
	while (i < size)
	{
		if (stack[i] > max_value)
		{
			max_value = stack[i];
			max_pos = i;
		}
		i++;
	}
	return (max_pos);
}

void	rotate_to_position(t_stacks *data, int pos)
{
	if (pos <= data->a_size / 2)
		while (pos--)
			rotate_stack(data->a, data->a_size, "up", "a");
	else
		while (pos++ < data->a_size)
			rotate_stack(data->a, data->a_size, "down", "a");
}

void	move_forward(int *array, int count)
{
	int	first;
	int	index;

	if (count <= 1)
		return ;
	first = array[0];
	index = 0;
	while (index < count - 1)
	{
		array[index] = array[index + 1];
		index++;
	}
	array[count - 1] = first;
}

void	move_backward(int *array, int count)
{
	int	last;
	int	index;

	if (count <= 1)
		return ;
	last = array[count - 1];
	index = count - 1;
	while (index > 0)
	{
		array[index] = array[index - 1];
		index--;
	}
	array[0] = last;
}
