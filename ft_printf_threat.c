/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_threat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:34:46 by sameye            #+#    #+#             */
/*   Updated: 2021/07/15 19:47:27 by sameye           ###   ########.fr       */
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
	flags->remaining = 0;
	flags->count = 0;
}

int ft_max(int nb1, int nb2)
{
	if (nb1 >= nb2)
		return (nb1);
	return (nb2);
}

int ft_min(int nb1, int nb2)
{
	if (nb1 <= nb2)
		return (nb1);
	return (nb2);
}

int ft_is_num_type(int c)
{
	if (c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

void ft_threat_str(t_flags *flags, int strlen, int *pt_count, va_list *argscopy)
{
	int leftspaces;
	int rightspaces;

	flags->remaining = ft_min(strlen, flags->precision);
	//printf("\nzero %i, minus %i, width %i, precision %i, type %c, inputmute %i, resnegative %i, remaining %i\n", flags->zero, flags->minus, flags->width, flags->precision, flags->type, flags->inputmute, flags->resnegative, flags->remaining);
	leftspaces = ft_max(0, (flags->minus == 0)  * (flags->width - flags->remaining));
	rightspaces = ft_max(0, (flags->minus == 1) * (flags->width - flags->remaining));
	*pt_count += ft_putcharrepeat(' ', leftspaces);
	flags->count = 0;
	ft_print_var(flags, argscopy);
	*pt_count += flags->count;
	*pt_count += ft_putcharrepeat(' ', rightspaces);

}

void ft_threat_int(t_flags *flags, int strlen, int *pt_count, va_list *argscopy)
{
	int leftzeros;
	int leftspaces;
	int rightspaces;
	int neg;
	int tempcount;

	neg = flags->resnegative;
	leftzeros = ft_max(0, flags->precision - strlen);
	leftzeros = ft_max(leftzeros, (flags->minus == 0) * (flags->zero == 1) * (flags->precision == 0) * (flags->width - strlen - neg));

	leftspaces = ft_max(0, (flags->minus == 0)  * (flags->width - leftzeros - strlen - neg));
	rightspaces = ft_max(0, (flags->minus == 1) * (flags->width - neg - strlen));

	*pt_count += ft_putcharrepeat(' ', leftspaces);
	*pt_count += ft_putcharrepeat('-', neg);
	*pt_count += ft_putcharrepeat('0', leftzeros);

	tempcount = ft_print_var(flags, argscopy);
	*pt_count += tempcount;
	*pt_count += ft_putcharrepeat(' ', rightspaces);
	//printf("\nzero %i, minus %i, width %i, precision %i, type %c, inputmute %i, resnegative %i, remaining %i\n", flags->zero, flags->minus, flags->width, flags->precision, flags->type, flags->inputmute, flags->resnegative, flags->remaining);
}


int ft_threat_var(char *format_string, va_list *args, int *pt_count)
{
	t_flags flags;
	int i;
	va_list argscopy;
	int strlen;
	
	ft_init_flags(&flags);
	i = ft_flag_parse(format_string, &flags, args);
	//printf("\nzero %i, minus %i, width %i, precision %i, type %c, inputmute %i, resnegative %i, remaining %i\n", flags.zero, flags.minus, flags.width, flags.precision, flags.type, flags.inputmute, flags.resnegative, flags.remaining);

	//flags.zero = flags.zero * (ft_is_num_type(flags.type) + (flags.type == '%'));

	va_copy(argscopy, *args);
	flags.inputmute = 1;
	flags.remaining = -1;
	//strlen = ft_print_var(&flags, args);
	//printf("strlen1=%i", strlen);
	ft_print_var(&flags, args);
	strlen = flags.count;
	//printf("strlen2=%i", strlen);
	flags.inputmute = 0;

	if (ft_is_num_type(flags.type))
		ft_threat_int(&flags, strlen, pt_count, &argscopy);
	if (flags.type == 'c' || flags.type == 's' || flags.type == '%')
		ft_threat_str(&flags, strlen, pt_count, &argscopy);
	return (i);
}


