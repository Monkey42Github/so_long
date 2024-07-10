/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschemit <pschemit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:09:54 by pschemit          #+#    #+#             */
/*   Updated: 2022/06/07 20:09:18 by pschemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define ESC				53
# define K_W				13
# define K_A				0
# define K_S				1
# define K_D				2
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_d
{
	int		h;
	int		l;
	char	**map;
	void	*img[5];

	void	*mlx;
	void	*win;

	int		p_joueur[2];
	int		nb_c;
	int		nb_move;
	int		nb_move_1;
	int		im_w;
	int		im_h;
	int		p;
}	t_data;

char	*ft_itoa(int nb);
int		ft_len(long nb);
int		ft_strchr(char *s, int c);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
//gnl
char	*get_next_line(int fd);
char	*ft_stat(char *stati);
char	*line(char *stati);
char	*verfi(char	*buffer, int fd, char *stati);
void	ecrire(char *str);

char	**read_map_file(char *file, t_data	*data);
char	**malloc_case(char *file);
int		file_linecount(char *file);
char	**malloc_map(char *file, t_data	*data);
//Parcing
void	parce_ber(char **av);
void	parcing(t_data	*data);
int		parcing_2(t_data	*data);
void	parce_bord(t_data	*data, int i, int j);
void	parce_ecp(t_data	*data, int i, int j);
void	parce_autre_char(t_data	*data, int i, int j);

void	taille_ligne(t_data	*data);
void	taille_hauteur(t_data	*data);
//so long
void	affichage(t_data *data);
int		affichage_map(t_data *data);
int		refresh_map(t_data *data, int i, int j);
int		touche(int key, t_data *data);

void	key_w(t_data *d);
void	key_s(t_data *d);
void	key_a(t_data *d);
void	key_d(t_data *d);

void	a_w(t_data *d);
void	a_s(t_data *d);
void	a_a(t_data *d);
void	a_d(t_data *d);

int		ft_destroy(void);
void	mv_ecrire(t_data *d);

#endif