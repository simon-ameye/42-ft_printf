/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:34:40 by sameye            #+#    #+#             */
/*   Updated: 2021/07/20 11:28:04 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_in_list(int i)
{
	return (i == 'c' || i == 's' || i == 'p' || i == 'd'
		|| i == 'i' || i == 'u' || i == 'x' || i == 'X' || i == '%');
}

int	ft_flag_in_list(int i)
{
	return (i == '-' || i == '0' || i == '.' || i == '*');
}

int	ft_flagnumparse(char *str, int *flag)
{
	int	i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		*flag = *flag * 10 + (str[i] - '0');
		i++;
	}
	return (i - 1);
}

void	ft_flag_parse(char *format_str, t_flags *flags, va_list *args, int *i)
{
	if (format_str[*i] == '0' && flags->minus == 0 && flags->width_given == 0
		&& flags->precision_given == 0)
		flags->zero = 1;
	if (format_str[*i] == '-')
		flags->minus = 1;
	if (format_str[*i] == '*' && flags->precision_given == 0)
	{
		flags->width = va_arg(*args, int);
		flags->width_given = 1;
	}
	if (ft_isdigit(format_str[*i]) && flags->precision_given == 0)
	{
		*i += ft_flagnumparse(&(format_str[*i]), &(flags->width));
		flags->width_given = 1;
	}
	if (format_str[*i] == '.')
		flags->precision_given = 1;
	if (format_str[*i] == '*' && flags->precision_given == 1)
		flags->precision = va_arg(*args, int);
	if (ft_isdigit(format_str[*i]) && flags->precision_given == 1)
	{
		flags->precision_given = 1;
		*i += ft_flagnumparse(&(format_str[*i]), &(flags->precision));
	}
}

int	ft_parse(char *format_str, t_flags *flags, va_list *args)
{
	int	i;

	i = 1;
	while (1)
	{
		if (!ft_type_in_list(format_str[i]) && !ft_flag_in_list(format_str[i])
			&& !ft_isdigit(format_str[i]))
			break ;
		ft_flag_parse(format_str, flags, args, &i);
		if (ft_type_in_list(format_str[i]))
		{
			flags->type = format_str[i++];
			break ;
		}
		i++;
	}
	if (flags->width < 0)
	{
		flags->width = -flags->width;
		flags->minus = 1;
	}
	if (flags->precision < 0)
		flags->precision_given = 0;
	flags->precision = ft_max(0, flags->precision);
	return (i);
}
