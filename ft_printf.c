/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:34:49 by sameye            #+#    #+#             */
/*   Updated: 2021/07/19 12:19:43 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_threat_format(char *format_str, va_list *args)
{
	int	printcount;
	int	i;

	printcount = 0;
	i = 0;
	while (1)
	{
		if (format_str[i] == '\0')
			break ;
		if (format_str[i] == '%')
		{
			i += ft_threat_var(&format_str[i], args, &printcount);
		}
		else
		{
			write(1, &format_str[i], 1);
			printcount++;
			i++;
		}
	}
	return (printcount);
}

int	ft_printf(const char *format_str, ...)
{
	va_list	args;
	int		printcount;

	va_start(args, format_str);
	printcount = ft_threat_format((char *)format_str, &args);
	va_end(args);
	return (printcount);
}
