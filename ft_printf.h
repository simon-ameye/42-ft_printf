/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:34:20 by sameye            #+#    #+#             */
/*   Updated: 2021/07/06 19:09:13 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

typedef	struct		s_flags
{
	int				zero;
	int				minus;
	int				width;
	int				precision;
	int				type;
}					t_flags;

int     ft_printf(const char *str, ...);
int ft_threat_format(char *format_str, va_list *args);
int ft_threat_var(char *format_string, va_list *args, int *pt_count);
void ft_init_flags(t_flags *pt_flags);
int ft_flag_parse(char *format_string, t_flags *flags, va_list *args);
int ft_print_var(t_flags *flags,va_list *args);





#endif