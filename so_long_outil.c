/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_outil.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschemit <pschemit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:33:45 by pschemit          #+#    #+#             */
/*   Updated: 2022/06/07 19:45:04 by pschemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ecrire(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	taille_ligne(t_data	*d)
{
	int	i;

	i = 0;
	while (d->map[0][i])
		i++;
	i--;
	d->l = i;
}

void	taille_hauteur(t_data	*d)
{
	int	i;

	i = 0;
	while (d->map[i])
		i++;
	d->h = i;
}

int	ft_destroy(void)
{
	exit(1);
}
