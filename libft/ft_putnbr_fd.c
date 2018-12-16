/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:49:25 by dmaltsev          #+#    #+#             */
/*   Updated: 2017/11/28 15:15:02 by dmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nn;

	nn = n;
	if (nn < 0)
	{
		nn = -nn;
		ft_putchar_fd('-', fd);
	}
	if (nn > 9)
		ft_putnbr_fd((nn / 10), fd);
	ft_putchar_fd(((nn % 10) + '0'), fd);
}
