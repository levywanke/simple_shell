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
 * Return: env gotten on succ or err
 **/
char *_getenv(const char *name)
{
	char **env;
	char *exics, *lexemes, *vars;
	int bitess;

	bitess = _strlen((char *) name);

	for (env = environ; *env; ++env)
	{
		exics = _strdup(*env);

		lexemes = strtok(exics, "=");
		if (lexemes == NULL)
		{
			free(exics);
			return (NULL);
		}

		if (_strlen(lexemes) != bitess)
		{
			free(exics);
			continue;
		}

		if (_strcmp((char *) name, exics) == 0)
		{
			lexemes = strtok(NULL, "=");
			vars = _strdup(lexemes);

			free(exics);
			return (vars);
		}

		free(exics);
	}

	return (NULL);
}

/**
 * which - get the required way
 *
 * @filename: the args erceived
 * @info: overall instructs about the bash
 *
 * Return: look to the path or err on return
 */
char *which(char *filename, general_t *info)
{
	char *path, *temppath, *lexemes;
	char *reduces;
	int bitess;

	(void) info;

	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);

	lexemes = strtok(path, ":");

	bitess = _strlen(filename) + 2;
	reduces = malloc(bitess * sizeof(char));
	reduces = _strcpy(reduces, "/");
	reduces = _strcat(reduces, filename);

	while (lexemes != NULL)
	{
		temppath = malloc(_strlen(lexemes) + bitess);
		temppath = _strcpy(temppath, lexemes);
		temppath = _strcat(temppath, reduces);

		if (is_executable(temppath) == PERMISSIONS)
		{
			free(reduces);
			free(path);
			return (temppath);
		}
		lexemes = strtok(NULL, ":");

		free(temppath);
	}

	free(path);
	free(reduces);

	return (NULL);
}

/**
 * is_current_path -	look for the order of the path
 *
 * @path: way to be checked
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
