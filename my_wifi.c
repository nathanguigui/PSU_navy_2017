/*
** EPITECH PROJECT, 2017
** my_wifi.c
** File description:
** 
*/

void connect_tome(int signum, siginfo_t *siginfo, void *context)
{
	(void) context;
	GAME.remote.pid = siginfo->si_pid;
	GAME.local.connected = 1;
	GAME.remote.touch = 1;
}

// void my_wait_p()
// {
// 	GAME.local.connected = 0;
// 	signal(SIGUSR1, &connect_tome);
// 	while (GAME.local.connected == 0)
// 		usleep(100);
// }

void my_wait()
{
	GAME.local.connected = 0;
	struct sigaction act;
	act.sa_sigaction = &connect_tome;
	act.sa_flags = SA_SIGINFO;
	
	sigaction(SIGUSR1, &act, NULL);
	while (GAME.local.connected == 0)
		usleep(100);

}