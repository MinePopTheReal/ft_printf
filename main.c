/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:07:28 by tmaldert          #+#    #+#             */
/*   Updated: 2025/12/12 18:38:28 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

int	main(void)
{
	printf("Size : %d\n", ft_printf("Erreur %z %d\n", 423423));
	return (0);
}
