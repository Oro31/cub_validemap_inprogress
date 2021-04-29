/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 07:52:23 by rvalton           #+#    #+#             */
/*   Updated: 2021/04/08 10:46:44 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_is_notwall(t_all *vars, char c, int s)
{
	int	x;
	int	y;

	x = vars->cam.pos.x;
	y = vars->cam.pos.y;
	if (c == 'y')
		y += s;
	else
		x += s;
	if (vars->map.box[y][x] != '0')
		return (0);
	else
		return (1);
}

void	ft_avancer(t_all *vars)
{
	if (vars->cam.dir == 'N')
	{
		if (ft_is_notwall(vars, 'y', -1))
			vars->cam.pos.y -= 1;
	}
	else if (vars->cam.dir == 'S')
	{
		if (ft_is_notwall(vars, 'y', 1))
			vars->cam.pos.y += 1;
	}
	else if (vars->cam.dir == 'W')
	{
		if (ft_is_notwall(vars, 'x', -1))
			vars->cam.pos.x -= 1;
	}
	else if (vars->cam.dir == 'E')
	{
		if (ft_is_notwall(vars, 'x', 1))
			vars->cam.pos.x += 1;
	}
}

void	ft_reculer(t_all *vars)
{
	if (vars->cam.dir == 'N')
	{
		if (ft_is_notwall(vars, 'y', 1))
			vars->cam.pos.y += 1;
	}
	else if (vars->cam.dir == 'S')
	{
		if (ft_is_notwall(vars, 'y', -1))
			vars->cam.pos.y -= 1;
	}
	else if (vars->cam.dir == 'W')
	{
		if (ft_is_notwall(vars, 'x', 1))
			vars->cam.pos.x += 1;
	}
	else if (vars->cam.dir == 'E')
	{
		if (ft_is_notwall(vars, 'x', -1))
			vars->cam.pos.x -= 1;
	}
}

void	ft_lateral_gauche(t_all *vars)
{
	if (vars->cam.dir == 'N')
	{
		if (ft_is_notwall(vars, 'x', -1))
			vars->cam.pos.x -= 1;
	}
	else if (vars->cam.dir == 'S')
	{	
		if (ft_is_notwall(vars, 'x', 1))
			vars->cam.pos.x += 1;
	}
	else if (vars->cam.dir == 'W')
	{
		if (ft_is_notwall(vars, 'y', 1))
			vars->cam.pos.y += 1;
	}
	else if (vars->cam.dir == 'E')
	{
		if (ft_is_notwall(vars, 'y', -1))
			vars->cam.pos.y -= 1;
	}
}

void	ft_lateral_droite(t_all *vars)
{
	if (vars->cam.dir == 'N')
	{
		if (ft_is_notwall(vars, 'x', 1))
			vars->cam.pos.x += 1;
	}
	else if (vars->cam.dir == 'S')
	{
		if (ft_is_notwall(vars, 'x', -1))
			vars->cam.pos.x -= 1;
	}
	else if (vars->cam.dir == 'W')
	{
		if (ft_is_notwall(vars, 'y', -1))
			vars->cam.pos.y -= 1;
	}
	else if (vars->cam.dir == 'E')
	{
		if (ft_is_notwall(vars, 'y', 1))
			vars->cam.pos.y += 1;
	}
}
