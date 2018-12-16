/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 19:51:04 by dmaltsev          #+#    #+#             */
/*   Updated: 2017/11/30 02:26:18 by dmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlnk;

	if (!(newlnk = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	newlnk->next = NULL;
	if (!content)
	{
		newlnk->content = NULL;
		newlnk->content_size = 0;
	}
	else
	{
		if (!(newlnk->content = malloc(content_size)))
		{
			free(newlnk);
			return (NULL);
		}
		newlnk->content = ft_memcpy(newlnk->content, content, content_size);
		newlnk->content_size = content_size;
	}
	return (newlnk);
}
