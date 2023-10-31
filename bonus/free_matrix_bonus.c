/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:10:32 by bbazagli          #+#    #+#             */
/*   Updated: 2023/10/31 11:52:26 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_matrix(t_game *game)
{
	int	i;

	if (game->matrix)
	{
		i = 0;
		while (game->matrix[i] != NULL)
		{
			free(game->matrix[i]);
			i++;
		}
		free(game->matrix);
	}
	if (game->new_matrix)
	{
		i = 0;
		while (game->new_matrix[i] != NULL)
		{
			free(game->new_matrix[i]);
			i++;
		}
		free(game->new_matrix);
	}
}
