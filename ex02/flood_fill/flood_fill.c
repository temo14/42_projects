#include <unistd.h>
#include <stdio.h>

typedef struct  s_point
{
        int           x;
        int           y;
}             t_point;

void make_area(char **tab, t_point cur_pos, t_point size, char c)
{
	if(cur_pos.x >= size.x || cur_pos.y >= size.y)
	{
		return;
	}

	if(cur_pos.x < 0 || cur_pos.y < 0)
	{
		return;
	}
	
	if(tab[cur_pos.x][cur_pos.y] != c)
	{
		return;
	}
	tab[cur_pos.x][cur_pos.y] = 'F';

	t_point up = { cur_pos.x, cur_pos.y + 1};
	make_area(tab, up, size, c);

	t_point down = { cur_pos.x, cur_pos.y - 1 };
	make_area(tab, down, size, c);

	t_point right = { cur_pos.x + 1, cur_pos.y };
	make_area(tab, right, size, c);

	t_point left = { cur_pos.x - 1, cur_pos.y };
	make_area(tab, left, size, c);
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char c = tab[begin.x][begin.y];
	make_area(tab, begin, size, c);
}

void print_arr(char **tab, t_point size)
{
	int i = 0;
	int j;
	while(i < size.x)
	{
		j = 0;
		while(j < size.y)
		{
			write(1, &tab[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int main()
{
	char data[5][6] = {
		"11111",
		"1x11w",
		"1a0q1",
		"11d11",
		"11111",
	};
	t_point size = { 5, 5 };
	t_point begin = { 0, 0 };
	char *tab[5];
	int i = 0;
	while(i < 5)
	{
		tab[i] = data[i];
		i++;
	}
	flood_fill(tab, size, begin);
	print_arr(tab, size);

	return 0;
}
