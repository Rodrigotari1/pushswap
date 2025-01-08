/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:01:39 by rodrigo           #+#    #+#             */
/*   Updated: 2025/01/08 20:32:35 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	sort_three_cases(t_stacks *data, int a, int b, int c);
static void	move_min_to_b(t_stacks *data);
void		sort_three_elements(t_stacks *data);
void		sort_small_stack(t_stacks *data);
void		handle_sorting(t_stacks *data);

static void	sort_three_cases(t_stacks *data, int a, int b, int c)
{
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

void	sort_three_elements(t_stacks *data)
{
	if (data->a_size < 2)
		return ;
	if (data->a_size == 2)
	{
		if (data->a[0] > data->a[1])
			swap_elements("sa", data->a, data->a_size);
		return ;
	}
	sort_three_cases(data, data->a[0], data->a[1], data->a[2]);
}

static void	move_min_to_b(t_stacks *data)
{
	int	min_pos;

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
}

void	sort_small_stack(t_stacks *data)
{
	int	i;

	if (data->a_size <= 3)
	{
		sort_three_elements(data);
		return ;
	}
	i = 0;
	while (i++ < 2)
		move_min_to_b(data);
	sort_three_elements(data);
	while (data->b_size > 0)
		push_element("pa", data);
}

void	handle_sorting(t_stacks *data)
{
	if (is_stack_sorted(data))
		cleanup_and_exit(data, NULL, 0);
	else if (data->a_size == 2)
		swap_elements("sa", data->a, data->a_size);
	else if (data->a_size == 3)
		sort_three_elements(data);
	else if (data->a_size <= 5)
		sort_small_stack(data);
	else
		bucket_sort(data);
}
