/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschemit <pschemit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:31:24 by pschemit          #+#    #+#             */
/*   Updated: 2022/06/07 15:09:08 by pschemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parce_bord(t_data	*d, int i, int j)
{
	int	erreur;

	erreur = 0;
	if ((j == d->l -1) && (d->map[i][j] != '1'))
	{
		ecrire("Map_Error : bordure droite\n");
		exit(1);
	}
	if ((j == 0) && (d->map[i][j] != '1'))
	{
		ecrire("Map_Error : bordure gauche\n");
		exit(1);
	}
	if ((i == 0) && (d->map[i][j] != '1'))
	{
		ecrire("Map_Error : bordure haut\n");
		exit(1);
	}
	if ((i == d->h -1) && (d->map[i][j] != '1'))
	{
		ecrire("Map_Error : bordure bas\n");
		exit(1);
	}
}

void	parce_autre_char(t_data	*d, int i, int j)
{
	if (d->map[i][j] != 'E' && d->map[i][j] != 'P'
	&& d->map[i][j] != 'C' && d->map[i][j] != '0'
	&& d->map[i][j] != '1' && d->map[i][j] != '\n'
	&& d->map[i][j] != '\0')
	{
		ecrire("Map_error : element inconnue\n");
		exit(1);
	}
}

void	parce_ecp(t_data	*d, int i, int j)
{
	static int	c = 0;
	static int	p = 0;
	static int	e = 0;

	if (d->map[i][j] == 'E')
		e++;
	if (d->map[i][j] == 'P')
	{
		d->p_joueur[0] = i;
		d->p_joueur[1] = j;
		p++;
	}
	if (d->map[i][j] == 'C')
	{
		d->nb_c++;
		c++;
	}
	if (i == d->h -1 && j == d->l -1)
	{
		if (e == 0 || p != 1 || c == 0)
		{
			ecrire("Map_Error : element manquant\n");
			exit(1);
		}
	}
}
