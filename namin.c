#include "namin.h"
#include "overall.h"

/**
 * main - gateway
 * @argc: instructs gotten
 * @argv: instructs gotten
 * Return: return zero
 **/

int main(int argc, char **argv)
{
	general_t *info;
	int statuscode;

	info = malloc(sizeof(general_t));
	if (info == NULL)
	{
		perror(argv[0]);
		exit(1);
	}

	info->pid = getpid();
	info->statuscode = 0;
	info->n_commands = 0;
	info->argc = argc;
	info->argv = argv;
	info->mode = isatty(STDIN) == INTERACTIVE;
	start(info);

	statuscode = info->statuscode;

	free(info);

	return (statuscode);
}
