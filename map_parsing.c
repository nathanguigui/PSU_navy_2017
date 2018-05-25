/*
** EPITECH PROJECT, 2017
** map_parsing.c
** File description:
** 
*/

void fill_map(char map[8][9])
{
	int x = 0;
	int y = 0;

	while (y < 8) {
		x = 0;
		while (x < 8) {
			map[y][x] = '.';
			x = x + 1;
		}
		map[y][x] = '\0';
		y = y + 1;
	}
}

void make_map(char *path)
{
	int fd = open(path, O_RDONLY, FD_CLOEXEC);
	
	lseek(fd, -31, SEEK_END);
	read(fd, GAME.local.map_s, 31);
	place_boat(GAME.local.map_s);
	close(fd);
}

int check_map(char *path)
{
	int fd = open(path, O_RDONLY, FD_CLOEXEC);
	lseek(fd, -31, SEEK_END);
	char map[31];

	if (fd == -1 || read(fd, map, 31) != 31)
		return (-1);
	close(fd);
	return (101);
}