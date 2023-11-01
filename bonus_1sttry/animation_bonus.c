/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:32:58 by bbazagli          #+#    #+#             */
/*   Updated: 2023/11/01 15:48:40 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw(t_game *game)
{
	static int	i;
	static int	j;

	(void)game;
	// int	x;
	// int	y;
	if (j == 50)
	{
		//ft_printf("animation is %i\n", i);
		mlx_image_to_window(game->mlx, game->flower[i], 128, 128);
		if (i == 3)
			i = -1;
		i++;
		j = 0;
	}
	j++;
// 	x = 0;
// 	while (game->matrix[x])
// 	{
// 		ft_printf("%i\n", x);
// 		y = 0;
// 		// while (game->matrix[x][y])
// 		// {
// 		// 	if (game->matrix[x][y] == 'C')
// 		// 	{
// 		// 		i = 0;
// 		// 		ft_printf("%d\n%d\n", y * PIXELS, x * PIXELS);
// 		// 		// while (i < game->collected)
// 		// 		// {
// 		// 		// 	// mlx_image_to_window(game->mlx, game->flower[i], y * PIXELS, x * PIXELS);
// 		// 		// 	i++;
// 		// 		// }
// 		// 	}
// 		// 	y++;
// 		// }
// 		x++;
//     }
}

// void	draw(t_game *game)
// {
// 	static int	i;
// 	static int	active_flower;

//     i = 0;
//     active_flower = 1;

//     if (!game->flower[0]->instances[i].enabled
//         && !game->flower[1]->instances[i].enabled
//         && !game->flower[2]->instances[i].enabled
//         && !game->flower[3]->instances[i].enabled)
//         active_flower = 1;
//     else
//     {
//         set_active_flower(game, i, active_flower);
//         active_flower = (active_flower % 4) + 1;
//     }
//     i++;
    
// }

void	animation_wrapper(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	draw(game);
}

void	set_active_flower(t_game *game, int i, int active_flower)
{
	disable_instances(game, i);
	if (active_flower == 1)
		game->flower[0]->instances[i].enabled = true;
	else if (active_flower == 2)
		game->flower[1]->instances[i].enabled = true;
	else if (active_flower == 3)
		game->flower[2]->instances[i].enabled = true;
	else if (active_flower == 4)
		game->flower[3]->instances[i].enabled = true;
}

// // // doesnt use time
// void	flower_animation(t_game *game, int i)
// {
// 	static int	active_flower;

// 	active_flower = 1;
// 	// if (!game->flower1->instances[i].enabled
// 	// 	&& !game->flower2->instances[i].enabled
// 	// 	&& !game->flower3->instances[i].enabled
// 	// 	&& !game->flower4->instances[i].enabled)
// 	// 	active_flower = 1;
// 	// else
// 	// {
// 	set_active_flower(game, i, active_flower);
// 	active_flower = (active_flower % 4) + 1;
// 	// }
// }

// try to set the shift according to the time
// void	flower_animation(t_game *game, int i)
// {
// 	static double	animation_speed;
// 	static clock_t	last_shift;
// 	clock_t			current_time;
// 	double			elapsed_time;
// 	static int		active_flower;
// 	int				j;

// 	animation_speed = 0.2;
// 	last_shift = 0;
// 	active_flower = 1;
// 	current_time = clock();
// 	elapsed_time = (double)(current_time - last_shift) / CLOCKS_PER_SEC;
// 	if (elapsed_time >= animation_speed)
// 	{
// 		j = 0;
// 		while (j < game->collected)
// 		{
// 			if (!game->flower[j]->instances[i].enabled
// 				&& !game->flower[j]->instances[i].enabled
// 				&& !game->flower[j]->instances[i].enabled
// 				&& !game->flower[j]->instances[i].enabled)
// 				active_flower = 1;
// 			else
// 			{
// 				set_active_flower(game, i, active_flower);
// 				active_flower = (active_flower % 4) + 1;
// 			}
// 			j++;
// 		}
// 		last_shift = current_time;
// 	}
// }

// void flower_animation(t_game *game, int i)
// {
//     static double animation_speed;
//     static clock_t last_shift;
//     clock_t current_time;
//     double elapsed_time;
//     static int active_flower;

//     animation_speed = 0.2;
//     last_shift = 0;
//     active_flower = 1;
//     current_time = clock();
//     elapsed_time = (double)(current_time - last_shift) / CLOCKS_PER_SEC;
//     if (elapsed_time >= animation_speed)
//     {
//         if (!game->flower1->instances[i].enabled
//             && !game->flower2->instances[i].enabled
//             && !game->flower3->instances[i].enabled
//             && !game->flower4->instances[i].enabled)
//             active_flower = 1;
//         else
//         {
//             set_active_flower(game, i, active_flower);
//             if (game->flower1->instances[i].enabled == true
//                 || game->flower2->instances[i].enabled == true
//                 || game->flower3->instances[i].enabled == true
//                 || game->flower4->instances[i].enabled == true)
//                 active_flower = (active_flower % 4) + 1;
//         }
//         last_shift = current_time;
//     }
// }

// void	animation_wrapper(void *param)
// {
// 	t_game	*game;

// 	game = (t_game *)param;
// 	flower_animation(game);
// }

// the i increment will be different from the i increment in collectflowers function,
//so it wont work
// void	flower_animation(t_game *game)
// {
// 	static double	animation_speed;
// 	clock_t			last_shift;
// 	clock_t			current_time;
// 	double			elapsed_time;
// 	int				active_flower;
// 	int				i;

// 	animation_speed = 0.2;
// 	last_shift = 0;
// 	active_flower = 1;
// 	current_time = clock();
// 	elapsed_time = (double)(current_time - last_shift) / CLOCKS_PER_SEC;
// 	i = 0;
// 	while (i < game->collected)
// 	{
// 		if (elapsed_time >= animation_speed)
// 		{
// 			if (!game->flower1->instances[i].enabled
// 				&& !game->flower2->instances[i].enabled
// 				&& !game->flower3->instances[i].enabled
// 				&& !game->flower4->instances[i].enabled)
// 				active_flower = 1;
// 			else
// 			{
// 				set_active_flower(game, i, active_flower);
// 				active_flower = (active_flower % 4) + 1;
// 			}
// 			last_shift = current_time;
// 			i++;
// 		}
// 	}
// }

// void	flower_animation(t_game *game)
// {
// 	static double animation_speed;
// 	clock_t last_shift;
// 	clock_t current_time;
// 	double elapsed_time;
// 	int i;
// 	int active_flower;

// 	animation_speed = 0.2;
// 	last_shift = 0;
// 	current_time = clock();
// 	elapsed_time = (double)(current_time - last_shift) / CLOCKS_PER_SEC;
// 	i = 0;
// 	if (elapsed_time >= animation_speed)
// 	{
// 		active_flower = 1;
// 		while (i < game->collected)
// 		{
// 			if (!game->flower1->instances[i].enabled &&
// 				!game->flower2->instances[i].enabled &&
// 				!game->flower3->instances[i].enabled &&
// 				!game->flower4->instances[i].enabled)
// 			{
// 				active_flower = 1;
// 			}
// 			else
// 			{
// 				set_active_flower(game, i, active_flower);
// 				active_flower = (active_flower % 4) + 1;
// 			}
// 			i++;
// 		}
// 		last_shift = current_time;
// 	}
// }