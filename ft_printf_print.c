/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:34:42 by sameye            #+#    #+#             */
/*   Updated: 2021/07/20 11:42:06 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_i(int c, t_flags *flags)
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

void	ft_putstr_i(char *str, t_flags *flags)
{
	int		i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr_i("(null)", flags);
		return ;
	}
	while (str[i] != '\0')
	{
		ft_putchar_i(str[i], flags);
		i++;
	}
	return ;
}

void	ft_print_var(t_flags *flags, va_list *args)
{
	if (flags->type == 'c')
		ft_putchar_i(va_arg(*args, int), flags);
	if (flags->type == 's')
		ft_putstr_i(va_arg(*args, char *), flags);
	if (flags->type == 'p')
		ft_puthexa_i(va_arg(*args, unsigned long long), 0, flags);
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

int	ft_putcharrepeat(int c, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		write(1, &c, 1);
		i++;
	}
	return (nb);
}
