/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 15:12:22 by dmaltsev          #+#    #+#             */
/*   Updated: 2017/12/03 15:14:42 by dmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_revers(char *s, int len)
{
	char	temp;
	int		beg;
	int		end;

	beg = 0;
	end = len - 1;
	while (beg < end)
	{
		temp = *(s + beg);
		*(s + beg) = *(s + end);
		*(s + end) = temp;
		beg++;
		end--;
	}
}
