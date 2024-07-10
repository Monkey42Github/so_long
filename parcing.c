/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschemit <pschemit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:49:48 by pschemit          #+#    #+#             */
/*   Updated: 2022/06/08 11:28:00 by pschemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parcing_2(t_data	*d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (d->map[i])
	{
		j = 0;
		while (d->map[i][j] != '\n' && d->map[i][j] != '\0')
		{
			parce_autre_char(d, i, j);
			parce_bord(d, i, j);
			parce_ecp(d, i, j);
			j++;
		}
		if (j != d->l || j == d->h)
		{
			ecrire("Map_erreur : Pas rectangle\n");
			exit(1);
		}
		i++;
	}
	return (0);
}

void	parce_ber(char **av)
{
	int	i;

	i = 0;
	if (!av[1])
	{	
		ecrire("Map_Error : not write\n");
		exit(1);
	}
	while (av[1][i])
		i++;
	if (av[1][i -1] != 'r' || av[1][i -2] != 'e'
	|| av[1][i -3] != 'b' || av[1][i -4] != '.')
	{
		ecrire("Map_Error : error extension\n");
		exit(1);
	}
}

void	parcing(t_data	*d)
{
	taille_ligne(d);
	taille_hauteur(d);
	parcing_2(d);
}
