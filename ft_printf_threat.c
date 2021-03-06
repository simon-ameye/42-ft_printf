/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_threat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:34:46 by sameye            #+#    #+#             */
/*   Updated: 2021/07/23 19:23:53 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_threat_percent(t_flags *flags, int strlen, int *pt_count,
			va_list *argscopy)
{
	int	leftchars;
	int	rightspaces;
	int	leftchar;

	if (flags->precision_given == 1)
		flags->remaining = ft_min(strlen, flags->precision);
	else
		flags->remaining = strlen;
	leftchars = ft_max(0, (flags->minus == 0)
			* (flags->width - flags->remaining) * (flags->width_given == 1));
	rightspaces = ft_max(0, (flags->minus == 1)
			* (flags->width - flags->remaining) * (flags->width_given == 1));
	leftchar = (flags->zero == 0) * ' ' + (flags->zero == 1) * '0';
	*pt_count += ft_putcharrepeat(leftchar, leftchars);
	flags->count = 0;
	ft_print_var(flags, argscopy);
	*pt_count += flags->count;
	*pt_count += ft_putcharrepeat(' ', rightspaces);
}

void	ft_threat_str(t_flags *flags, int strlen, int *pt_count,
			va_list *argscopy)
{
	int	leftcharacs;
	int	rightspaces;

	if (flags->precision_given == 1)
		flags->remaining = ft_min(strlen, flags->precision);
	else
		flags->remaining = strlen;
	leftcharacs = ft_max(0, (flags->minus == 0)
			* (flags->width - flags->remaining) * (flags->width_given == 1));
	rightspaces = ft_max(0, (flags->minus == 1)
			* (flags->width - flags->remaining) * (flags->width_given == 1));
	*pt_count += ft_putcharrepeat(' ' * (flags->zero == 0)
			+ '0' * (flags->zero == 1), leftcharacs);
	flags->count = 0;
	ft_print_var(flags, argscopy);
	*pt_count += flags->count;
	*pt_count += ft_putcharrepeat(' ', rightspaces);
}

void	ft_threat_int(t_flags *flags, int strlen, int *pt_count,
	va_list *argscopy)
{
	int	leftzeros;
	int	leftspaces;
	int	rightspaces;
	int	neg;

	neg = flags->resnegative;
	leftzeros = ft_max(0, flags->precision - strlen);
	if (flags->minus == 0 && flags->zero == 1 && flags->precision == 0)
		leftzeros = ft_max(leftzeros, flags->width - strlen - neg);
	leftzeros = leftzeros * (flags->precision_given == 0 || strlen != 0);
	leftspaces = ft_max(0, (flags->minus == 0) * (flags->width
				- leftzeros - strlen - neg - 2 * (flags->type == 'p')));
	rightspaces = ft_max(0, (flags->minus == 1) * (flags->width - neg
				- strlen - leftzeros - leftspaces - 2 * (flags->type == 'p')));
	*pt_count += ft_putcharrepeat(' ', leftspaces);
	if (flags->type == 'p')
		ft_putstr_i("0x", flags);
	*pt_count += 2 * (flags->type == 'p');
	*pt_count += ft_putcharrepeat('-', neg);
	*pt_count += ft_putcharrepeat('0', leftzeros);
	flags->count = 0;
	ft_print_var(flags, argscopy);
	*pt_count += flags->count;
	*pt_count += ft_putcharrepeat(' ', rightspaces);
}

int	ft_threat_var(char *format_string, va_list *args, int *pt_count)
{
	t_flags	flags;
	int		i;
	va_list	argscopy;
	int		strlen;

	ft_init_flags(&flags);
	i = ft_parse(format_string, &flags, args);
	va_copy(argscopy, *args);
	flags.inputmute = 1;
	flags.remaining = -1;
	ft_print_var(&flags, args);
	strlen = flags.count;
	flags.inputmute = 0;
	if (ft_is_num_type(flags.type))
		ft_threat_int(&flags, strlen, pt_count, &argscopy);
	if (flags.type == 'c' || flags.type == 's')
		ft_threat_str(&flags, strlen, pt_count, &argscopy);
	if (flags.type == '%')
		ft_threat_percent(&flags, strlen, pt_count, &argscopy);
	return (i);
}
