/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:34:42 by sameye            #+#    #+#             */
/*   Updated: 2021/07/16 17:34:07 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void ft_putchar_i(int c, t_flags *flags)
{
	if (flags->inputmute == 0 && flags->remaining != 0)
	{
		write(1, &c, 1);
		(flags->remaining)--;
		(flags->count)++;
	}
	if (flags->inputmute == 1)
		(flags->count)++;
}

void ft_putstr_i(char *str, t_flags *flags)
{
	int		i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr_i("(null)", flags);
		return;
	}
	while (str[i] != '\0')
	{
		ft_putchar_i(str[i], flags);
		i++;
	}
	return;
}

void ft_putnbr_i_util(long nb, int size, t_flags *flags)
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
	ft_putstr_i(str, flags);
}

void ft_putnbr_i(long nb, t_flags *flags)
{
	int size;
	long copy;
	int isneg;

	if (nb == 0 && flags->precision_given == 1 && flags->precision == 0 && (flags->type == 'i' || flags->type == 'd' || flags->type == 'u'))
		return;
	if (nb == 0)
	{
		ft_putchar_i('0', flags);
		return;
	}
	isneg = nb < 0;
	if (isneg)
	{
		nb = -nb;
		flags->resnegative = 1;
	}
	size = 0;
	copy = nb;
	while (copy > 0)
	{
		copy = copy / 10;
		size++;
	}
	ft_putnbr_i_util(nb, size, flags);
}

void ft_puthexa_i_util(long nb, int size, int upp, t_flags *flags)
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
	ft_putstr_i(str, flags);
}

void ft_puthexa_i(long nb, int upp, t_flags *flags)
{
	int size;
	long copy;

	copy = nb;
	size = 0;
	if (nb == 0 && flags->precision_given == 1 && flags->precision == 0 && (flags->type == 'x' || flags->type == 'X' || flags->type == 'p'))
		return;
	if (nb == 0)
	{
		ft_putchar_i('0', flags);
		return;
	}
	while (copy > 0)
	{
		copy = copy / 16;
		size++;
	}
	ft_puthexa_i_util(nb, size, upp, flags);
}

void ft_print_var(t_flags *flags,va_list *args)
{
	if (flags->type == 'c')
		ft_putchar_i(va_arg(*args, int), flags);
	if (flags->type == 's')
		ft_putstr_i(va_arg(*args, char *), flags);
	if (flags->type == 'p')
		ft_puthexa_i(va_arg(*args, unsigned long), 0, flags);
	if (flags->type == 'd')
		ft_putnbr_i(va_arg(*args, int), flags);
	if (flags->type == 'i')
		ft_putnbr_i(va_arg(*args, int), flags);
	if (flags->type == 'u')
		ft_putnbr_i(va_arg(*args, unsigned int), flags);
	if (flags->type == 'x')
		ft_puthexa_i(va_arg(*args, unsigned int), 0, flags);
	if (flags->type == 'X')
		ft_puthexa_i(va_arg(*args, unsigned int), 1, flags);
	if (flags->type == '%')
		ft_putchar_i('%', flags);
}

int ft_putcharrepeat(int c, int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		write(1, &c, 1);
		i++;
	}
	return (nb);
}