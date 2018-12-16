/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 17:09:31 by dmaltsev          #+#    #+#             */
/*   Updated: 2018/05/07 15:04:12 by dmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strndp(char *src, size_t siz)
{
	char		*ret;

	if (!src || !siz)
		return (NULL);
	if (!(ret = (char *)malloc((siz > ft_strlen(src) ?
		(siz = ft_strlen(src)) : (siz += 0)) + 1)))
		return (NULL);
	ft_strncpy(ret, src, siz);
	ret[siz] = '\0';
	return (ret);
}

static char		*ft_strnctdp(char *dst, char *src, size_t siz)
{
	char		*ret;

	if (!src || !siz)
		return (NULL);
	if (!dst)
		return (ft_strndp(src, siz));
	if (!(ret = (char *)malloc(ft_strlen(dst) + (siz > ft_strlen(src) ?
						(siz = ft_strlen(src)) : (siz += 0)) + 1)))
		return (NULL);
	ft_strcpy(ret, dst);
	ft_strncpy(&ret[ft_strlen(dst)], src, siz);
	ret[(int)ft_strlen(dst) + siz] = '\0';
	ft_strdel(&dst);
	return (ret);
}

static char		*ft_redofd(int i, char *src)
{
	char		*ret;

	if (!(ret = ft_strndp(&src[i + 1], ft_strlen(&src[i + 1]))))
		return (NULL);
	ft_strdel(&src);
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*fd_buf[2147483648];
	char		buf[BUFF_SIZE + 1];

	if (fd < 0 || fd > 2147483647 || !line || BUFF_SIZE < 1)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0 &&
		!(buf[ret] = '\0'))
		if (!(fd_buf[fd] = ft_strnctdp(fd_buf[fd], buf, ft_strlen(buf))))
			return (-1);
		else if (ft_strchr(fd_buf[fd], '\n') != 0 && (ret = 0) != 1)
			break ;
	if (fd_buf[fd])
		while (fd_buf[fd][ret] && fd_buf[fd][ret] != '\n')
			ret++;
	if (ret == 0 && (*line = ft_strnew((size_t)0)) &&
		(!fd_buf[fd] || (fd_buf[fd] && !fd_buf[fd][ret])))
		return (0);
	if (ret != 0 && !(*line = ft_strndp(fd_buf[fd], ret)))
		return (-1);
	if (fd_buf[fd][ret] && fd_buf[fd][ret + 1])
		return (!(fd_buf[fd] = ft_redofd(ret, fd_buf[fd])) ? -1 : 1);
	ft_strdel(&fd_buf[fd]);
	return (1);
}
