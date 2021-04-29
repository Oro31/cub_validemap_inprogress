/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 07:46:41 by rvalton           #+#    #+#             */
/*   Updated: 2021/04/06 08:42:09 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main()
{
	int	fd;
	char	*line;
	t_all	vars;
	int	i;

	printf("start \n");
	if (!(ft_init_before_parse(&vars)))
		return (0);
	if (!(fd = open("map.cub", O_RDONLY)))
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		printf("gnl running /\n");
		ft_parse_line(ft_check_line(line), &vars, line);
	}
	close(fd);
	if (!(ft_ismap_walled(vars.map.box)))
	{
		printf("map is not walled ?!!!! \n");
		return (0);
	}
	ft_replace_mapspace(vars.map.box);
	printf("map is walled !");
	i = 0;
	while (vars.spr.path[i])
	{
		printf("texpath[%d] = %s \n", i, vars.spr.path[i]);
		i++;
	}
	i = 0;
	while(vars.map.box[i])
	{
		printf("map[%d] = %s \n", i , vars.map.box[i]);
		i++;
	}
	printf("len max map : %d \n", ft_lenmax_mpline(vars.map.box));
	if (!(ft_init_after_parse(&vars)))
		return (0);
	printf("before fill sprites \n");
	ft_fill_sprites(&vars);
	vars.ground.color = ft_rgbtocolor(&vars.ground);
	vars.sky.color = ft_rgbtocolor(&vars.sky);
	ft_define_rslwin(&vars);
	vars.cam.dir = ft_define_cam(&vars);
	/*if (ft_draw(&vars) == 0)
		return (0);*/
	ft_draw(&vars);
	printf("before exit \n");
	/*ft_exit(&vars);*/
	printf("after exit \n");
	mlx_hook(vars.win, 2, 1L<<0, ft_moove_kyhk, &vars);
	/*if (ft_draw(&vars) == 0)
		return (0);*/
	ft_draw(&vars);
	mlx_loop(vars.mlx);
	return (0);
}
