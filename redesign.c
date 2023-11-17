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
	char *tmp;
	char symbol;

	(void) index;

	symbol = *string;
	if (symbol != '?' && symbol != '$')
	{
		tmp = replace_env(info, string);
		return (tmp);
	}

	tmp = (symbol == '$') ? to_string(info->pid) :
		to_string(info->status_code);

	return (tmp);
}

/**
 * replace_env - gateway
 * @info: variable
 * @environment: variable
 * Return: aray of strs
**/

char *replace_env(general_t *info, char *environment)
{
	char *env;

	(void) info;

	env = _getenv(environment);
	if (env != NULL)
		return (env);

	return (NULL);
}


