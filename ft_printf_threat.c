/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_threat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameye <sameye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:34:46 by sameye            #+#    #+#             */
/*   Updated: 2021/07/02 19:14:48 by sameye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void ft_init_flags(t_flags *pt_flags)
{
    (void) pt_flags;
    printf("flags initialises!!!");
}

int ft_threat_var(char *format_string, va_list args, int *pt_count)
{
    t_flags flags;
    
    (void) format_string;
    (void) args;
    (void) pt_count;
    ft_init_flags(&flags);

    return(2);
}