/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:02:18 by rodrigo           #+#    #+#             */
/*   Updated: 2025/01/06 22:44:53 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <limits.h>

int	count_words(const char *str, char delimiter)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == delimiter)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != delimiter)
			i++;
	}
	return (count);
}

void	check_duplicates_and_sort(t_stacks *data, int flag)
{
	int	i;
	int	j;

	j = 0;
	if (!flag)
	{
		i = -1;
		while (++i < data->a_size)
		{
			j = i + 1;
			while (j < data->a_size)
			{
				if (data->a[i] == data->a[j])
					cleanup_and_exit(data, "Error\n", 1);
				j++;
			}
		}
	}
	if (is_stack_sorted(data))
		cleanup_and_exit(data, NULL, 0);
}

void	parse_numbers(t_stacks *data)
{
	char	**split;
	int		i;
	int		pos;

	pos = 0;
	split = ft_split(data->join_args, ' ');
	i = 0;
	while (split[i] && split[i][0])
	{
		data->a[pos++] = string_to_int(split[i++], data);
		free(split[i - 1]);
	}
	free(split);
}

void	initialize_stacks(int count, char **args, t_stacks *data)
{
	int	i;
	int	num_count;

	i = 0;
	num_count = 0;
	while (--count)
	{
		if (count_words(args[i + 1], ' '))
			num_count += count_words(args[i + 1], ' ');
		else
			num_count++;
		i++;
	}
	data->a = malloc(num_count * sizeof(int));
	data->b = malloc(num_count * sizeof(int));
	if (!data->a || !data->b)
		cleanup_and_exit(data, "Error\n", 1);
	data->a_size = num_count;
	data->b_size = 0;
}

void	create_ranks(t_stacks *data)
{
	int	*temp;
	int	i;
	int	j;
	int	rank;

	if (!(temp = malloc(data->a_size * sizeof(int))))
		cleanup_and_exit(data, "Error\n", 1);
	i = -1;
	while (++i < data->a_size)
	{
		rank = 0;
		j = -1;
		while (++j < data->a_size)
			if (data->a[i] > data->a[j])
				rank++;
		temp[i] = rank;
	}
	i = data->a_size;
	while (i--)
		data->a[i] = temp[i];
	free(temp);
}

int	get_min_value(int *stack, int size)
{
	int	min;
	int	i;

	min = stack[0];
	i = 1;
	while (i < size)
	{
		if (stack[i] < min)
			min = stack[i];
		i++;
	}
	return (min);
}

int	get_max_value(int *stack, int size)
{
	int	max;
	int	i;

	max = stack[0];
	i = 1;
	while (i < size)
	{
		if (stack[i] > max)
			max = stack[i];
		i++;
	}
	return (max);
}