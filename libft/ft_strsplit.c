/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:08:26 by dmaltsev          #+#    #+#             */
/*   Updated: 2018/05/02 20:19:29 by dmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_split_count(char const *s, char c)
{
	int		i;
	int		d;
	int		wrd;

	i = 0;
	d = 0;
	wrd = 0;
	while (s[i])
		if (s[i++] != c)
		{
			if (d == 0)
			{
				d = 1;
				wrd++;
			}
		}
		else
			d = 0;
	return (wrd);
}

int			ft_split_len(char const *s, char c, int cword)
{
	int		i;
	int		d;
	int		wrd;
	int		len;

	len = 0;
	i = 0;
	d = 0;
	wrd = 0;
	while (s[i])
		if (s[i++] != c)
		{
			if (d == 0)
			{
				d = 1;
				wrd++;
			}
			if (d == 1 && wrd == cword)
				len++;
		}
		else
			d = 0;
	return (len);
}

int			ft_split_start(char const *s, char c, int cword)
{
	int		i;
	int		d;
	int		wrd;
	int		len;

	len = 0;
	i = 0;
	d = 0;
	wrd = 0;
	while (s[i])
		if (s[i++] != c)
		{
			if (d == 0)
			{
				d = 1;
				wrd++;
				if (wrd == cword)
					return (i - 1);
			}
		}
		else
			d = 0;
	return (len);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		start;
	int		wrd;
	int		len;
	int		i;

	if (s == NULL)
		return (NULL);
	wrd = ft_split_count(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (wrd + 1))))
		return (NULL);
	i = 0;
	while (i < wrd)
	{
		start = ft_split_start(s, c, i + 1);
		len = ft_split_len(s, c, i + 1);
		tab[i] = ft_strsub(s, (unsigned int)start, (size_t)len);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
