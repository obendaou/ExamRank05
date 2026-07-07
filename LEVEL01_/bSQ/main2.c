#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


struct data 
{
	char empty;
	char obstacle;
	char full;
	int lines;
	int line_len;
	char **map;
	int max;
	int max_x;
	int max_y;
};

int min3(int a, int b, int c)
{
	if (a <= b && a <= c)
		return a;
	if (b <= a && b <= c)
		return b;
	else
		return c;
}

void dp(struct data *d)
{
	int **Dp = malloc(sizeof(int *) * d->lines);
	int i = 0;
	d->max = -1;
	d->max_x = -1;
	d->max_y = -1;
	while (i < d->lines)
	{
		Dp[i] = malloc(sizeof(int) * d->line_len);
		int j = 0;
		while (j < d->line_len)
		{
			if (d->map[i][j] == d->obstacle)
				Dp[i][j] = 0;
			else
			{
				int up = 0, left = 0, left_up = 0;
				if (i > 0)
					up = Dp[i - 1][j];
				if (j > 0)
					left = Dp[i][j - 1];
				if (j > 0 && i > 0)
					left_up = Dp[i - 1][j - 1];
				Dp[i][j] = min3(left, up, left_up) + 1;
				if (Dp[i][j] > d->max)
				{
					d->max = Dp[i][j];
					d->max_x = i;
					d->max_y = j;
				}
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < d->lines)
	{
		free(Dp[i]);
		i++;
	}
	free(Dp);
}

void draw(struct data *d)
{
	if (d->max != -1)
	{
		int i = d->max_x - d->max + 1;
		while (i <= d->max_x)
		{
			int j = d->max_y - d->max + 1;
			while (j <= d->max_y)
			{
				d->map[i][j] = d->full;
				j++;
			}
			i++;
		}
	}
	int i = 0;
	while (i < d->lines)
	{
		fprintf(stdout, "%s\n", d->map[i]);
		free(d->map[i]);
		i++;
	}
	free(d->map);
}

int parse(FILE *f, struct data *d)
{
	char *line = NULL;
	size_t size = 0;
	ssize_t read = getline(&line, &size, f);
	if (read < 5 || line[read - 1] != '\n')
	{
		if (line)
			free(line);
		return 0;
	}
	d->full = line[read - 2];
	d->obstacle = line[read - 3];
	d->empty = line[read - 4];
	if (d->full == d->obstacle || d->full == d->empty || d->obstacle == d->empty)
	{
		free(line);
		return 0;
	}
	line[read - 4] = 0;
	d->lines = 0;
	int i = 0;
	while (line[i])
	{
		if (line[i] < '0' || line[i] > '9')
			break;
		d->lines = d->lines * 10 + (line[i] - '0');
		i++;
	}
	if (line[i] || d->lines == 0)
	{
		free(line);
		return 0;
	}
	i = 0;
	d->line_len = -1;
	d->map = malloc(sizeof(char *) * (d->lines + 1));
	while (i < d->lines)
	{
		ssize_t read = getline(&line, &size, f);
		if (read == -1)
			break;
		
		if (d->line_len == -1)
			d->line_len = read - 1;
		if (d->line_len != (int)read - 1 || line[read - 1] != '\n' || d->line_len < 1)
		{
			i--;
			while (i >= 0)
			{
				free(d->map[i]);
				i--;
			}
			free(d->map);
			free(line);
			return 0;
		}
		d->map[i] = malloc(sizeof(char) * (d->line_len + 1));
		int j = 0;
		while (j < d->line_len)
		{
			if (line[j] != d->full && line[j] != d->obstacle && line[j] != d->empty && line[j] != '\n')
			{
				while (i >= 0)
				{
					free(d->map[i]);
					i--;
				}
				free(d->map);
				free(line);
				return 0;
			}
			d->map[i][j] = line[j];
			j++;
		}
		d->map[i][j] = 0;
		i++;
	}
	if (i != d->lines || getline(&line, &size, f) != -1)
	{
		free(line);
		int j = 0;
		while (j < i)
		{
			free(d->map[j]);
			j++;
		}
		free(d->map);
		return 0;
	}
	d->map[i] = NULL;
	free(line);
	return 1;
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		FILE *f = stdin;
		struct data d;

		if (parse(f, &d) == 0)
		{
			fprintf(stderr, "map error\n");
			return 0;
		}
		dp(&d);
		draw(&d);
		return 0;
	}
	int i = 1;
	while (i < ac)
	{
		FILE *f = fopen(av[i], "r");

		if (f != NULL)
		{
			struct  data d;
			if (parse(f, &d) == 0)
			{
				fclose(f);
				fprintf(stderr, "map error\n");
			}
			else
			{
				fclose(f);
				dp(&d);
				draw(&d);
			}
		}
		else
			fprintf(stderr, "map error\n");
		i++;
		if (i != ac)
			fprintf(stdout, "\n");
	}
	return 1;
}