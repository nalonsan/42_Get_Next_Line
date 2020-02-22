/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso- <nalonso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 07:21:01 by nalonso-          #+#    #+#             */
/*   Updated: 2020/02/22 12:27:40 by nalonso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		join_read_line(char **line, char **cached)
{
	char	*aux;
	int		len;

	len = 0;
	while(cached[0][len] != '\n' && cached[0][len] != '\0')
			len++;
	if(cached[0][len] == '\n'/*|| cached[0][len] == '\0'*/)
	{
		*line = ft_substr(*cached, 0, len);
		aux = ft_strdup(*cached + len + 1);
		free(*cached);
		*cached = aux;
		/*if (cached[0][0] == '\0')
		{
			free(*cached);
			*cached = NULL;
			//printf("please\n");
		}*/
		return(1);	
	}
	else
	{
		*line = ft_strdup(*cached);
		free(*cached);
		*cached = NULL;
	}
	return(0);
}

int		get_next_line(int fd, char **line)
{
	static char		*cached;
	char			buf[BUF_SIZE +1];
	char			*temp;
	int				ret;

	if(fd < 0 || BUF_SIZE <= 0)
		return (-1);
	while((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if(cached == NULL)
			cached = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(cached, buf);
			free(cached);
			cached = temp;
		}
		if(ft_strchr(cached, '\n'))
			break;
	}
	if(ret < 0)
			return(-1);
	if (ret == 0 && (cached == NULL || cached =='\0'))
	{
		*line = ft_strdup("");
		return(0);
	}
	return join_read_line(line, &cached);
}
