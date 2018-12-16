/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freelst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 18:45:42 by dmaltsev          #+#    #+#             */
/*   Updated: 2017/12/03 18:57:55 by dmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freelst(t_list *lst)
{
	t_list	*tmpcur;
	t_list	*tmpnxt;

	if (!lst)
		return ;
	tmpcur = lst;
	while (tmpcur != NULL)
	{
		tmpnxt = tmpcur->next;
		ft_memdel(&tmpcur->content);
		tmpcur->content_size = 0;
		free(tmpcur);
		tmpcur = tmpnxt;
	}
	lst = NULL;
}
