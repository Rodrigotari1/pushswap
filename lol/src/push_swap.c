/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:02:01 by rodrigo           #+#    #+#             */
/*   Updated: 2025/01/13 12:53:35 by rodrigo          ###   ########.fr       */
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
	while (str[i] && str[i] != ' ' && str[i] != '\t')
	{
		if (!ft_isdigit(str[i]))
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

static void	check_arg(char *arg)
{
	int	j;
	int	found_num;

	j = 0;
	found_num = 0;
	while (arg[j])
	{
		while (arg[j] == ' ' || arg[j] == '\t')
			j++;
		if (arg[j])
		{
			if (!is_valid_number(arg + j))
				cleanup_and_exit(NULL, "Error\n", 1);
			found_num = 1;
			while (arg[j] && arg[j] != ' ' && arg[j] != '\t')
				j++;
		}
	}
	if (!found_num)
		cleanup_and_exit(NULL, "Error\n", 1);
}

static void	process_arguments(int count, char **args)
{
	int	i;
	int	word_count;

	i = 1;
	if (count == 2)
	{
		word_count = count_words(args[1], ' ');
		if (word_count == 0)
			cleanup_and_exit(NULL, "Error\n", 1);
		check_arg(args[1]);
	}
	else
	{
		while (i < count)
			check_arg(args[i++]);
	}
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
