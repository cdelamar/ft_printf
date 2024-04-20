/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:50:23 by cdelamar          #+#    #+#             */
/*   Updated: 2023/11/09 22:49:16 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_nbr(unsigned int n)
{
	int		count;
	long	nb;

	count = 0;
	nb = (long)n;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		count++;
	}
	if (n <= 9)
	{
		ft_putchar((n + '0'));
		return (++count);
	}
	count += ft_putnbr(n / 10);
	count += ft_putnbr(n % 10);
	return (count);
}

int	ft_putnbr(int n)
{
	int		count;
	long	nb;

	count = 0;
	nb = (long)n;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		count++;
	}
	if (nb <= 9)
	{
		ft_putchar((nb + '0'));
		return (++count);
	}
	count += ft_putnbr(nb / 10);
	count += ft_putnbr(nb % 10);
	return (count);
}
