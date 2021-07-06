/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:34:42 by sameye            #+#    #+#             */
/*   Updated: 2021/07/06 17:09:58 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_putchar_i(int c)
{
	write(1, &c, 1);
	return(1);
}

int ft_putstr_i(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		i += ft_putchar_i(c);
	}
	return (i);
}

int ft_putnbr_i_util(long nb, int size)
{
	char str[size + 1];
	int i;

	i = 0;
	while (i < size)
	{
		str[size - 1 - i] = nb % 10 + '0';
		i++;
		nb = nb / 10;
	}
	str[i] = '\0';
	ft_putstr_i(str);
	return (size);
}

int ft_putnbr_i(long nb)
{
	int size;
	long copy;
	int isneg;

	isneg = nb < 0;
	if (isneg)
	{
		nb = -nb;
		ft_putchar_i('-');
	}
	size = 0;
	copy = nb;
	while (copy > 0)
	{
		copy = copy / 10;
		size++;
	}
	size = ft_putnbr_i_util(nb, size);
	return (size + isneg);
}

int ft_puthexa_i_util(long nb, int size, int upp)
{
	char str[size + 1];
	int i;
	long modulo;

	i = 0;
	while (i < size)
	{
		modulo = nb % 16;
		if (modulo <= 9)
			str[size - 1 - i] = modulo + '0';
		else if (upp == 0)
			str[size - 1 - i] = modulo + 'a' - 10;
		else if (upp == 1)
			str[size - 1 - i] = modulo + 'A' - 10;
		i++;
		nb = nb / 16;
	}
	str[i] = '\0';
	ft_putstr_i(str);
	return (size);
}

int ft_puthexa_i(long nb, int upp)
{
	int size;
	long copy;

	copy = nb;
	size = 0;
	while (copy > 0)
	{
		copy = copy / 16;
		size++;
	}
	size = ft_puthexa_i_util(nb, size, upp);
	return (size); 
}

int ft_putpointer_i(unsigned long pt)
{
	int count;

	count = 2;
	ft_putstr_i("0x");
	count += ft_puthexa_i(pt, 0);
	return(count);
}

int ft_print_var(t_flags *flags,va_list *args)
{
	int count;

	count = 0;
	if (flags->type == 'c')
		count = ft_putchar_i(va_arg(*args, int));
	if (flags->type == 's')
		count = ft_putstr_i(va_arg(*args, char *));
	if (flags->type == 'p')
		count = ft_putpointer_i(va_arg(*args, unsigned long));
	if (flags->type == 'd')
		count = ft_putnbr_i(va_arg(*args, int));
	if (flags->type == 'i')
		count = ft_putnbr_i(va_arg(*args, int));
	if (flags->type == 'u')
		count = ft_putnbr_i(va_arg(*args, unsigned int));
	if (flags->type == 'x')
		count = ft_puthexa_i(va_arg(*args, unsigned int), 0);
	if (flags->type == 'X')
		count = ft_puthexa_i(va_arg(*args, unsigned int), 1);
	if (flags->type == '%')
		count = ft_putchar_i('%');
	return (count);
}
