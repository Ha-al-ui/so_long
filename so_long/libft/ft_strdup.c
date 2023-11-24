/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaoui <halaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:20:19 by halaoui           #+#    #+#             */
/*   Updated: 2023/11/17 15:20:19 by halaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../SRC/so_long.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (s == 0)
		return (0);
	else
	{
		while (s1[i] != '\0')
		{
			s[i] = s1[i];
			i++;
		}
	}
	s[i] = '\0';
	return (s);
}
