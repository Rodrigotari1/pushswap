/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:02:01 by rodrigo           #+#    #+#             */
/*   Updated: 2025/01/08 21:01:37 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	is_sorted(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	execute_instruction(char *line, t_stacks *data)
{
	if (!ft_strncmp(line, "sa\n", 3))
		swap_elements("sa", data->a, data->a_size);
	else if (!ft_strncmp(line, "sb\n", 3))
		swap_elements("sb", data->b, data->b_size);
	else if (!ft_strncmp(line, "pa\n", 3))
		push_element("pa", data);
	else if (!ft_strncmp(line, "pb\n", 3))
		push_element("pb", data);
	else if (!ft_strncmp(line, "ra\n", 3))
		rotate_stack(data->a, data->a_size, "up", "a");
	else if (!ft_strncmp(line, "rb\n", 3))
		rotate_stack(data->b, data->b_size, "up", "b");
	else if (!ft_strncmp(line, "rra\n", 4))
		rotate_stack(data->a, data->a_size, "down", "a");
	else if (!ft_strncmp(line, "rrb\n", 4))
		rotate_stack(data->b, data->b_size, "down", "b");
	else
		cleanup_and_exit(data, "Error\n", 1);
}

int	main(int argc, char **argv)
{
	t_stacks	*data;
	char		*line;

	if (argc < 2)
		return (0);
	data = malloc(sizeof(t_stacks));
	if (!data)
		return (1);
	initialize_stacks(argc, argv, data);
	join_args(argv, 1, data);
	parse_numbers(data);
	while (get_next_line(0, &line) > 0)
	{
		execute_instruction(line, data);
		free(line);
	}
	if (is_sorted(data->a, data->a_size) && data->b_size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	cleanup_and_exit(data, NULL, 0);
	return (0);
} 