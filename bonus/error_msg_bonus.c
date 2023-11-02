/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:05:16 by bbazagli          #+#    #+#             */
/*   Updated: 2023/11/02 13:53:50 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error_msg(char *error, t_game *game)
{
	free_matrix(game);
	ft_printf("Error: %s.\n", error);
	exit(1);
}
