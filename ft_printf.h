/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:53:49 by tmalpert          #+#    #+#             */
/*   Updated: 2025/11/25 13:29:55 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>

int 	ft_printf(const char *tab, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
char	*ft_itoa(int n);
int		ft_putnbr(int nb, int cap);
int		ft_putnbr_u(unsigned int nb, unsigned int base, int cap);
int		ft_jesaispas(void *p);
int		ft_putnbr_hex(unsigned long int nb, unsigned int base, int cap);

#endif