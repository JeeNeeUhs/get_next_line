/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nothing <nothing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:53:09 by ahekinci          #+#    #+#             */
/*   Updated: 2024/11/08 00:16:49 by nothing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (!(unsigned char)c)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	const char	*counter;

	if (!s)
		return (0);
	counter = s;
	while (*counter)
		counter++;
	return (counter - s);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (s < d)
		while (n--)
			d[n] = s[n];
	else
		while (n--)
			*d++ = *s++;
	return (dest);
}

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*str;
// 	char	*ptr;

// 	// if (!s1)
// 	// {
// 	// 	s1 = (char *)malloc(1 * sizeof(char));
// 	// 	s1[0] = '\0';
// 	// }
// 	if (!s1)
// 		return (free(s1), s2);
// 	if (!*s2)
// 		return (free(s1),NULL);
// 	str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen (s2)) + 1));
// 	if (!str)
// 		return (NULL);
// 	ptr = str;
// 	while (s1 && *s1)
// 		*str++ = *s1++;
// 	while (s2 && *s2)
// 		*str++ = *s2++;
// 	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
// 	// if (s1)
// 	// 	free(s1);
// 	return (ptr);
// }

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen (s2)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	if (s1)
	{
		ft_memmove(str, s1, ft_strlen(s1));
		i = ft_strlen(s1);
	}
	ft_memmove(str + i, s2, ft_strlen(s2));
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (free(s1), str);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len)
	{
		*(ptr + len - 1) = c;
		len--;
	}
	return (b);
}
