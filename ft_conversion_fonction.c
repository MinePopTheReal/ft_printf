/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_fonction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:53:37 by tmalpert          #+#    #+#             */
/*   Updated: 2025/11/25 13:12:18 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return(1);
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

int	ft_putnbr(int nb, int cap)
{
	long int	n;
	char		*tab;
	int			count;

	n = nb;
	count = 0;
	tab = "0123456789abcdef";
	if (cap == 1)
		tab = "0123456789ABCDEF";
	if (n < 0)
	{
		count += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		count += ft_putnbr((unsigned int)n / 10, cap);
		count += ft_putchar(tab[(unsigned int)n % 10]);
	}
	else
		count += ft_putchar(tab[n]);
	return (count);
}

int	ft_putnbr_u(unsigned int nb, unsigned int base, int cap)
{
	char	*tab;
	int		count;

	count = 0;
	tab = "0123456789abcdef";
	if (cap == 1)
	{
		tab = "0123456789ABCDEF";
	}
	if (nb >= base)
	{
		count += ft_putnbr_u(nb / base, base, cap);
		count += ft_putchar(tab[nb % base]);
	}
	else
		count += ft_putchar(tab[nb]);
	return (count);
}

int	ft_putnbr_hex(unsigned long int nb, unsigned int base, int cap)
{
	char	*tab;
	int		count;

	count = 0;
	tab = "0123456789abcdef";
	if (cap == 1)
	{
		tab = "0123456789ABCDEF";
	}
	if (nb >= base)
	{
		count += ft_putnbr_hex(nb / base, base, cap);
		count += ft_putchar(tab[nb % base]);
	}
	else
		count += ft_putchar(tab[nb]);
	return (count);
}

int	ft_jesaispas(void	*p)
{
	unsigned long int	addr;
	int					count;

	if (!p)
		return (ft_putstr("(nil)"));
	addr = (unsigned long int)p;
	count = ft_putstr("0x");
	count += ft_putnbr_hex(addr, 16, 0);
	return (count);
}
