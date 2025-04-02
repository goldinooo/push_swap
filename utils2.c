/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 04:21:57 by retahri           #+#    #+#             */
/*   Updated: 2025/04/02 10:07:41 by retahri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);	
}

int is_digit(int nb)
{
	return (nb >= '0' && nb <= '9');
}

int	ft_array_len(char	**array)
{
	int	len;

	len = 0;
	if (!array)
		return (0);
	while (array[len])
		len++;
	return (len);
}

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	result;
	int					sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - 48;
		i++;
		if (result > 9223372036854775807 && sign == 1)
			return (-1);
		else if (result > 9223372036854775807 && sign == -1)
			return (0);
	}
	return (result * sign);
}

char	*ft_strdup(char *s1)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(ft_strlen(s1) + 1);
	i = 0;
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}