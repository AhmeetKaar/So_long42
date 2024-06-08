/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akar <akar@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 16:58:45 by akar              #+#    #+#             */
/*   Updated: 2023/12/25 16:58:45 by akar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_control(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*str;
	int		lenstr;
	int		first;
	int		last;

	i = 0;
	first = 0;
	last = ft_strlen(s1);
	if (s1 == NULL)
		return (NULL);
	while (ft_control(s1[first], set))
		first++;
	while (last > first && ft_control(s1[last - 1], set))
		last--;
	lenstr = last - first;
	str = malloc(sizeof(char) * (lenstr + 1));
	if (str == NULL)
		return (NULL);
	while (s1[first] && lenstr-- > 0)
		str[i++] = s1[first++];
	str[i] = '\0';
	return (str);
}
