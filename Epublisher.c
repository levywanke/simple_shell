#include "theme.h"

/**
 * print_err - output to standard error
 *
 * @msg: the outputted
 *
 * Return: the size
 **/
int print_err(char *msg)
{
	return (print_to_fd(msg, STDERR));
}
