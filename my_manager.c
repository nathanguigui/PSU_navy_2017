/*
** EPITECH PROJECT, 2017
** my_manager.c
** File description:
** 
*/

void manage_view_s()
{
	my_putstr("my positions:\n");
	view_map(GAME.local.map);
	my_putstr("\nenemy's positions:\n");
	view_map(GAME.remote.map);
}