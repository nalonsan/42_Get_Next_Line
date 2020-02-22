/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso- <nalonso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 07:40:14 by nalonso-          #+#    #+#             */
/*   Updated: 2020/02/21 09:42:51 by nalonso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t n;

	n = 0;
	while (s[n] != '\0')
	{
		n++;
	}
	return (n);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != c)
	{
		if (*s == '\0')
		{
			return (NULL);
		}
		s++;
	}
	return ((char*)s);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*dup;

	len = ft_strlen(s1);
	i = 0;
	dup = (char*)malloc(sizeof(*dup) * (len + 1));
	if (dup == NULL)
		return (NULL);
	while (i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (!(new = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	while (i < len)
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*new;
	int				total_len;
	unsigned int	i;
	unsigned int	y;

	if ((!s1) || (!s2))
		return (0);
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(new = (char *)malloc(sizeof(char) * total_len)))
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		new[i] = s1[i];
		i++;
	}
	y = 0;
	while (i < (ft_strlen(s1) + ft_strlen(s2)))
	{
		new[i] = s2[y];
		i++;
		y++;
	}
	new[i] = '\0';
	return (new);
}

char	ft_putstr(char *s1)
{
	while(s1 != '\0')
	{
		write(1, &s1, 1);
	}
	return(0);
}
