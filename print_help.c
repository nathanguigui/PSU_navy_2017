/*
** EPITECH PROJECT, 2017
** print_help.c
** File description:
** 
*/

int print_help(void)
{
	my_putstr("USAGE\n");
	my_putstr("\t./navy [first_player_pid] navy_positions\n");
	my_putstr("DESCRIPTION\n");
	my_putstr("\tfirst_player_pid:  only for th 2nd player.  ");
	my_putstr("pid of the first player.\n");
	my_putstr("\tnavy_positions:  file representing the positions of the ships.\n");
	return (0);
}