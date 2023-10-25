/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:32:30 by bbazagli          #+#    #+#             */
/*   Updated: 2023/10/25 10:32:45 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_msg(char *error, char **matrix, char **new_matrix)
{
	free_matrix(matrix, new_matrix);
	ft_printf("Error: %s.\n", error);
	exit(1);
}
