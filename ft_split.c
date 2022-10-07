/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <vviovi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:41:21 by vviovi            #+#    #+#             */
/*   Updated: 2022/10/07 11:05:59 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countword(char const *s, char c)
{
	size_t	i;
	int		nbword;

	i = 0;
	nbword = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			nbword++;
		i++;
	}
	return (nbword);
}

static int	getlenword(int pos, char const *str, char c)
{
	int	lenword;

	lenword = 0;
	while (str[pos] != c && str[pos])
	{
		pos++;
		lenword++;
	}
	return (lenword);
}

static char	**ft_fill_tab(char **tabstr, char const *s, char const c)
{
	int		i;
	int		j;
	int		lenword;
	char	*word;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			lenword = getlenword(i, s, c);
			word = ft_substr(s, i, lenword);
			if (word == NULL)
				return (NULL);
			word[lenword] = '\0';
			i += lenword;
			tabstr[j] = word;
			j++;
		}
	}
	tabstr[j] = NULL;
	return (tabstr);
}

char	**ft_split(char const *s, char c)
{
	int		nbword;
	char	**tabstr;

	if (!s)
		return (NULL);
	nbword = ft_countword(s, c);
	tabstr = malloc(sizeof(char *) * (nbword + 1));
	if (tabstr == NULL)
		return (NULL);
	tabstr = ft_fill_tab(tabstr, s, c);
	return (tabstr);
}
