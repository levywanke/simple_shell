#include "store.h"
#include "instructs.h"
#include "overall.h"

/**
 * execute - craeting another call of a func
 *
 * @command: the one to output
 * @arguments: instructs available
 * @info: overall views of the bash
 * @buff: input initial
 **/
void execute(char *command, char **arguments, general_t *info, char *buff)
{
	int tatus;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		execve(command, arguments, environ);
		perror("./sh");

		free_memory_pp((void *) arguments);

		if (info->value_path != NULL)
		{
			free(info->value_path);
			info->value_path = NULL;
		}

		free(info);
		free(buff);
		exit(1);
	}
	else if (pid > 0)
	{
		waitpid(pid, &tatus, 0);
		if (WIFEXITED(tatus))
			info->statuscode = WEXITSTATUS(tatus);
	}
}


/**
 * current_directory - craete acall if the curr folder
 *
 * @cmd: instructs to prcess
 * @arguments: instructions of it
 * @buff: input initial
 * @info: overall views about the has
 *
 * Return: the current situation o the proc
 **/
int current_directory(char *cmd, char **arguments, char *buff, general_t *info)
{

	if (info->is_current_path == _FALSE)
		return (_FALSE);

	if (is_executable(cmd) == PERMISSIONS)
	{
		execute(cmd, arguments, info, buff);
		return (_TRUE);
	}

	return (_FALSE);
}

