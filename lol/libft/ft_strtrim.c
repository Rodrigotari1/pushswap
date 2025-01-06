/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_username <your_email@student.42.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:00:00 by your_username    #+#    #+#             */
/*   Updated: 2024/10/09 12:00:00 by your_username   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	beg;
	size_t	end;

	beg = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[beg] && ft_strchr(set, s1[beg]))
	{
		beg++;
	}
	end = ft_strlen(s1);
	while (end > beg && ft_strchr(set, s1[end - 1]))
	{
		end--;
	}
	return (ft_substr(s1, beg, end - beg));
}
