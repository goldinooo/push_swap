/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:07:15 by retahri           #+#    #+#             */
/*   Updated: 2025/04/02 10:06:04 by retahri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void free_arr(char **arr)
{
	int idx;

	idx = 0;
	while (arr[idx])
		free(arr[idx]);
	free(arr);
	
}
void is_valid(char *str, char **arr)
{
	int idx;
	
	idx = 0;
	if ((str[0] == '-' && str[1] == '\0') || (str[0] == '+' && str[1] == '\0'))
	{
		free_arr(arr);
		error();
	}
	if (!(str[0] == '-' || str[0] == '+' || !is_digit(str[0])))
	{
		free_arr(arr);
		error();	
	}
	while (str[idx])
	{
		if (!is_digit(str[idx]))
		{
			free_arr(arr);
			error();
		}
		idx++;
	}
	ft_atoi(str);
	free_arr(arr);
	exit(0);
}

char **simplify(int *ac, char **av)
{
	int idx;
	char **arr;
	
	idx = 0;
	if (*ac < 2)
		exit(0);
	if (*ac == 2)
	{
		arr = ft_split(av[1], ' ');
		if (!arr)
			(free_arr(arr), exit(1));
		else if (!arr[1])
			is_valid(arr[0], arr);
		*ac = ft_array_len(arr);	
	}
	else
	{
		arr = malloc(sizeof(char *) * (*ac));
		while (++idx < *ac)
			arr[idx - 1] = ft_strdup(av[idx]);
		arr[idx - 1] = NULL;
		(*ac)--;
	}
	return (arr);
}
