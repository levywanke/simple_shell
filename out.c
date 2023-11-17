#include "overall.h"
#include "parts.h"

/**
 * bin_exit - escbin function
 * Description: store otu of available storage
 * @info: overall views of the bash
 * @arguments: gotten instructions
 **/
void bin_exit(general_t *info, char **arguments)
{
	int statuscode, tatus;

	tatus = _TRUE;
	if (arguments[1] != NULL)
		tatus = number_controller(info, arguments[1]);

	if (tatus == _FALSE)
		return;

	statuscode = info->statuscode;

	free_memory_pp((void **) arguments);
	free_memory_p((void *) info->buffer);
	free_memory_p((void *) info->environment);
	free_memory_p((void *) info);

	exit(statuscode);
}

/**
 * number_controller - be in cgarge of the output instruct
 *
 * @info: overall views of the bash
 * @number: instructions
 *
 * Return: true or false
 **/
int number_controller(general_t *info, char *number)
{
	int _number;

	_number = _atoi(number);

	if (_number < 0 || contains_letter(number))
	{
		info->statuscode = 2;
		info->error_code = _CODE_ILLEGAL_NUMBER;
		error_extra(info, number);
		return (_FALSE);
	}

	if (_number > 255)
		info->statuscode = _number % 256;
	else
		info->statuscode = _number;

	return (_TRUE);
}

