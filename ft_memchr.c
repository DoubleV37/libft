/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <vviovi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:49:13 by vviovi            #+#    #+#             */
/*   Updated: 2022/09/30 15:58:15 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	schar;
	size_t			i;

	i = 0;
	schar = (unsigned char) c;
	str = (unsigned char *) s;
	while (i < n)
	{
		if (str[i] == schar)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
