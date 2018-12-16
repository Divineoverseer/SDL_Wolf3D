/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestrarr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 18:23:49 by dmaltsev          #+#    #+#             */
/*   Updated: 2017/12/03 18:35:07 by dmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freestrarr(char **strarr)
{
	int		i;

	if (!strarr)
		return ;
	i = 0;
	while (strarr[i])
	{
		ft_strdel(&strarr[i]);
		i++;
	}
	free(strarr);
	strarr = NULL;
}
