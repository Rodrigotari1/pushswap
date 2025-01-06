/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:01:39 by rodrigo           #+#    #+#             */
/*   Updated: 2025/01/06 23:17:11 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_three_elements(t_stacks *data)
{
	int	a;
	int	b;
	int	c;

	if (data->a_size < 2)
		return ;
	if (data->a_size == 2)
	{
		if (data->a[0] > data->a[1])
			swap_elements("sa", data->a, data->a_size);
		return ;
	}
	a = data->a[0];
	b = data->a[1];
	c = data->a[2];
	if (a > b && b < c && c > a)
		swap_elements("sa", data->a, data->a_size);
	else if (a > b && b > c)
	{
		swap_elements("sa", data->a, data->a_size);
		rotate_stack(data->a, data->a_size, "down", "a");
	}
	else if (a > b && b < c && c < a)
		rotate_stack(data->a, data->a_size, "up", "a");
	else if (a < b && b > c && c > a)
	{
		swap_elements("sa", data->a, data->a_size);
		rotate_stack(data->a, data->a_size, "up", "a");
	}
	else if (a < b && b > c && c < a)
		rotate_stack(data->a, data->a_size, "down", "a");
}

void	sort_small_stack(t_stacks *data)
{
	int	min_pos;
	int	i;

	if (data->a_size <= 3)
	{
		sort_three_elements(data);
		return ;
	}
	i = 0;
	while (i < 2)
	{
		min_pos = get_min_position(data->a, data->a_size);
		while (min_pos > 0)
		{
			if (min_pos <= data->a_size / 2)
				rotate_stack(data->a, data->a_size, "up", "a");
			else
				rotate_stack(data->a, data->a_size, "down", "a");
			min_pos = get_min_position(data->a, data->a_size);
		}
		push_element("pb", data);
		i++;
	}
	sort_three_elements(data);
	while (data->b_size > 0)
		push_element("pa", data);
}

static void	push_chunks_to_b(t_stacks *data)
{
	int	chunk;
	int	chunk_size;
	int	i;
	int	pushed;

	if (data->a_size <= 100)
		chunk_size = data->a_size / 4;
	else
		chunk_size = data->a_size / 8;
	chunk = 0;
	while (data->a_size > 0)
	{
		pushed = 0;
		while (pushed < chunk_size && data->a_size > 0)
		{
			i = 0;
			while (i < data->a_size)
			{
				if (data->a[i] >= chunk * chunk_size && 
					data->a[i] < (chunk + 1) * chunk_size)
				{
					if (i <= data->a_size / 2)
						while (i--)
							rotate_stack(data->a, data->a_size, "up", "a");
					else
						while (i++ < data->a_size)
							rotate_stack(data->a, data->a_size, "down", "a");
					push_element("pb", data);
					if (data->b_size > 1 && data->b[0] < data->b[1])
						swap_elements("sb", data->b, data->b_size);
					pushed++;
					break;
				}
				i++;
			}
		}
		chunk++;
	}
}

void	sort_large_stack(t_stacks *data)
{
	int	max_pos;

	push_chunks_to_b(data);
	while (data->b_size > 1)
	{
		max_pos = get_max_position(data->b, data->b_size);
		if (max_pos == 0)
		{
			push_element("pa", data);
			continue;
		}
		if (max_pos <= data->b_size / 2)
			while (max_pos--)
				rotate_stack(data->b, data->b_size, "up", "b");
		else
			while (max_pos++ < data->b_size)
				rotate_stack(data->b, data->b_size, "down", "b");
	}
	if (data->b_size)
		push_element("pa", data);
} 