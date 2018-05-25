/*
** EPITECH PROJECT, 2017
** my_pid.c
** File description:
** 
*/

void my_pid()
{
	my_putstr("my_pid: ");
	my_put_nbr(getpid());
	my_putstr("\nwaiting for enemy connection...\n");
	my_wait();
	my_putstr("\nenemy connected\n\n");	
}