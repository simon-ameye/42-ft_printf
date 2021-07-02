/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:34:20 by sameye            #+#    #+#             */
/*   Updated: 2021/07/02 19:33:11 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

typedef	struct		s_flags
{
	int				type;
	int				minus;
	int				zero;
	int				dot;
	int				star;
}					t_flags;

int     ft_printf(const char *str, ...);
int ft_threat_format(char *format_str, va_list args);
int ft_threat_var(char *format_string, va_list args, int *pt_count);
void ft_init_flags(t_flags *pt_flags);




#endif