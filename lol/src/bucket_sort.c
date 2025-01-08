/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:01:39 by rodrigo           #+#    #+#             */
/*   Updated: 2025/01/08 20:32:03 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	optimize_and_push_to_b(t_stacks *data, int i)
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
}

static void	process_chunk(t_stacks *data, int chunk, int chunk_size)
{
	int	i;

	i = 0;
	while (i < data->a_size)
	{
		if (data->a[i] >= chunk * chunk_size
			&& data->a[i] < (chunk + 1) * chunk_size)
		{
			optimize_and_push_to_b(data, i);
			break ;
		}
		i++;
	}
}

static void	divide_into_sorted_chunks(t_stacks *data)
{
	int	chunk;
	int	chunk_size;
	int	pushed;

	chunk_size = data->a_size / 4;
	if (data->a_size > 100)
		chunk_size = data->a_size / 8;
	chunk = 0;
	while (data->a_size > 0)
	{
		pushed = 0;
		while (pushed++ < chunk_size && data->a_size > 0)
			process_chunk(data, chunk, chunk_size);
		chunk++;
	}
}

static void	rotate_b_to_max(t_stacks *data, int max_pos)
{
	if (max_pos <= data->b_size / 2)
		while (max_pos--)
			rotate_stack(data->b, data->b_size, "up", "b");
	else
		while (max_pos++ < data->b_size)
			rotate_stack(data->b, data->b_size, "down", "b");
}

void	bucket_sort(t_stacks *data)
{
	int	max_pos;

	divide_into_sorted_chunks(data);
	while (data->b_size > 1)
	{
		max_pos = get_max_position(data->b, data->b_size);
		if (max_pos == 0)
			push_element("pa", data);
		else
			rotate_b_to_max(data, max_pos);
	}
	if (data->b_size)
		push_element("pa", data);
}
