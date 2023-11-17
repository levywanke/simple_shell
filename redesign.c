#include "instructs.h"
#include "theme.h"
#include "overall.h"

/**
 * replacement - gateway
 * @info: variable
 * @index: variable
 * @string: variable
 * Return: array of strings
**/

char *replacement(general_t *info, int *index, char *string)
{
	char *temp;
	char symbol;

	(void) index;

	symbol = *string;
	if (symbol != '?' && symbol != '$')
	{
		temp = replace_env(info, string);
		return (temp);
	}

	temp = (symbol == '$') ? to_string(info->pid) :
		to_string(info->statuscode);

	return (temp);
}

/**
 * replace_env - gateway
 * @info: variable
 * @environment: variable
 * Return: aray of strs
**/

char *replace_env(general_t *info, char *environment)
{
	char *ronment;

	(void) info;

	ronment = _getenv(environment);
	if (ronment != NULL)
		return (ronment);

	return (NULL);
}


