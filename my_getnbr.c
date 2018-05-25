/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** ascii to integer
*/

int my_getnbr(char *str)
{
	int nb = 0;

	for (int i = 0; str[i]; i++)
		nb = nb * 10 + str[i] - '0';
	return (nb);
}