/*
** EPITECH PROJECT, 2017
** my_result.c
** File description:
** 
*/

void compute_res(int signum, siginfo_t *siginfo, void *context)
{
	(void) context;
	if (signum == SIGUSR2)
		GAME.remote.result = 1;
	else if (signum == SIGUSR1)
		GAME.remote.result = 0;
	GAME.local.result = 1;
}

void draw_result()
{
	int x = GAME.local.impact.x;
	int y = GAME.local.impact.y;

	if (GAME.remote.result == 1) {
		GAME.remote.touch = GAME.remote.touch + 1;
		my_putchar(x);
		my_putchar(y);
		my_putstr(": hit\n");
		GAME.remote.map[y - 49][x - 65] = 'x';
	} else if (GAME.remote.result == 1) {
		my_putstr(": missed\n");
		GAME.remote.map[y - 49][x - 65] = 'o';
	}
}

void get_result()
{
	GAME.local.result = 0;
	struct sigaction act;
	act.sa_sigaction = &compute_res;
	act.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (GAME.local.result == 0)
		usleep(100);
	draw_result();
}