/*
** EPITECH PROJECT, 2017
** my_core.c
** File description:
** 
*/

void server_core()
{
	while (GAME.local.touch < 14 && GAME.remote.touch < 14) {
		GAME.local.impact = get_input();
		// check_input(GAME.local.impact);
		usleep(100);
		my_send();
		get_result();
		usleep(100);
		GAME.remote.impact.x = 64;
		GAME.remote.impact.y = 48;
		my_putstr("\nwaiting for enemy's attack...\n");
		recieve_shot();	
		check_input(GAME.remote.impact);
		manage_view_s();	
	}
}

void client_core()
{
	// t_coord shot;

	// shot = get_input();
	// check_input(shot);
	// manage_view_s;
	while (GAME.local.touch < 14 && GAME.remote.touch < 14) {
		usleep(100);
		GAME.remote.impact.x = 64;
		GAME.remote.impact.y = 48;
		my_putstr("\nwaiting for enemy's attack...\n");
		recieve_shot();
		check_input(GAME.remote.impact);
		// my_put_nbr(GAME.remote.impact.x);
		// my_putchar('\n');
		// my_put_nbr(GAME.remote.impact.y);

		GAME.local.impact = get_input();
		// check_input(GAME.local.impact);
		usleep(100);
		my_putchar('d');
		my_send();
		get_result();
		manage_view_s();
	}
}