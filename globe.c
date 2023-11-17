#include "theme.h"
#include "parts.h"
#include "instructs.h"
#include <string.h>
#include <sys/cdefs.h>
#include <unistd.h>

/**
 * _getenv - bring out the envvariable
 *
 * @name: th gotten var
 *
 * Return: ronment gotten on succ or err
 **/
char *_getenv(const char *name)
{
	char **ronment;
	char *exically, *lexeme, *var;
	int bites;

	bites = _strlen((char *) name);

	for (ronment = environ; *ronment; ++ronment)
	{
		exically = _strdup(*ronment);

		lexeme = strtok(exically, "=");
		if (lexeme == NULL)
		{
			free(exically);
			return (NULL);
		}

		if (_strlen(lexeme) != bites)
		{
			free(exically);
			continue;
		}

		if (_strcmp((char *) name, exically) == 0)
		{
			lexeme = strtok(NULL, "=");
			var = _strdup(lexeme);

			free(exically);
			return (var);
		}

		free(exically);
	}

	return (NULL);
}

/**
 * which - get the required path
 *
 * @filename: the args erceived
 * @info: overall instructs about the bash
 *
 * Return: look to the path or err on return
 */
char *which(char *filename, general_t *info)
{
	char *path, *tempway, *lexeme;
	char *reduces;
	int bites;

	(void) info;

	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);

	lexeme = strtok(path, ":");

	bites = _strlen(filename) + 2;
	reduces = malloc(bites * sizeof(char));
	reduces = _strcpy(reduces, "/");
	reduces = _strcat(reduces, filename);

	while (lexeme != NULL)
	{
		tempway = malloc(_strlen(lexeme) + bites);
		tempway = _strcpy(tempway, lexeme);
		tempway = _strcat(tempway, reduces);

		if (is_executable(tempway) == PERMISSIONS)
		{
			free(reduces);
			free(path);
			return (tempway);
		}
		lexeme = strtok(NULL, ":");

		free(tempway);
	}

	free(path);
	free(reduces);

	return (NULL);
}

/**
 * is_current_path -	look for the order of the path
 *
 * @path: path to be checked
 * @info: overall instructions about the shell
 **/
void is_current_path(char *path, general_t *info)
{
	info->is_current_path = _FALSE;

	if (path == NULL)
		return;

	if (path[0] == ':')
		info->is_current_path = _TRUE;
}

/**
 * get_full_env - receive acces to the whole environ
 **/
void get_full_env(void)
{
	char **temp;
	int i;

	for (i = 0, temp = environ; temp[i] != NULL; i++)
	{
		print(temp[i]);
		_putchar('\n');
	}
}
