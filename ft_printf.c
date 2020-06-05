/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 07:44:31 by nalonso-          #+#    #+#             */
/*   Updated: 2020/06/04 18:05:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    parser(t_point *format, const char *input)
{   
    int     z;
    format->result = NULL;
    if(input[format->i] == 's')
    {
        format->result = va_arg(format->args, char*);
        z = 0;
        while(format->result[z])
        {
            format->count += write(1, &(format->result[z]), 1);
            z++;
        }
    }
    if(input[format->i] == 'c')
    {
        write(1, " c specifier ", 13);
    }
  }

int     ft_printf(const char *input, ...)
{
    t_point   format;
    format.i = 0;
    format.count = 0;
    va_start(format.args, input);
    while(input[format.i] != '\0')
    {
      if(input[format.i] == '%')
      {
        //write(1, "Format", 6);
        input[format.i++];
        parser(&format, input);
        }
      else {
        format.count = write(1, &input[format.i], 1);
      }
      format.i++;
      }
    va_end(format.args);
    return(format.count);
}

int   main()
{
    printf("print s%string\n", "HHH");
    ft_printf("print s%string", "HHH");
    //ft_printf("%");
    //ft_printf("%%");
    //ft_printf("string:%.1s", "bonjour");
    //ft_printf("string: %s\n", "bonjour");
    //ft_printf("%20s\n", "Hallo h\\eimur");
    //ft_printf("%03.1s\n", "Hallo heimur");
    //ft_printf("%030.5s\n", "Hallo heimur");
    //ft_printf("string precision |%.9s|\n", "jesuisbonjourbonjour");
    //ft_printf("string padding |%9s|\n", "bon");
    return (0);
}