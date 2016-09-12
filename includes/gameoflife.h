
#ifndef	GAMEOFLIFE_H_
# define GAMEOFLIFE_H_
# define SIZE 42
# define ISALIVE 49

char	**m_tab(int size);
void	printtab(char **grid);
void	processing(char **grid, void (*pfunc)(char**, int, int));
void	printgrid(char **grid, int x, int y);
void	dead_cell(char **grid, int x, int y, int alivenbr);
void	alive_cell(char **grid, int x, int y, int alivenbr);
void	gol_process(char **grid, int x, int y);
#endif
