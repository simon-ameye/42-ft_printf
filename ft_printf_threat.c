/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_threat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:34:46 by sameye            #+#    #+#             */
/*   Updated: 2021/07/03 02:51:01 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void ft_init_flags(t_flags *flags)
{
	flags->dot = 0;
	flags->minus = 0;
	flags->star = 0;
	flags->type = 0;
	flags->zero = 0;
	flags->digit = 0;
}

int ft_threat_var(char *format_string, va_list *args, int *pt_count)
{
	t_flags flags;
	int i;
	
	ft_init_flags(&flags);
	i = ft_flag_parse(format_string, &flags);
	*pt_count = ft_print_var(&flags, args);
	return(i);
}