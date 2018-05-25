/*
** EPITECH PROJECT, 2017
** my_view.c
** File description:
** 
*/

void alt_str(char *str)
{
	int i = 0;

	while (str[i]) {
		my_putchar(str[i]);
		my_putchar(' ');
		i = i + 1;
	}
}

void view_map(char map[8][9])
{
	int i = 0;

	my_putstr(" |A B C D E F G H\n");
	my_putstr("-+---------------\n");
	while (i < 8) {
		my_put_nbr(i+1);
		my_putchar('|');
		alt_str(map[i]);
		my_putchar('\n');
		i = i + 1;
	}
}