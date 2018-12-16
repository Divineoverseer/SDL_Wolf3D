/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:32:37 by dmaltsev          #+#    #+#             */
/*   Updated: 2017/11/26 18:40:43 by dmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*newlst_p;

	if (!lst || !f)
		return (NULL);
	if (!(newlst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	newlst = f(lst);
	newlst_p = newlst;
	while ((lst = lst->next) != NULL)
	{
		if (!(newlst_p->next = (t_list *)malloc(sizeof(t_list))))
		{
			ft_freelst(newlst);
			return (NULL);
		}
		newlst_p->next = f(lst);
		newlst_p = newlst_p->next;
	}
	newlst_p->next = NULL;
	return (newlst);
}
