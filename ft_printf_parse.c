/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:34:40 by sameye            #+#    #+#             */
/*   Updated: 2021/07/03 02:55:41 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_type_in_list(int i)
{
	return (i== 'c' || i == 's' || i == 'p' || i == 'd'
			 || i == 'i' || i == 'u' || i == 'x' || i == 'X' || i == '%');
}

int ft_flag_in_list(int i)
{
	return (i == '-' || i == '0' || i == '.' || i == '*');
}
int ft_flag_parse(char *format_str, t_flags *flags)
{
	int i;

	i = 1;
	while (1)
	{
		if (!ft_type_in_list(format_str[i]) && !ft_flag_in_list(format_str[i])
				 && !ft_isdigit(format_str[i]))
			break ;
		if (format_str[i] == '0' && flags->minus == 0)
			flags->zero = 1;
		if (format_str[i] == '.')
			flags->dot = 1;
		if (format_str[i] == '-')
			flags->minus = 1;
		if (format_str[i] == '*')
			flags->star = 1;
		if (ft_isdigit(format_str[i]))
			flags->digit = format_str[i] - '0';
		if (ft_type_in_list(format_str[i]))
		{
			flags->type = format_str[i];
			i++;
			break ;
		}
		i++;
	}
	return(i);
}