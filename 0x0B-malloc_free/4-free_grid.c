#include "main.h"
/**
 * free_grid - this releases the previously made two dimensional grid
 * @grid: pointer to 2-D grid
 * @height: number of rows
 * Return: nothing, frees memory
 **/
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
		free(grid[i]);
	free(grid);
}
