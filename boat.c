/*
** EPITECH PROJECT, 2017
** boat.c
** File description:
** 
*/

void set_boat(t_lineco boat, char len)
{
	if (boat.co1.x == boat.co2.x) {
		if (boat.co1.y < boat.co2.y)
			while (boat.co1.y <= boat.co2.y)
				GAME.local.map[boat.co1.y++][boat.co1.x] = len;
		else
			while (boat.co1.y >= boat.co2.y)
				GAME.local.map[boat.co1.y--][boat.co1.x] = len;
	} else {
		if (boat.co1.x < boat.co2.x)
			while (boat.co1.x <= boat.co2.x)
				GAME.local.map[boat.co1.y][boat.co1.x++] = len;
		else
			while (boat.co1.x >= boat.co2.x)
				GAME.local.map[boat.co1.y][boat.co1.x--] = len;
	}
}

void place_boat(char *map_s)
{
	fill_map(GAME.local.map);
	t_lineco tmp_co;
	int line = 0;
	char len;

	while (line < 4) {
		len = map_s[line * 8];
		tmp_co.co1.x = map_s[line * 8 + 2] - 65;
		tmp_co.co1.y = map_s[line * 8 + 3] - 49;
		tmp_co.co2.x = map_s[line * 8 + 5] - 65;
		tmp_co.co2.y = map_s[line * 8 + 6] - 49;
		set_boat(tmp_co, len);
		line = line + 1;
	}
}