#include "so_long.h"

void	error_msg(char *error, char **matrix)
{
	free_matrix(matrix);
	ft_printf("Error: %s.\n", error);
	exit(1);
}