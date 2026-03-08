/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:53:37 by tmalpert          #+#    #+#             */
/*   Updated: 2026/03/08 19:39:18 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

static int	print_nbr(unsigned long long n, int base, char *tab)
{
	int	count;

	count = 0;
	if (n >= (unsigned long long)base)
		count += print_nbr(n / base, base, tab);
	count += ft_putchar(tab[n % base]);
	return (count);
}

int	putnbr_base(long long number, int base, bool is_upper)
{
	int						count;
	char					*tab;
	unsigned long long		nb;

	count = 0;
	tab = "0123456789abcdef";
	if (is_upper)
		tab = "0123456789ABCDEF";
	if (number < 0 && base == 10)
	{
		count += ft_putchar('-');
		nb = (unsigned long long)(-number);
	}
	else
		nb = (unsigned long long)number;
	count += print_nbr(nb, base, tab);
	return (count);
}

int	ft_adress(void	*p)
{
	unsigned long int	addr;
	int					count;

	if (!p)
		return (ft_putstr("(nil)"));
	addr = (unsigned long int)p;
	count = ft_putstr("0x");
	count += putnbr_base(addr, 16, false);
	return (count);
}
