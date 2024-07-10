/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschemit <pschemit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:00:42 by pschemit          #+#    #+#             */
/*   Updated: 2022/06/07 20:33:39 by pschemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_w(t_data *d)
{
	a_w(d);
	if ((d->p_joueur[0] != 0 \
		&& d->map[d->p_joueur[0] - 1][d->p_joueur[1]] != '1' \
		&& d->map[d->p_joueur[0] - 1][d->p_joueur[1]] != 'E') \
		|| (d->map[d->p_joueur[0] - 1][d->p_joueur[1]] == 'E'
		&& d->nb_c == 0))
	{
		d->map[d->p_joueur[0]][d->p_joueur[1]] = '0';
		refresh_map(d, d->p_joueur[0], d->p_joueur[1]);
		if (d->map[d->p_joueur[0] -1][d->p_joueur[1]] == 'C')
			d->nb_c--;
		if (d->map[d->p_joueur[0] -1][d->p_joueur[1]] == 'E')
			exit(0);
		d->p_joueur[0]--;
		d->nb_move++;
		d->map[d->p_joueur[0]][d->p_joueur[1]] = 'P';
		refresh_map(d, d->p_joueur[0], d->p_joueur[1]);
	}
}

void	key_s(t_data *d)
{
	a_s(d);
	if ((d->p_joueur[0] != d->h -1 \
		&& d->map[d->p_joueur[0] +1][d->p_joueur[1]] != '1' \
		&& d->map[d->p_joueur[0] +1][d->p_joueur[1]] != 'E') \
		|| (d->map[d->p_joueur[0] +1][d->p_joueur[1]] == 'E' \
		&& d->nb_c == 0))
	{
		d->map[d->p_joueur[0]][d->p_joueur[1]] = '0';
		refresh_map(d, d->p_joueur[0], d->p_joueur[1]);
		if (d->map[d->p_joueur[0] +1][d->p_joueur[1]] == 'C')
			d->nb_c--;
		if (d->map[d->p_joueur[0] +1][d->p_joueur[1]] == 'E')
			exit(0);
		d->p_joueur[0]++;
		d->nb_move++;
		d->map[d->p_joueur[0]][d->p_joueur[1]] = 'P';
		refresh_map(d, d->p_joueur[0], d->p_joueur[1]);
	}
}

void	key_a(t_data *d)
{
	a_a(d);
	if ((d->p_joueur[1] != 0 \
		&& d->map[d->p_joueur[0]][d->p_joueur[1] -1] != '1' \
		&& d->map[d->p_joueur[0]][d->p_joueur[1] -1] != 'E') \
		|| (d->map[d->p_joueur[0]][d->p_joueur[1] -1] == 'E' \
		&& d->nb_c == 0))
	{
		d->map[d->p_joueur[0]][d->p_joueur[1]] = '0';
		refresh_map(d, d->p_joueur[0], d->p_joueur[1]);
		if (d->map[d->p_joueur[0]][d->p_joueur[1] -1] == 'C')
			d->nb_c--;
		if (d->map[d->p_joueur[0]][d->p_joueur[1] -1] == 'E')
			exit(0);
		d->p_joueur[1]--;
		d->nb_move++;
		d->map[d->p_joueur[0]][d->p_joueur[1]] = 'P';
		refresh_map(d, d->p_joueur[0], d->p_joueur[1]);
	}
}

void	key_d(t_data *d)
{
	a_d(d);
	if ((d->p_joueur[1] != d->l -1 \
		&& d->map[d->p_joueur[0]][d->p_joueur[1] +1] != '1' \
		&& d->map[d->p_joueur[0]][d->p_joueur[1] +1] != 'E') \
		|| (d->map[d->p_joueur[0]][d->p_joueur[1] +1] == 'E' \
		&& d->nb_c == 0))
	{
		d->map[d->p_joueur[0]][d->p_joueur[1]] = '0';
		refresh_map(d, d->p_joueur[0], d->p_joueur[1]);
		if (d->map[d->p_joueur[0]][d->p_joueur[1] +1] == 'C')
			d->nb_c--;
		if (d->map[d->p_joueur[0]][d->p_joueur[1] +1] == 'E')
			exit(0);
		d->p_joueur[1] += 1;
		d->nb_move++;
		d->map[d->p_joueur[0]][d->p_joueur[1]] = 'P';
		refresh_map(d, d->p_joueur[0], d->p_joueur[1]);
	}
}
