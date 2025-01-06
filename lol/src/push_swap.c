/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:02:01 by rodrigo           #+#    #+#             */
/*   Updated: 2025/01/06 23:12:42 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

static int	is_valid_number(char *str)
{
	int	i;
	int	len;
	int	has_digit;

	i = 0;
	has_digit = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	len = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '\t')
			return (0);
		if (ft_isdigit(str[i]))
			has_digit = 1;
		len++;
		i++;
	}
	if (len > 10 || !has_digit)
		return (0);
	return (1);
}

void	process_arguments(int count, char **args)
{
	int	i;
	int	j;
	int	found_num;

	i = 1;
	while (i < count)
	{
		j = 0;
		found_num = 0;
		while (args[i][j])
		{
			while (args[i][j] == ' ' || args[i][j] == '\t')
				j++;
			if (args[i][j])
			{
				if (!is_valid_number(args[i] + j))
					cleanup_and_exit(NULL, "Error\n", 1);
				found_num = 1;
				while (args[i][j] && args[i][j] != ' ' && args[i][j] != '\t')
					j++;
			}
		}
		if (!found_num)
			cleanup_and_exit(NULL, "Error\n", 1);
		i++;
	}
}

static void	join_args(char **args, int i, t_stacks *data)
{
	char	*temp;
	char	*result;

	result = ft_strdup("");
	while (args[i])
	{
		temp = ft_strjoin(result, args[i]);
		free(result);
		if (args[i + 1])
		{
			result = ft_strjoin(temp, " ");
			free(temp);
		}
		else
			result = temp;
		i++;
	}
	data->join_args = result;
	if (!data->join_args)
		cleanup_and_exit(data, "Error\n", 1);
}

static void	handle_sorting(t_stacks *data)
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
		sort_large_stack(data);
}

int	main(int argc, char **argv)
{
	t_stacks	*data;

	process_arguments(argc, argv);
	data = malloc(sizeof(t_stacks));
	if (!data)
		return (1);
	initialize_stacks(argc, argv, data);
	join_args(argv, 1, data);
	parse_numbers(data);
	check_duplicates_and_sort(data, 0);
	create_ranks(data);
	handle_sorting(data);
	cleanup_and_exit(data, NULL, 0);
	return (0);
} 