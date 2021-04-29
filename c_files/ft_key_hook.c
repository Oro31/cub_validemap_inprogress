/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 07:52:23 by rvalton           #+#    #+#             */
/*   Updated: 2021/04/08 10:46:44 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_close(t_all *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
}

void	ft_turn(t_all *vars, char c)
{
	float	fov;
	float	tmp;

	fov = ft_dir_to_fov(vars->cam.dir);
	if (c == 'l')
		tmp = fov + M_PI / 2;
	else
		tmp = fov - M_PI / 2;
	while (tmp > 2 * M_PI)
		tmp -= 2 * M_PI;
	while (tmp < 0)
		tmp += 2 * M_PI;
	printf("ft_turn tmp = %f \n", tmp);
	vars->cam.dir = ft_fov_to_dir(tmp);
}

void	ft_moove(t_all *vars, char c)
{
	vars->map.box[vars->cam.pos.y][vars->cam.pos.x] = '0';
	if (c == 'w')
		ft_avancer(vars);
	else if (c == 's')
		ft_reculer(vars);
	else if (c == 'a')
		ft_lateral_gauche(vars);
	else if (c == 'd')
		ft_lateral_droite(vars);
	vars->map.box[vars->cam.pos.y][vars->cam.pos.x] = vars->cam.dir;
}

int	ft_moove_kyhk(int keycode, t_all *vars)
{
	printf("keycode = %d \n", keycode);
	if (keycode == 65307)
		ft_close(vars);
	else if (keycode == 65361)
		ft_turn(vars, 'l');
	else if (keycode == 65363)
		ft_turn(vars, 'r');
	else if (keycode == 119) /*may be 122 with azerty*/
		ft_moove(vars, 'w');
	else if (keycode == 115)
		ft_moove(vars, 's');
	else if (keycode == 97) /*may be 113 with azerty*/
		ft_moove(vars, 'a');
	else if (keycode == 100)
		ft_moove(vars, 'd');
/*	if (ft_draw(vars) == 0)
	{
		printf("dir = %c \n", vars->cam.dir);
		return (0);
	}*/
	printf("cam.dir = %c \n", vars->cam.dir);
	printf("pos : %d, %d \n", vars->cam.pos.x, vars->cam.pos.y);
	ft_draw(vars);
	return (1);
}
