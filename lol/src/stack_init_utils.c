/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:02:18 by rodrigo           #+#    #+#             */
/*   Updated: 2025/01/08 20:32:43 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	check_duplicates_and_sort(t_stacks *data, int flag)
{
	int	i;
	int	j;

	if (!flag)
	{
		i = 0;
		while (i < data->a_size)
		{
			j = i + 1;
			while (j < data->a_size)
			{
				if (data->a[i] == data->a[j])
					cleanup_and_exit(data, "Error\n", 1);
				j++;
			}
			i++;
		}
	}
	if (is_stack_sorted(data))
		cleanup_and_exit(data, NULL, 0);
}

static void	init_arrays(t_stacks *data, int **sorted, int **ranks)
{
	int	i;

	*sorted = malloc(data->a_size * sizeof(int));
	*ranks = malloc(data->a_size * sizeof(int));
	if (!*sorted || !*ranks)
		cleanup_and_exit(data, "Error\n", 1);
	i = 0;
	while (i < data->a_size)
	{
		(*sorted)[i] = data->a[i];
		i++;
	}
}

static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static void	fill_ranks(t_stacks *data, int *sorted, int *ranks)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->a_size)
	{
		ranks[i] = 0;
		j = 0;
		while (j < data->a_size)
		{
			if (data->a[i] > sorted[j])
				ranks[i]++;
			j++;
		}
		i++;
	}
}

void	create_ranks(t_stacks *data)
{
	int	*sorted;
	int	*ranks;
	int	i;

	init_arrays(data, &sorted, &ranks);
	sort_array(sorted, data->a_size);
	fill_ranks(data, sorted, ranks);
	i = 0;
	while (i < data->a_size)
	{
		data->a[i] = ranks[i];
		i++;
	}
	free(sorted);
	free(ranks);
}
