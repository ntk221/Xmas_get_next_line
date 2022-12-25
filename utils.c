/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:35:12 by kazuki            #+#    #+#             */
/*   Updated: 2022/12/24 18:43:55 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

static int	is_space(const char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static bool	is_digits(const char c)
{
    return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	num;
	int	prev;

	sign = 1;
	num = 0;
	while (*str != '\0' && is_space(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
    if (!is_digits(*str))
		exit(1);
	while (*str >= '0' && *str <= '9')
	{
		prev = num;
		num = num * 10 + sign * (*str++ - '0');
		if (num > prev && sign == -1)
			return (0);
		if (num < prev && sign == 1)
			return (-1);
	}
	return (num);
}
