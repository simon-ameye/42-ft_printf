/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_nums.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 11:35:33 by sameye            #+#    #+#             */
/*   Updated: 2021/07/20 11:35:52 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_i_util(long nb, int size, t_flags *flags)
{
	char	str[10 + 1];
	int		i;

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

void	ft_putnbr_i(long nb, t_flags *flags)
{
	int		size;
	long	copy;
	int		isneg;

	if (nb == 0 && flags->precision_given == 1 && flags->precision == 0
		&& (flags->type == 'i' || flags->type == 'd' || flags->type == 'u'))
		return ;
	if (nb == 0)
		ft_putchar_i('0', flags);
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

void	ft_puthexa_i_util(unsigned long long nb, int size, int upp,
			t_flags *flags)
{
	char	str[16 + 1];
	int		i;
	long	modulo;

	i = 0;
	while (i < size)
	{
		modulo = nb % 16;
		if (modulo <= 9)
			str[size - 1 - i] = modulo + '0';
		else
			str[size - 1 - i] = modulo + 'a' - 10 + ('A' - 'a') * (upp == 1);
		i++;
		nb = nb / 16;
	}
	str[i] = '\0';
	ft_putstr_i(str, flags);
}

void	ft_puthexa_i(unsigned long long nb, int upp, t_flags *flags)
{
	int					size;
	unsigned long long	copy;

	copy = nb;
	size = 0;
	if (nb == 0 && flags->precision_given == 1 && flags->precision == 0
		&& (flags->type == 'x' || flags->type == 'X' || flags->type == 'p'))
		return ;
	if (nb == 0)
	{
		ft_putchar_i('0', flags);
		return ;
	}
	while (copy > 0)
	{
		copy = copy / 16;
		size++;
	}
	ft_puthexa_i_util(nb, size, upp, flags);
}
