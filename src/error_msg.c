#include "so_long.h"

void	error_msg(char *error, char **matrix, char **new_matrix)
{
	free_matrix(matrix, new_matrix);
	ft_printf("Error: %s.\n", error);
	exit(1);
}