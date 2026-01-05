/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:51:18 by tmalpert          #+#    #+#             */
/*   Updated: 2026/01/05 18:38:23 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	count_percent(const char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count++;
			i++;
		}
		i++;
	}
	return (count);
}

static bool	conversion_attribution(char c, t_attribution *attrib)
{
	attrib->argc += 1;
	if (c == 'c')
		attrib->count += ft_putchar(va_arg(attrib->args, int));
	else if (c == 's')
		attrib->count += ft_putstr(va_arg(attrib->args, char *));
	else if (c == 'd' || c == 'i')
		attrib->count += ft_putnbr(va_arg(attrib->args, int), 0);
	else if (c == 'u')
		attrib->count += ft_putnbr_u(va_arg(attrib->args, unsigned int), 10, 0);
	else if (c == 'x')
		attrib->count += ft_putnbr_u(va_arg(attrib->args, int), 16, 0);
	else if (c == 'X')
		attrib->count += ft_putnbr_u(va_arg(attrib->args, int), 16, 1);
	else if (c == '%')
		attrib->count += ft_putchar('%');
	else if (c == 'p')
		attrib->count += ft_adress(va_arg(attrib->args, void *));
	else
	{
		if (count_percent(attrib->tab) > 1)
			attrib->count += ft_putchar('%');
		return (false);
	}
	return (true);
}

static int	error(int argc, bool success, int count)
{
	if (argc == 1 && !success)
		return (-1);
	return (count);
}

int	ft_printf(const char *tab, ...)
{
	t_attribution	attrib;
	size_t			i;

	i = 0;
	attrib.tab = tab;
	attrib.argc = 0;
	attrib.success = true;
	attrib.count = 0;
	if (!tab)
		return (-1);
	va_start(attrib.args, tab);
	while (attrib.tab[i])
	{
		if (attrib.tab[i] == '%')
		{
			if (!conversion_attribution(attrib.tab[++i], &attrib))
				attrib.success = false;
		}
		else
			attrib.count += ft_putchar(attrib.tab[i]);
		i++;
	}
	va_end(attrib.args);
	return (error(attrib.argc, attrib.success, attrib.count));
}
int main(void)
{
	printf("%d",ft_printf("je sais pas quoi mettre %p", (void *)551551154));
	return (0);
}
