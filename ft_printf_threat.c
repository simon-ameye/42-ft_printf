/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_threat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:34:46 by sameye            #+#    #+#             */
/*   Updated: 2021/07/06 22:14:13 by sameye           ###   ########.fr       */
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
}

int ft_threat_var(char *format_string, va_list *args, int *pt_count)
{
	t_flags flags;
	int i;
	int widthadd;
	int varstrlen;
	va_list argscopy;
	
	ft_init_flags(&flags);
	i = ft_flag_parse(format_string, &flags, args);
	va_copy(argscopy, *args);
	varstrlen = ft_print_var(&flags, args, 1);
	widthadd = flags.width - varstrlen;
	if (widthadd > 0 && flags.zero == 0 && flags.minus == 0)
		ft_putcharrepeat(' ', widthadd);
	if (widthadd > 0 && flags.zero == 1 && flags.minus == 0)
		ft_putcharrepeat('0', widthadd);
	*pt_count = ft_print_var(&flags, &argscopy, 0) + widthadd * (widthadd > 0);
	if (widthadd > 0 && flags.zero == 0 && flags.minus == 1)
		ft_putcharrepeat(' ', widthadd);
	//printf("\nzero %i, minus %i, width %i, precision %i, type %c\n", flags.zero, flags.minus, flags.width, flags.precision, flags.type);
	return(i);
}