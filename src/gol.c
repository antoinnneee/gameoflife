
#include "../libft/includes/libft.h"
#include "../includes/gameoflife.h"

static int	countalive(char **grid, int x, int y)
{
	int	cnt;

	cnt = 0;
	if (y > 0)
	{
		if (grid[x][y-1] == ISALIVE)
			cnt++;
		if (x > 0)
			if (grid[x-1][y-1] == ISALIVE)
				cnt++;
		if (x < SIZE)
		{
			if (grid[x+1][y-1] == ISALIVE)
				cnt++;
			if (grid[x+1][y] == ISALIVE)		
				cnt++;
		}

	}
	if (y < SIZE)
	{
		if (grid[x][y+1] == ISALIVE)
			cnt++;
		if (x > 0)
		{
			if (grid[x-1][y] == ISALIVE)
				cnt++;
			if (grid[x-1][y+1] == ISALIVE)
				cnt++;
		}
		if (x < SIZE)
			if (grid[x+1][y+1] == ISALIVE)
				cnt++;
	}
	return (cnt);
}	

void		gol_process(char **grid, int x, int y)
{
	
	if(grid[x][y] != ISALIVE)
		dead_cell(grid, x, y, countalive(grid, x, y));
	else
		alive_cell(grid, x, y, countalive(grid, x, y));
}

void		alive_cell(char **grid, int x, int y, int alivenbr)
{
	if (alivenbr == 2 || alivenbr == 3)
	{
		;
	}
	else
		grid[x][y] = '0';
}

void		dead_cell(char **grid, int x, int y, int alivenbr)
{
	if (alivenbr == 3)
	{
		grid[x][y] = '1';
	}
	else
		grid[x][y] = '0';
}
