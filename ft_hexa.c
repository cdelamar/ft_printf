/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:50:27 by cdelamar          #+#    #+#             */
/*   Updated: 2023/11/09 20:58:37 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_hex(unsigned long num, const char format)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, format);
		ft_put_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
		{
			if (format == 'x')
				ft_putchar(num - 10 + 'a');
			if (format == 'X')
				ft_putchar(num - 10 + 'A');
		}
	}
}

int	ft_print_hex(unsigned long num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(num, format);
	return (ft_hex_len(num));
}

// int ft_indhex(long n)
// {
//     char hexDigits[] = "0123456789abcdef";
//     int count;

//     count = 0;
//     if (n < 16)
//     {
//         count += ft_putchar(hexDigits[n]);
//         return (count);
//     }

//     count += ft_indhex(n / 16);
//     count += ft_indhex(n % 16);
//     return (count);
// }

// int ft_puthex(int n)
// {
//     long num;
//     int count;

//     num = (long)n;
//     count = 0;

//     if (num < 0)
//     {
//         num = -num;
//         count++;
//     }

//     if (num == 0)
//     {
//         count += ft_putchar('0');
//         return (count);
//     }

//     ft_indhex(num);
//     return(count);
// }