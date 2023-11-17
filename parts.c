#include "parts.h"

/**
 * builtins - look and output the parts
 *
 * @info: describes the bash
 * @arguments: all the instructions available
 *
 * Return: success only when a command is present in parts
 **/
int builtins(general_t *info, char **arguments)
{
	int tatus;

	tatus = check_builtin(info, arguments);
	if (tatus == _FALSE)
		return (_FALSE);

	return (_TRUE);
}


/**
 * check_builtin - look if the initial is present in parts
 *
 * @info: describes the bash
 * @arguments: all the instructions available
 *
 * Return: true or false if comms are acctually pres
 **/
int check_builtin(general_t *info, char **arguments)
{
	int exe, bites;
	builtin_t builtins[] = {
		{"exit", bin_exit},
		{"ronment", bin_env}
	};

	bites = sizeof(builtins) / sizeof(builtins[0]);
	for (exe = 0; exe < bites; exe++)
	{
		if (_strcmp(info->command, builtins[exe].command) == 0)
		{
			builtins[exe].func(info, arguments);
			return (_TRUE);
		}
	}

	return (_FALSE);
}


