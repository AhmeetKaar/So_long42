/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akar <akar@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 20:11:36 by akar              #+#    #+#             */
/*   Updated: 2023/12/25 15:10:31 by akar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	func(const char *str, char sep)
{
	int	i;
	int	arraylen;

	i = 0;
	arraylen = 0;
	while (str[i] && str[i] == sep)
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != sep)
			i++;
		arraylen++;
		while (str[i] && str[i] == sep)
			i++;
	}
	return (arraylen);
}

char	*sub(const char *str, char c, size_t i)
{
	size_t	hide;
	size_t	indekslen;

	hide = i;
	indekslen = 0;
	while (str[hide] != c && str[hide])
	{
		hide++;
		indekslen++;
	}
	return (ft_substr(str, i, indekslen));
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	res_i;
	char	**res;

	i = 0;
	res_i = 0;
	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (func(s, c) + 1));
	if (!res)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			res[res_i] = sub(s, c, i);
			res_i++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	res[res_i] = 0;
	return (res);
}
