/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 08:06:15 by rvalton           #+#    #+#             */
/*   Updated: 2021/04/05 11:15:31 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ft_len_clst_wall(t_all *vars, int i)
{
	double	x;
	double	y;
	float	fov;
	float	a;
	float	cosbeta;

	y = ft_new_hor_inte(vars, &vars->ray, i);
	x = ft_new_ver_inte(vars, &vars->ray, i);
	fov = ft_dir_to_fov(vars->cam.dir);
	if (fov > vars->ray.a)
		a = fov - vars->ray.a;
	else
		a = vars->ray.a - fov;
	cosbeta = cos(a);
	if (cosbeta < 0)
		cosbeta *= -1;
	if (x >= y)
	{

		if (vars->ray.a > 0 && vars->ray.a < M_PI)
			vars->wallface[i] = 3;
		else
			vars->wallface[i] = 0;
		return (ft_new_hor_inte(vars, &vars->ray, i) * cosbeta);
	}
	else
	{
		if (vars->ray.a < M_PI / 2 || vars->ray.a > 3 * M_PI / 2)
			vars->wallface[i] = 2;
		else
			vars->wallface[i] = 1;
		return (ft_new_ver_inte(vars, &vars->ray, i) * cosbeta);
	}
}

void	ft_find_walls(t_all *vars, double *wall)
{
	int	i;
	float	a;
	float	fov;

	a = (M_PI / 3) / vars->rsl.w;
	fov = ft_dir_to_fov(vars->cam.dir);
	printf("fov = %f \n", fov);
	i = 0;
	while (i < vars->rsl.w)
	{
		vars->ray.a = fov + M_PI / 6 - i * a;
		wall[i] = ft_len_clst_wall(vars, i);
		i++;
	}
	printf("before unif walls \n");
	ft_unif_walls(wall, i);
}
