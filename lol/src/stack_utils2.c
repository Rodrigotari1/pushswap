/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:02:18 by rodrigo           #+#    #+#             */
/*   Updated: 2025/01/06 22:28:07 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <limits.h>

int	string_to_int(const char *str, t_stacks *data)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			cleanup_and_exit(data, "Error\n", 1);
		num = num * 10 + (str[i++] - '0');
		if ((num * sign) > INT_MAX || (num * sign) < INT_MIN)
			cleanup_and_exit(data, "Error\n", 1);
	}
	return ((int)(num * sign));
}

int	is_stack_sorted(t_stacks *data)
{
	int	i;

	i = 0;
	while (i < data->a_size - 1)
	{
		if (data->a[i] > data->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	get_max_number(int *stack, int size)
{
	int	i;
	int	max;

	i = 0;
	max = stack[0];
	while (i < size)
	{
		if (stack[i] > max)
			max = stack[i];
		i++;
	}
	return (max);
}

int	get_min_position(int *stack, int size)
{
	int	i;
	int	min_pos;
	int	min_value;

	i = 0;
	min_pos = 0;
	min_value = stack[0];
	while (i < size)
	{
		if (stack[i] < min_value)
		{
			min_value = stack[i];
			min_pos = i;
		}
		i++;
	}
	return (min_pos);
}