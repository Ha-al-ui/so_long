/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaoui <halaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:20:24 by halaoui           #+#    #+#             */
/*   Updated: 2023/11/17 15:20:24 by halaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../SRC/so_long.h"

char *ft_strjoin(char *s1, char *s2)
{
    if (!s1 && !s2)
        return (NULL);

    size_t len1 = (s1 == NULL) ? 0 : ft_strlen(s1);
    size_t len2 = (s2 == NULL) ? 0 : ft_strlen(s2);

    char *str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
    if (str == NULL)
        return (NULL);

    size_t i = 0;
    while (s1 && s1[i] != '\0')
    {
        str[i] = s1[i];
        i++;
    }

    size_t j = 0;
    while (s2 && s2[j] != '\0')
    {
        str[i + j] = s2[j];
        j++;
    }
    str[i + j] = '\0';
    return (free(s1), str);
}
