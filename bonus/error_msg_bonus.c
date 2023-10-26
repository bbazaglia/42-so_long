/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:05:16 by bbazagli          #+#    #+#             */
/*   Updated: 2023/10/25 16:05:24 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error_msg(char *error, char **matrix, char **new_matrix)
{
	free_matrix(matrix, new_matrix);
	ft_printf("Error: %s.\n", error);
	exit(1);
}