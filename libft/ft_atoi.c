/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:35:50 by dmaltsev          #+#    #+#             */
/*   Updated: 2017/11/30 02:27:21 by dmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long int		buff;
	int				sign;
	long int		result;

	while ((ft_isspace(*str)) == 1)
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	result = 0;
	while (ft_isdigit(*str) == 1 && (buff = result) != -1)
	{
		result = (10 * result) + (*str - '0');
		if (result < buff)
			return (sign > 0 ? -1 : 0);
		str++;
	}
	return (result * sign);
}
