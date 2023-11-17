#include "parts.h"
#include "instructs.h"
#include "store.h"
#include "overall.h"
#include "theme.h"

/**
 * analyze - stats of the instructions
 *
 * @arguments: this are the instructions to output
 * @info: overall arguments about the bash
 * @buff: the input holder instruction
 **/
void analyze(char **arguments, general_t *info, char *buff)
{
	char *cmd;
	int tatus;

	if (*arguments == NULL || arguments == NULL)
		return;

	cmd = arguments[0];
	info->command = cmd;
	if (check_builtin(info, arguments) == _TRUE)
		return;

	tatus = is_file(cmd);
	if (tatus == NON_PERMISSIONS)
	{
		info->statuscode = 126;
		info->error_code = _CODE_EACCES;
		error(info);
		return;
	}

	if (tatus == 1)
	{
		execute(cmd, arguments, info, buff);
		return;
	}

	if (current_directory(cmd, arguments, buff, info) == _TRUE)
		return;

	info->value_path = which(cmd, info);
	if (info->value_path != NULL)
	{
		execute(info->value_path, arguments, info, buff);
		free_memory_p((void *) info->value_path);
		return;
	}

	info->statuscode = 127;
	info->error_code = _CODE_CMD_NOT_EXISTS;
	error(info);
}

