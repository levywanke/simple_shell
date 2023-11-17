#include "theme.h"
#include "overall.h"

/**
 * _putchar - standard output
 *
 * @c: variable
 *
 * Return: one or negative one
 **/
int _putchar(char c)
{
	return (write(STDOUT, &c, 1));
}

/**
 * print - standard output  
 *
 * @msg: variables
 *
 * Return: one or -ve one
 **/
int print(char *msg)
{
	return (print_to_fd(msg, STDOUT));
}

