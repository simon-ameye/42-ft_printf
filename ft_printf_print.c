/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:34:42 by sameye            #+#    #+#             */
/*   Updated: 2021/07/03 10:56:18 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_putstr_i(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		write(1, &c, 1);
		i++;
	}
	return (i);
}

int ft_putnbr_i(int i)
{
	ft_putnbr_fd(i, 1);
	return (2);
}

int ft_print_var(t_flags *flags,va_list *args)
{
	int count;
	
	count = 0;
	if (flags->type == 's')
		count = ft_putstr_i(va_arg(*args, char *));
	if (flags->type == 'd')
		count = ft_putnbr_i(va_arg(*args, int));
	return (count);
}
