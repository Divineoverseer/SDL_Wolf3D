/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:47:51 by dmaltsev          #+#    #+#             */
/*   Updated: 2017/11/30 02:40:46 by dmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmpcur;
	t_list	*tmpnxt;

	if (!*alst || !del)
		return ;
	tmpcur = *alst;
	while (tmpcur != NULL)
	{
		tmpnxt = tmpcur->next;
		del(tmpcur->content, tmpcur->content_size);
		free(tmpcur);
		tmpcur = tmpnxt;
	}
	*alst = NULL;
}
