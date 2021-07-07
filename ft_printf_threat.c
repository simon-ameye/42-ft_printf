/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_threat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:34:46 by sameye            #+#    #+#             */
/*   Updated: 2021/07/07 19:46:13 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void ft_init_flags(t_flags *flags)
{
	flags->zero = 0;
	flags->minus = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->type = 0;
	flags->resnegative = 0;
	flags->inputmute = 0;
}

int ft_max(int nb1, int nb2)
{
	if (nb1 >= nb2)
		return (nb1);
	return (nb2);
}

int ft_threat_var(char *format_string, va_list *args, int *pt_count)
{
	t_flags flags;
	int i;
	va_list argscopy;
	int strlen;
	int leftzeros;
	int leftspaces;
	int rightspaces;
	int neg;
	
	ft_init_flags(&flags);
	i = ft_flag_parse(format_string, &flags, args);
	flags.width = ft_max(0, flags.width);
	flags.precision = ft_max(0, flags.precision);

	va_copy(argscopy, *args);
	flags.inputmute = 1;
	strlen = ft_print_var(&flags, args);
	flags.inputmute = 0;

	neg = flags.resnegative;
	leftzeros = ft_max(0, flags.precision - strlen);
	leftzeros = ft_max(leftzeros, (flags.minus == 0) * (flags.zero == 1) * (flags.precision == 0) * (flags.width - strlen - neg));
	leftspaces = ft_max(0, (flags.minus == 0)  * (flags.width - leftzeros - strlen - neg));
	rightspaces = ft_max(0, (flags.minus == 1) * (flags.width - neg - strlen));

	*pt_count += ft_putcharrepeat(' ', leftspaces);
	*pt_count += ft_putcharrepeat('-', neg);
	*pt_count += ft_putcharrepeat('0', leftzeros);
	*pt_count += ft_print_var(&flags, &argscopy);
	*pt_count += ft_putcharrepeat(' ', rightspaces);

	//printf("\nzero %i, minus %i, width %i, precision %i, type %c\n", flags.zero, flags.minus, flags.width, flags.precision, flags.type);
	return(i);
}


