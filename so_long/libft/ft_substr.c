/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaoui <halaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:20:31 by halaoui           #+#    #+#             */
/*   Updated: 2023/11/17 15:20:31 by halaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../SRC/so_long.h"

char	*ft_substr(const char *s, unsigned int start, int len)
{
	int				i;
	unsigned int	strl_len;
	char			*p;

	if (!s)
		return (NULL);
	strl_len = ft_strlen(s);
	i = 0;
	if (start > strl_len)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	while (i < len)
	{
		p[i] = s[start];
		start++;
		i++;
	}
	p[i] = '\0';
	return (p);
}
