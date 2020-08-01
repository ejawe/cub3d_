/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:54:04 by dmontgen          #+#    #+#             */
/*   Updated: 2019/11/12 16:42:49 by dmontgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_nbwords(char const *s, char c)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if ((i > 0 && s[i - 1] == c && s[i] != c) || (i == 0 && s[i] != c))
			nb++;
		i++;
	}
	return (nb);
}

static	int		ft_lenwords(char const *s, char c)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] != c)
			len++;
		else
			return (len);
		i++;
	}
	return (len);
}

static	char	**free_newstr(char **newstr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(newstr[i]);
		i++;
	}
	free(newstr);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**newstr;

	i = 0;
	j = 0;
	newstr = NULL;
	if (!s)
		return (NULL);
	if (!(newstr = (char **)malloc(sizeof(char *) * (ft_nbwords(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		if ((s[i - 1] == c && s[i] != c) || (i == 0 && s[i] != c))
		{
			if (!(newstr[j] = ft_substr(s, i, (ft_lenwords(&s[i], c)))))
				return (free_newstr(newstr, j));
			j++;
		}
		i++;
	}
	newstr[j] = NULL;
	return (newstr);
}
