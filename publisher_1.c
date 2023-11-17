#include "theme.h"
#include "overall.h"
#include <unistd.h>

/**
 * _putchar_to_fd - fd of a folder
 *
 * @c: variable
 * @fd: specific position
 *
 * Return: one or -ve one
 **/
int _putchar_to_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}


/**
 * print_to_fd - output an array of chars
 *
 * @msg: var
 * @fd: the outputted one
 *
 * Return: one or -ve one
 **/
int print_to_fd(char *msg, int fd)
{
	int size;

	size = _strlen(msg);

	return (write(fd, msg, size));
}

