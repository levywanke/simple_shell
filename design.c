#include "theme.h"
#include "store.h"
#include "overall.h"
#include "instructs.h"

/**
 * analyze_patterns - gateway
 * @info: variable
 * @arguments: variable
**/

void analyze_patterns(general_t *info, char **arguments)
{
	int cmp;

	for (cmp = 0; arguments[cmp] != NULL; cmp++)
		arguments[cmp] = pattern_handler(info, arguments[cmp]);
}

/**
 * pattern_handler - gateway
 * @info: variable
 * @string: variable
 * Return: array of strs
**/

char *pattern_handler(general_t *info, char *string)
{
	int cmp;

	for (cmp = 0; string[cmp] != '\0'; cmp++)
	{
		if (string[cmp] == '$' && string[cmp + 1] != '\0')
			string = replace_value(info, &cmp, string);
	}

	return (string);
}

/**
 * replace_value - gateway
 * @info: variable
 * @index: invariable
 * @string: variable
 * Return: arr of strs
**/

char *replace_value(general_t *info, int *index, char *string)
{
	int cmp, nss, oss;
	char *value;

	cmp = *index;
	cmp++;

	value = replacement(info, index, string + cmp);
	if (value == NULL)
	{
		string = _strcpy(string, "");

		return (string);
		;
	}

	oss = _strlen(string);
	nss = _strlen(value) + 1;

	string = _realloc(string, oss, nss);
	string = _strcpy(string, value);

	free_memory_p(value);
	*index = cmp;
	return (string);
}
