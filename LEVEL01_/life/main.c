#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	if (ac != 4)
		return 0;
	int 	width = atoi(av[1]);
	int		height = atoi(av[2]);
	int		iterations = atoi(av[3]);

	char **board = malloc((height + 1) * sizeof(char *));
	if (board == NULL)
		return 0;
	int i = 0;
	while (i < height)
	{
		board[i] = malloc((width + 1) * sizeof(char));
		if (board[i] == NULL)
		{
			i--;
			while (i >= 0)
			{
				free(board[i]);
				i--;
			}
			free(board);
			return 0;
		}
		int j = 0;
		while (j < width)
		{
			board[i][j] = ' ';
			j++;
		}
		i++;
	}
	char c;
	ssize_t bread = read(STDIN_FILENO, &c, 1);
	int x = 0;
	int y = 0;
	int pen_down = 0;
	while (bread > 0)
	{
		if (c == 'x')
		{
			if (pen_down == 0)
				pen_down = 1;
			else
				pen_down = 0;
		}
		else if (c == 'w')
			x--;
		else if (c == 'a')
			y--;
		else if (c == 's')
			x++;
		else if (c == 'd')
			y++;
		if (pen_down == 1 && y >= 0 && y < width && x >= 0 && x < height)
			board[x][y] = 'O';
		bread = read(STDIN_FILENO, &c, 1);
	}
	i = 0;
	char **tmp = malloc((height + 1) * sizeof(char *));
	if (tmp == NULL)
		return 0;
	i = 0;
	while (i < height)
	{
		tmp[i] = malloc((width + 1) * sizeof(char));
		if (tmp[i] == NULL)
		{
			i--;
			while (i >= 0)
			{
				free(tmp[i]);
				i--;
			}
			free(tmp);
			i = 0;
			while (i < height)
			{
				free(board[i]);
				i++;
			}
			free(board);
			return 0;
		}
		i++;
	}
	int count;
	i = 0;
	while (i < iterations)
	{
		x = 0;
		while (x < height)
		{
			y = 0;
			while (y < width)
			{
				count = 0;
				if (y - 1 >= 0 && board[x][y - 1] == 'O')
					count++;
				if (y + 1 < width && board[x][y + 1] == 'O')
					count++;
				if (x - 1 >= 0 && board[x - 1][y] == 'O')
					count++;
				if (x + 1 < height && board[x + 1][y] == 'O')
					count++;
				if (y - 1 >= 0 && x - 1 >= 0 && board[x - 1][y - 1] == 'O')
					count++;
				if (y + 1 < width && x + 1 < height && board[x + 1][y + 1] == 'O')
					count++;
				if (x - 1 >= 0 && y + 1 < width && board[x - 1][y + 1] == 'O')
					count++;
				if (x + 1 < height && y - 1 >= 0 && board[x + 1][y - 1] == 'O')
					count++;
				if ((board[x][y] == 'O' && (count == 2 || count == 3)) || (board[x][y] == ' ' && count == 3))
					tmp[x][y] = 'O';
				else
					tmp[x][y] = ' ';
				y++;
			}
			x++;
		}
		char **a = tmp;
		tmp = board;
		board = a;
		i++;
	}
	i = 0;
	while (i < height)
	{
		int j = 0;
		while (j < width)
		{
			putchar(board[i][j]);
			j++;
		}
		putchar('\n');
		i++;
	}
	i = 0;
	while (i < height)
			{
				free(board[i]);
				i++;
			}
			free(board);

	i = 0;
	while (i < height)
			{
				free(tmp[i]);
				i++;
			}
			free(tmp);
	return 0;
}