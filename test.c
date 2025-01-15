/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:02:18 by rodrigo           #+#    #+#             */
/*   Updated: 2025/01/08 19:15:42 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

static void	print_stack(int *stack, int size, char stack_name)
{
	int	i;

	i = 0;
	ft_putchar_fd(stack_name, 1);
	write(1, ": ", 2);
	while (i < size)
	{
		ft_putnbr_fd(stack[i], 1);
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

static void	print_both_stacks(t_stacks *data)
{
	print_stack(data->a, data->a_size, 'A');
	print_stack(data->b, data->b_size, 'B');
	write(1, "\n", 1);
}

void	cleanup_and_exit(t_stacks *data, char *msg, int error)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (data)
	{
		if (data->a)
			free(data->a);
		if (data->b)
			free(data->b);
		if (data->join_args)
			free(data->join_args);
		free(data);
	}
	exit(error);
}

static void	test_sort(int *numbers, int size)
{
	t_stacks	*data;
	int			i;
	int			*sorted;
	int			*original;

	data = malloc(sizeof(t_stacks));
	if (!data)
		return ;
	data->a = malloc(sizeof(int) * size);
	data->b = malloc(sizeof(int) * size);
	sorted = malloc(sizeof(int) * size);
	original = malloc(sizeof(int) * size);
	if (!data->a || !data->b || !sorted || !original)
		cleanup_and_exit(data, "Malloc error\n", 1);
	
	// Save original and create sorted array
	i = -1;
	while (++i < size)
	{
		data->a[i] = numbers[i];
		sorted[i] = numbers[i];
		original[i] = numbers[i];
	}
	data->a_size = size;
	data->b_size = 0;
	data->join_args = NULL;
	
	write(1, "Original numbers:\n", 17);
	print_both_stacks(data);

	// Sort array for reference
	i = -1;
	while (++i < size - 1)
	{
		int j = 0;
		while (j < size - i - 1)
		{
			if (sorted[j] > sorted[j + 1])
			{
				int temp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = temp;
			}
			j++;
		}
	}

	write(1, "Sorted reference: ", 17);
	i = -1;
	while (++i < size)
	{
		ft_putnbr_fd(sorted[i], 1);
		write(1, " ", 1);
	}
	write(1, "\n", 1);

	// Show what ranks should be
	write(1, "Expected ranks:  ", 16);
	i = -1;
	while (++i < size)
	{
		int j = 0;
		int rank = 0;
		while (j < size)
		{
			if (original[i] > sorted[j])
				rank++;
			j++;
		}
		ft_putnbr_fd(rank, 1);
		write(1, " ", 1);
	}
	write(1, "\n", 1);

	// Call create_ranks and show result immediately
	create_ranks(data);
	write(1, "Actual ranks:   ", 15);
	i = -1;
	while (++i < size)
	{
		ft_putnbr_fd(data->a[i], 1);
		write(1, " ", 1);
	}
	write(1, "\n\n", 2);

	write(1, "Stack A after ranking:\n", 22);
	print_both_stacks(data);

	bucket_sort(data);

	write(1, "After sorting:\n", 14);
	print_both_stacks(data);

	free(sorted);
	free(original);
	cleanup_and_exit(data, NULL, 0);
}

int	main(void)
{
	// Test 1: Original numbers
	int test1[] = {7, 2, 9, 4, 5, 1, 8, 3, 6, 0};
	write(1, "\nTest 1 - Original numbers:\n", 28);
	test_sort(test1, 10);

	// Test 2: Numbers different from ranks
	int test2[] = {10, 3, 15, 0, 1};
	write(1, "\nTest 2 - Numbers different from ranks:\n", 39);
	test_sort(test2, 5);

	return (0);
}