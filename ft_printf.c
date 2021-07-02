/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:34:49 by sameye            #+#    #+#             */
/*   Updated: 2021/07/02 19:17:02 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_threat_format(char *format_str, va_list args)
{
	int	count;
	int	printcount;
	int i;

	printcount = 0;
	i = 0;
	while (1)
	{
		if (format_str[i] == '\0')
			break ;
		if (format_str[i] == '%')
		{
			i += ft_threat_var(&format_str[i], args, &count);
			printcount += count;
		}
		else
		{
			write(1, &format_str[i], 1);
			printcount++;
		}
	}
	return (printcount);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		printcount;
	char	*format_str;
	va_start(args, input);

	format_str = ft_strdup(input);
	printcount = ft_threat_format(format_str, args);
	free(format_str);
	va_end(args);
	return (printcount);
}