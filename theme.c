#include "store.h"
#include "overall.h"
#include "instructs.h"
#include "theme.h"

/**
 * prompt - output the evoke
 *
 * @info: overall view of the bash
 **/
void prompt(general_t *info)
{
	if (info->mode == NON_INTERACTIVE)
		return;

	print("$ ");
}

/**
 * read_prompt - get the available input
 *
 * Return: end of file
 **/
char *read_prompt()
{
	char *buf;
	int res;
	size_t size;

	buf = NULL;

	res = getline(&buf, &size, stdin);

	if (res == EOF)
	{
		free_memory_p((void *) buf);
		return (NULL);
	}

	return (buf);
}

/**
 * start_prompt - evoke
 *
 * @info: architect of programm
 *
 * Return: end of file
 **/
void start_prompt(general_t *info)
{
	char *buff;
	char **arguments;
	char *path;

signal(SIGINT, sigintHandler);
	while (1)
	{
		prompt(info);

		path = _getenv("PATH");
		is_current_path(path, info);

		info->environment = path;
		buff = read_prompt();
		if (buff == NULL)
		{
			print(info->mode == INTERACTIVE ? "exit\n" : "");
			free(path);
			break;
		}

		info->n_commands++;
		if (buff[0] != '\n')
		{
			arguments = split_words(buff, " \t\n");

			info->arguments = arguments;
			info->buffer = buff;
			analyze_patterns(info, arguments);
			analyze(arguments, info, buff);

			free_memory_pp((void *) arguments);
		}

		free_memory_p((void *) buff);
		free_memory_p((void *) path);
	}

}

/**
 * sigintHandler - take care of the signal
 *
 * @sig_num: null variable
 **/
void sigintHandler(int sig_num)
{
	(void) sig_num;

	signal(SIGINT, sigintHandler);
	print("\n$ ");
	fflush(stdout);
}

