/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_matrix_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:13:05 by bbazagli          #+#    #+#             */
/*   Updated: 2023/10/31 13:48:20 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	get_num_lines(char *argv)
{
	int		fd;
	char	*line;
	int		num_lines;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: Error opening file\n");
		exit(1);
	}
	num_lines = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		num_lines++;
		free(line);
	}
	close(fd);
	return (num_lines);
}

char	**populate_matrix(char *argv, t_game *game)
{
	int		fd;
	int		i;
	int		len;

	game->matrix = malloc(sizeof(char *) * (game->num_lines + 1));
	if (game->matrix == NULL)
		error_msg("Memory allocation failed", game);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error_msg("Failed to open file", game);
	i = 0;
	while (i < game->num_lines)
	{
		game->matrix[i] = get_next_line(fd);
		if (game->matrix[i] == NULL)
			error_msg("Failed to read matrix line", game);
		len = ft_strlen(game->matrix[i]);
		if (game->matrix[i][len - 1] == '\n')
			game->matrix[i][len - 1] = '\0';
		i++;
	}
	game->matrix[i] = NULL;
	close(fd);
	return (game->matrix);
}

char	**copy_matrix(t_game *game)
{
	int		i;

	game->new_matrix = malloc(sizeof(char *) * (game->num_lines + 1));
	if (game->new_matrix == NULL)
		error_msg("Memory allocation failed", game);
	i = 0;
	while (game->matrix[i])
	{
		game->new_matrix[i] = ft_strdup(game->matrix[i]);
		if (game->new_matrix[i] == NULL)
			error_msg("Memory allocation failed", game);
		i++;
	}
	game->new_matrix[i] = NULL;
	return (game->new_matrix);
}

void	initialize_game(t_game *game)
{
	game->exit_reached = 0;
	game->player = 0;
	game->exit = 0;
	game->collectibles = 0;
	game->collected = 0;
	game->space = 0;
	game->wall = 0;
	game->error = 0;
	game->move_count = 0;
}
