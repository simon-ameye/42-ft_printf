/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:34:20 by sameye            #+#    #+#             */
/*   Updated: 2021/07/23 17:43:47 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_flags
{
	int				zero;
	int				minus;
	int				width;
	int				precision;
	int				type;
	int				inputmute;
	int				resnegative;
	int				remaining;
	int				count;
	int				precision_given;
	int				width_given;
}					t_flags;

int		ft_printf(const char *str, ...);
int		ft_threat_format(char *format_str, va_list *args);
int		ft_threat_var(char *format_string, va_list *args, int *pt_count);
void	ft_init_flags(t_flags *pt_flags);
int		ft_parse(char *format_string, t_flags *flags, va_list *args);
void	ft_print_var(t_flags *flags, va_list *args);
void	ft_putchar_i(int c, t_flags *flags);
void	ft_putstr_i(char *str, t_flags *flags);
int		ft_putcharrepeat(int c, int nb);
int		ft_max(int nb1, int nb2);
int		ft_min(int nb1, int nb2);
int		ft_is_num_type(int c);
void	ft_threat_percent(t_flags *flags, int strlen, int *pt_count,
			va_list *argscopy);
void	ft_threat_str(t_flags *flags, int strlen, int *pt_count,
			va_list *argscopy);
void	ft_threat_int(t_flags *flags, int strlen, int *pt_count,
			va_list *argscopy);
void	ft_putnbr_i_util(long nb, int size, t_flags *flags);
void	ft_putnbr_i(long nb, t_flags *flags);
void	ft_puthexa_i_util(unsigned long long nb, int size, int upp,
			t_flags *flags);
void	ft_puthexa_i(unsigned long long nb, int upp, t_flags *flags);
int		ft_type_in_list(int i);
int		ft_flag_in_list(int i);
int		ft_flagnumparse(char *str, int *flag);
void	ft_flag_parse(char *format_str, t_flags *flags, va_list *args, int *i);
int		ft_isdigit(int c);

#endif