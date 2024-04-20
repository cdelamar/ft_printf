/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:10:30 by cdelamar          #+#    #+#             */
/*   Updated: 2023/11/09 22:56:41 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_printf(const char *format, ...);
int		ft_unsigned_nbr(unsigned int n);
int		ft_print_hex(unsigned long num, const char format);
void	ft_put_hex(unsigned long num, const char format);
int		ft_hex_len(unsigned long num);
int		ft_percent(void);
int		print_address(void *ptr);

#endif