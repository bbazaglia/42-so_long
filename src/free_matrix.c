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