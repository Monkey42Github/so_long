/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschemit <pschemit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:58:53 by pschemit          #+#    #+#             */
/*   Updated: 2022/06/07 20:27:57 by pschemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	a_w(t_data *d)
{
	if (d->p == 0)
	{
		d->img[4] = mlx_xpm_file_to_image(d->mlx, "p/w.xpm",
				&d->im_w, &d->im_h);
		d->p = 1;
	}
	else
	{
		d->img[4] = mlx_xpm_file_to_image(d->mlx, "p/w1.xpm",
				&d->im_w, &d->im_h);
		d->p = 0;
	}
}

void	a_s(t_data *d)
{
	if (d->p == 0)
	{
		d->img[4] = mlx_xpm_file_to_image(d->mlx, "p/s.xpm",
				&d->im_w, &d->im_h);
		d->p = 1;
	}
	else
	{
		d->img[4] = mlx_xpm_file_to_image(d->mlx, "p/s1.xpm",
				&d->im_w, &d->im_h);
		d->p = 0;
	}
}

void	a_a(t_data *d)
{
	if (d->p == 0)
	{
		d->img[4] = mlx_xpm_file_to_image(d->mlx, "p/a.xpm",
				&d->im_w, &d->im_h);
		d->p = 1;
	}
	else
	{
		d->img[4] = mlx_xpm_file_to_image(d->mlx, "p/a1.xpm",
				&d->im_w, &d->im_h);
		d->p = 0;
	}
}

void	a_d(t_data *d)
{
	if (d->p == 0)
	{
		d->img[4] = mlx_xpm_file_to_image(d->mlx, "p/d.xpm",
				&d->im_w, &d->im_h);
		d->p = 1;
	}
	else
	{
		d->img[4] = mlx_xpm_file_to_image(d->mlx, "p/d1.xpm",
				&d->im_w, &d->im_h);
		d->p = 0;
	}
}

void	mv_ecrire(t_data *d)
{
	char	*str;

	str = ft_itoa(d->nb_move);
	if ((d->nb_move != d->nb_move_1) || (d->nb_move == 0 && d->nb_move_1 == 0))
	{
		ecrire(str);
		ecrire("\n");
		mlx_string_put(d->mlx, d->win, 25, 25, 16777215, str);
	}
	free(str);
	d->nb_move_1 = d->nb_move;
}
