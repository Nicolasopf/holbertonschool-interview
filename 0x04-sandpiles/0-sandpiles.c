#include "sandpiles.h"
void print_grid(int grid[3][3]);


/**
 * print_grid - Pretty print of a grid.
 * @grid: grid to print.
 */

void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_perfect_sand - Check if a grid is sandpile.
 * @grid: grid to test.
 * Return: 1 perfect, 0 if not.
 */

int is_perfect_sand(int grid[3][3])
{
	int row, column;

	for (row = 0; row < 3; row++)
		for (column = 0; column < 3; column++)
			if (grid[row][column] > 3)
				return (0);

	return (1);
}

/**
 * sandpiles_sum - get the sum of the sandpiles.
 * @grid1: grid 1 to sum
 * @grid2: grid2 to sum
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int row, column;

	for (row = 0; row < 3; row++)
		for (column = 0; column < 3; column++)
			grid1[row][column] += grid2[row][column];


	while (!is_perfect_sand(grid1))
	{
		print_grid(grid1);
		check_sandpile(grid1);
	}
}


/**
 * check_sandpile - Check a sandpile to convert it to perfect.
 * @grid: grid to check.
 */

void check_sandpile(int grid[3][3])
{
	int row, column, discount = 0, tmp[3][3];

	for (row = 0; row < 3; row++)
		for (column = 0; column < 3; column++)
			tmp[row][column] = grid[row][column];

	for (row = 0; row < 3; row++)
		for (column = 0; column < 3; column++)
		{
			if (grid[row][column] > 3)
			{
				/* UP, if index 0, row-1 would be -1 */
				if (row != 0)
					tmp[row - 1][column] += 1, discount++;
				else
					discount++;

				/* DOWN */
				if (row != 2)
					tmp[row + 1][column] += 1, discount++;
				else
					discount++;

				/* LEFT */
				if (column != 0)
					tmp[row][column - 1] += 1, discount++;
				else
					discount++;

				/* RIGHT */
				if (column != 2)
					tmp[row][column + 1] += 1, discount++;
				else
					discount++;

				tmp[row][column] -= discount;
			}
			discount = 0;
		}

	for (row = 0; row < 3; row++)
		for (column = 0; column < 3; column++)
			grid[row][column] = tmp[row][column];
}
