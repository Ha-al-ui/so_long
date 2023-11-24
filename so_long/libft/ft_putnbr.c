/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaoui <halaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 02:27:06 by halaoui           #+#    #+#             */
/*   Updated: 2023/11/22 03:41:05 by halaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../SRC/so_long.h"

void	ft_putnbr(int n)
{
	int	d;
	int	m;

	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	else if (n < 0)
	{
		ft_putchar('-');
		n *= (-1);
		ft_putnbr(n);
	}
	else if (n >= 10)
	{
		m = n % 10;
		d = n / 10;
		n = d;
		ft_putnbr(n);
		ft_putchar(m + '0');
	}
	else if (n >= 0 && n < 10)
		ft_putchar(n + '0');
}
