/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 08:04:37 by nalonso-          #+#    #+#             */
/*   Updated: 2020/06/04 17:36:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// LIBRARIES
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

// STRUCTURES
typedef struct s_point
{
    va_list     args;
    char        *input;
    int         count;
    int         i;
    char        *result;
    //char        *s;
}               t_point; //typedef_point

// PROTOTYPES
int     printf(const char *s, ...);

#endif