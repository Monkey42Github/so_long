/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschemit <pschemit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:50:24 by pschemit          #+#    #+#             */
/*   Updated: 2022/06/07 19:18:21 by pschemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

char	*ft_itoa(int nb)
{
	char	buf[12];
	char	*str;
	int		i;
	int		j;
	int		neg;

	j = 0;
	i = 12;
	neg = 0;
	if (nb >= 0 || neg++)
		nb = -nb;
	buf[--i] = '0' - nb % 10;
	while (nb / 10)
	{
		nb = nb / 10;
		buf[--i] = '0' - nb % 10;
	}
	str = malloc(sizeof(char) * ((12 - i + neg) + 1));
	if (neg)
		str[j++] = '-';
	while (12 - i)
		*(str + j++) = *(buf + i++);
	*(str + j) = '\0';
	return (str);
}
