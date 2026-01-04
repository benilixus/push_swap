/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <oused-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 17:04:33 by oused-da          #+#    #+#             */
/*   Updated: 2026/01/04 12:46:48 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;
	size_t	i;

	if (size && nmemb > SIZE_MAX / size)
		return (NULL);
	i = nmemb * size;
	if (i == 0)
	{
		s = malloc(1);
		if (!s)
			return (NULL);
		return (s);
	}
	s = malloc(i);
	if (!s)
		return (NULL);
	ft_bzero(s, i);
	return (s);
}
