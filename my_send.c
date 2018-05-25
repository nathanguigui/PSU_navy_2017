/*
** EPITECH PROJECT, 2017
** my_send.c
** File description:
** 
*/

void my_send()
{
	int i = 0;

	while (i < GAME.local.impact.x - 64) {
		usleep(500);
		kill(GAME.remote.pid, SIGUSR2);
		i = i + 1;
	}
	my_put_nbr(i);
	i = 0;
	usleep(500);
	kill(GAME.remote.pid, SIGUSR1);
	while (i < GAME.local.impact.y - 48) {
		usleep(500);
		kill(GAME.remote.pid, SIGUSR2);
		i = i + 1;
	}
	my_put_nbr(i);
	kill(GAME.remote.pid, SIGUSR1);
}