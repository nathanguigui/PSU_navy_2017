##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## 
##

all:
	@gcc *.c -o navy -g -include include/navy.h
	@echo "make: all done."

fclean:
	@rm navy
	@echo "make: fclean done."

re:	fclean all
	@echo "make: re done."