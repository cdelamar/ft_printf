/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:00:37 by cdelamar          #+#    #+#             */
/*   Updated: 2023/11/09 22:54:32 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	specifier(const char format, va_list args)
{
	int	i;

	i = 0;
	if (format == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (format == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		i += print_address(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		i += ft_unsigned_nbr(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		i += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		i += ft_percent();
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		counter;
	va_list	args;

	va_start(args, format);
	i = 0;
	counter = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			counter += specifier(format[i + 1], args);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			++counter;
		}
		++i;
	}
	return (counter);
}

/// TESTS ///
// int main()
// {
// // // 	char t = '0';
// // // 	printf("TEST %%c ARGS '0':\n");
// // // 	int n = ft_printf("%c", t);
// // // 	printf("\nRETURN VALUE:\n");
// // // 	printf("%d\n", n);
// // int n = -1;
// int res = ft_printf("%x", -1);
// int res2 = printf("%x", -1);
// ft_printf(" %x\n\n", -1);
// printf(" %x\n", -1);
// ft_printf("\n -- %d\n", res);
// printf(" -- %d\n", res2);
// }
// // //     return (0);
// // // }