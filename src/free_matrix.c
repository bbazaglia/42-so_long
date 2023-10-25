/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:33:21 by bbazagli          #+#    #+#             */
/*   Updated: 2023/10/25 10:33:42 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_matrix(char **matrix, char **new_matrix)
{
	int	i;

	if (matrix)
	{
		i = 0;
		while (matrix[i] != NULL)
		{
			free(matrix[i]);
			i++;
		}
		free(matrix);
	}
	if (new_matrix)
	{
		i = 0;
		while (new_matrix[i] != NULL)
		{
			free(new_matrix[i]);
			i++;
		}
		free(new_matrix);
	}
}
