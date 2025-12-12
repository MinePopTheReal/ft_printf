/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:51:18 by tmalpert          #+#    #+#             */
/*   Updated: 2025/12/12 18:38:20 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	conversion_attribution(char c, va_list args, int *count, int *argc)
{
	*argc += 1;
	if (c == 'c')
		*count += ft_putchar(va_arg(args, int));
	else if (c == 's')
		*count += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		*count += ft_putnbr(va_arg(args, int), 0);
	else if (c == 'u')
		*count += ft_putnbr_u(va_arg(args, unsigned int), 10, 0);
	else if (c == 'x')
		*count += ft_putnbr_u(va_arg(args, int), 16, 0);
	else if (c == 'X')
		*count += ft_putnbr_u(va_arg(args, int), 16, 1);
	else if (c == '%')
		*count += ft_putchar('%');
	else if (c == 'p')
		*count += ft_adress(va_arg(args, void *));
	else
	{
		*count += ft_putchar('%');
		return (false);
	}
	return (true);
}

int	ft_printf(const char *tab, ...)
{
	va_list	args;
	int		count;
	bool	success;
	int		argc;

	argc = 0;
	success = true;
	count = 0;
	if (!tab)
		return (-1);
	va_start(args, tab);
	while (*tab)
	{
		if (*tab == '%')
		{
			if (!conversion_attribution(*++tab, args, &count, &argc))
				success = false;
		}
		else
			count += ft_putchar(*tab);
		tab++;
	}
	if (argc == 1 && !success)
		return (-1);
	return (count);
}
