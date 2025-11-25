/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_fonction_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:41:55 by tmalpert          #+#    #+#             */
/*   Updated: 2025/11/25 13:46:21 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_adress(void	*p)
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
