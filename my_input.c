/*
** EPITECH PROJECT, 2017
** my_input.c
** File description:
** 
*/

int format_input(t_coord shot)
{
	shot.x = shot.x - 64;
	shot.y = shot.y - 48;

	if (!(shot.x >=1 && shot.x <= 8))
		return (-1);
	if (!(shot.y >=1 && shot.y <= 8))
		return (-1);
	GAME.remote.map[shot.y - 49][shot.x - 65] == 'x';
	return (0);
}

void check_touch(t_coord shot)
{
	char tmp = GAME.local.map[shot.y - 49][shot.x - 65];

	my_putchar(shot.x);
	my_putchar(shot.y);
	if (tmp >= 48 && tmp <= 57) {
		GAME.remote.map[shot.y - 49][shot.x - 65] = 'x';
		GAME.remote.touch = GAME.remote.touch + 1;
		my_putstr(": hit\n");
		kill(GAME.remote.pid, SIGUSR2);
	} else {
		GAME.remote.map[shot.y - 49][shot.x - 65] = 'o';
		my_putstr(": missed\n");
		kill(GAME.remote.pid, SIGUSR1);		
	}
	my_putchar('\n');
}

void check_input(t_coord shot)
{
	if (format_input(shot) == -1) {
		my_putstr("wrong position\n");
		my_putstr("attack: \n");
		check_input(get_input());
	} else {
		// my_putchar(shot.x);
		// my_putchar(shot.y);
		check_touch(shot);
		my_send();
	}

}

t_coord get_input()
{
	char buff[1024];
	t_coord result;

	my_putstr("\nattack: ");
	read(STDIN_FILENO, buff, sizeof(buff));
	result.x = buff[0];
	result.y = buff[1];	
	return (result);
}