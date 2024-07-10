/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschemit <pschemit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:20:20 by pschemit          #+#    #+#             */
/*   Updated: 2022/06/08 11:42:02 by pschemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	touche(int key, t_data	*d)
{
	if (key == K_W)
		key_w(d);
	if (key == K_S)
		key_s(d);
	if (key == K_A)
		key_a(d);
	if (key == K_D)
		key_d(d);
	if (key == ESC)
		exit(0);
	if (d->nb_move != d->nb_move_1)
		mv_ecrire(d);
	return (0);
}

void	affichage(t_data *d)
{
	d->nb_move_1 = -1;
	d->nb_move = 0;
	d->p = 0;
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, d->l * 50, d->h * 50, "so_long");
	d->img[0] = mlx_xpm_file_to_image(d->mlx, "i/img1.xpm", &d->im_w, &d->im_h);
	d->img[1] = mlx_xpm_file_to_image(d->mlx, "i/img2.xpm", &d->im_w, &d->im_h);
	d->img[2] = mlx_xpm_file_to_image(d->mlx, "i/img3.xpm", &d->im_w, &d->im_h);
	d->img[3] = mlx_xpm_file_to_image(d->mlx, "i/poke.xpm", &d->im_w, &d->im_h);
	d->img[4] = mlx_xpm_file_to_image(d->mlx, "p/s.xpm", &d->im_w, &d->im_h);
	affichage_map(d);
	mv_ecrire(d);
	mlx_hook(d->win, 2, 0, touche, d);
	mlx_hook(d->win, 17, 0, ft_destroy, NULL);
	mlx_loop(d->mlx);
}

int	refresh_map(t_data *d, int i, int j)
{
	const char	str[6] = "10ECP";
	int			k;

	mlx_put_image_to_window(d->mlx, d->win, d->img[0],
		0, 0);
	mlx_put_image_to_window(d->mlx, d->win, d->img[0],
		50, 0);
	k = 0;
	while (k < 5)
	{
		if (d->map[i][j] == str[k])
		{
			mlx_put_image_to_window(d->mlx, d->win, d->img[k],
				50 * j, 50 * i);
		}
		k++;
	}
	return (0);
}

int	affichage_map(t_data *d)
{
	int			i;
	int			j;

	i = 0;
	while (i != d->h)
	{
		j = 0;
		while (j != d->l)
		{
			refresh_map(d, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	d;
	int		i;

	(void)ac;
	i = 0;
	parce_ber(av);
	d.map = read_map_file(av[1], &d);
	parcing(&d);
	affichage(&d);
	while (d.map[i])
	{
		free(d.map[i]);
		i++;
	}
	free(d.map);
	system("leaks a.out");
	return (0);
}
