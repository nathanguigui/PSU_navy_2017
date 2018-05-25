/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** 
*/

int start_server(char *path)
{
	my_pid();
	fill_map(GAME.local.map);
	fill_map(GAME.remote.map);
	make_map(path);
	manage_view_s();
	server_core();
}

int start_client(char *path, char *pid)
{
	kill(GAME.remote.pid, SIGUSR1);
	my_putstr("my_pid: ");
	my_put_nbr(getpid());
	my_putstr("\nsuccessfully connected\n\n");
	fill_map(GAME.local.map);
	fill_map(GAME.remote.map);
	make_map(path);
	manage_view_s();
	client_core();
}

int main(int ac, char **av)
{
	if (my_strcmp(av[1], "-h"))
		print_help();
	else {
		switch (ac) {
		case 2:
			if (check_map(av[1]) == -1)
				break;
			start_server(av[1]);
			break;
		case 3:
			if (check_map(av[2]) == -1)
				break;
			GAME.remote.pid = my_getnbr(av[1]);
			start_client(av[2], av[1]);
			break;
		default:
			return (84);
		}
	}
	return (0);
}