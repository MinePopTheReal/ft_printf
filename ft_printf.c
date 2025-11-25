/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:51:18 by tmalpert          #+#    #+#             */
/*   Updated: 2025/11/25 13:45:25 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion_attribution(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(args, int), 0);
	else if (c == 'u')
		count += ft_putnbr_u(va_arg(args, unsigned int), 10, 0);
	else if (c == 'x')
		count += ft_putnbr_u(va_arg(args, int), 16, 0);
	else if (c == 'X')
		count += ft_putnbr_u(va_arg(args, int), 16, 1);
	else if (c == '%')
		count += ft_putchar('%');
	else if (c == 'p')
		count += ft_adress(va_arg(args, void *));
	else
		return (0);
	return (count);
}

int	ft_printf(const char *tab, ...)
{
	int		i;
	va_list	args;
	int		count;

	i = 0;
	count = 0;
	va_start(args, tab);
	while (tab[i])
	{
		if (tab[i] == '%')
			count += conversion_attribution(tab[++i], args);
		else
		{
			ft_putchar(tab[i]);
			count++;
		}
		i++;
	}
	return (count);
}
