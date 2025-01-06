/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:02:26 by rodrigo           #+#    #+#             */
/*   Updated: 2025/01/06 22:44:53 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stacks
{
	int		*a;
	int		*b;
	int		a_size;
	int		b_size;
	char	*join_args;
}			t_stacks;

int			count_words(const char *str, char delimiter);
void		rotate_stack(int *stack, int len, char *dir, char *name);
void		swap_elements(char *op, int *stack, int len);
void		push_element(char *op, t_stacks *data);
void		sort_three_elements(t_stacks *data);
void		sort_four_to_five_numbers(t_stacks *data);
void		sort_small_stack(t_stacks *data);
void		radix_sort_stack(t_stacks *data);
void		parse_numbers(t_stacks *data);
void		create_ranks(t_stacks *data);
void		initialize_stacks(int count, char **args, t_stacks *data);
void		cleanup_and_exit(t_stacks *data, char *msg, int error);
void		check_duplicates_and_sort(t_stacks *data, int flag);
int			is_stack_sorted(t_stacks *data);
int			string_to_int(const char *str, t_stacks *data);
int			get_max_number(int *stack, int size);
void		sort_large_stack(t_stacks *data);
int			get_min_position(int *stack, int size);
int			get_max_position(int *stack, int size);
void		rotate_to_position(t_stacks *data, int pos);
int			get_target_pos(t_stacks *data, int num);
void		move_forward(int *array, int count);
void		move_backward(int *array, int count);
int			get_min_value(int *stack, int size);
int			get_max_value(int *stack, int size);

#endif