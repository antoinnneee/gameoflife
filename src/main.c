#include "../includes/gameoflife.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>


char **m_tab(int size)
{
	char	**tab;
	int	i;
	int	j;

	i = 0;
	j = 0;
	tab = (char**) ft_memalloc(sizeof(char*) * size);
	while (i < size)
	{
		tab[i] = (char*) ft_memalloc(sizeof(char) * size);
		while (j < size)	
		{
			tab[i][j] = '0';
			if (j%4 != 0)
			tab[i][j] = '1';
				
			j++;
		}
		j = 0;
		i++;
	}
	return (tab);
}
//			if (grid[i][j] == ISALIVE)
void	printgrid(char **grid, int x, int y)
{
	if (x == 0)
		ft_putchar('\n');
	ft_putchar(grid[x][y]);
}

void	processing(char **grid, void(*pfunc)(char **grid, int x, int y))
{
	int	i;
	int	j;

	ft_inittwovar(&i, &j);
	while (i < SIZE + 1)
	{
		while (j < SIZE + 1)
		{
			pfunc(grid, j, i);
			j++;
		}
	i++;
	j = 0;
	}
}

void	printtab(char **grid)
{
	int	i;

	i = 0;

	while (i++ < SIZE)
		ft_putchar('_');
	ft_putchar('\n');
	i = 0;
	while (i < SIZE)
	{
		ft_putendl(grid[i]);
		i++;
	}
	i = 0;
	while (i++ < SIZE)
		ft_putchar(96);

}

int main(void)
{
	char	**grid;
	int	pid;

	grid = m_tab(SIZE + 1);
	while (1)
	{
		usleep(10000);
   		system("clear");
		processing(grid, &printgrid);
		ft_putchar('\n');
		processing(grid, &gol_process);
	}
//	printtab(grid);
	return (0);
}
