/*
** EPITECH PROJECT, 2017
** my_recieve.c
** File description:
** 
*/

void count_shot_x()
{
	GAME.remote.impact.x ++;
}

void count_shot_y()
{
	GAME.remote.impact.y ++;
}

void count_shot(int signum, siginfo_t *siginfo, void *context)
{
	(void) context;
	usleep(100);
	if (GAME.remote.touch == 0 && signum == SIGUSR2)
		GAME.remote.impact.x ++;
	if (GAME.remote.touch == 1 && signum == SIGUSR2)
		GAME.remote.impact.y ++;
	else if (GAME.remote.touch == 1 && signum != SIGUSR2)
		GAME.remote.touch = 0;
}

void recieve_shot()
{
	struct sigaction action;
	action.sa_sigaction = &count_shot;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &action, NULL);
	my_wait();
	action.sa_sigaction = &count_shot;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &action, NULL);
	my_wait();

	// signal(SIGUSR2, &next_shot);
}