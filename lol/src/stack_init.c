/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:02:18 by rodrigo           #+#    #+#             */
/*   Updated: 2025/01/09 21:26:36 by rodrigo          ###   ########.fr       */
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

void	join_args(char **args, int i, t_stacks *data)
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
