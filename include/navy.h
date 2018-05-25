/*
** EPITECH PROJECT, 2017
** navy.h
** File description:
** 
*/

#ifndef NAVY_
#define NAVY_
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

typedef struct s_coord {
	int x;
	int y;
} t_coord;

typedef struct s_lineco {
	t_coord co1;
	t_coord co2;
} t_lineco;

typedef struct s_gdata {
	char map_s[31];
	char map[8][9];
	pid_t pid;
	int connected;
	int touch;
	t_coord impact;
	int result;
} t_gdata;

typedef struct s_gsession {
	t_gdata local;
	t_gdata remote;
} t_gsession;

int my_putchar(char c);
int	my_putstr(char const *str);
int my_put_nbr(int nb);
int my_getnbr(char *str);
int print_help(void);
int	my_strcmp(char *str1, char *str2);

int check_map(char *path);
void fill_map(char map[8][9]);
void make_map(char *path);
//boat.c
void place_boat(char *map_s);
//my_view.c
void view_map(char map[8][9]);
//my_manager.c
void manage_view_s(void);
//my_wifi.c
void my_wait(void);
//my_pid.c
void my_pid(void);
//my_core.c
void server_core(void);
void client_core();
//my_input.c
void check_input(t_coord);
t_coord get_input();
//my_recieve.c
void recieve_shot();
//my_send.c
void my_send();


t_gsession GAME;

#endif