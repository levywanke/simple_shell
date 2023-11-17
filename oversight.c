#include "oversight.h"
#include "theme.h"
#include "overall.h"

/**
 * message_selector - gets the gsm that look like in the prog
 *
 * @info: overall instructs about the code
 *
 * Return: fail if not familiar
 **/
char *message_selector(general_t info)
{
	int h, n_options;
	error_t messages[] = {
		{_ENOENT, _CODE_ENOENT},
		{_EACCES, _CODE_EACCES},
		{_CMD_NOT_EXISTS, _CODE_CMD_NOT_EXISTS},
		{_ILLEGAL_NUMBER, _CODE_ILLEGAL_NUMBER}
	};

	n_options = sizeof(messages) / sizeof(messages[0]);
	for (h = 0; h < n_options; h++)
		if (info.error_code == messages[h].code)
			return (messages[h].gsms);

	return ("");
}

/**
 * error - output fail
 *
 * @info: oerall instructions about the bash
 **/
void error(general_t *info)
{
	char *gsms;
	char *merics;
	char *exically;
	int size_number, size_message;

	merics = NULL;
	gsms = message_selector(*info);
	merics = to_string(info->n_commands);

	size_number = _strlen(merics);
	size_message = _strlen(info->argv[0]);

	exically = malloc(size_message + size_number + 3);

	exically = _strcpy(exically, info->argv[0]);
	exically = _strcat(exically, ": ");
	exically = _strcat(exically, merics);

	gsms = join_words(exically, info->command, gsms, ": ");
	print_err(gsms);

	free(gsms);
	free(merics);
	free(exically);
}

/**
 * error_extra - return err if not succ
 *
 * @info: ooverall instructs about the bash
 * @extra: additioanal one
 **/
void error_extra(general_t *info, char *extra)
{
	char *gsms, *merics, *exically, *exics;
	int size_number, size_message, size_extra;

	merics = NULL;
	gsms = message_selector(*info);
	merics = to_string(info->n_commands);

	size_number = _strlen(merics);
	size_message = _strlen(info->argv[0]);
	size_extra = _strlen(extra);

	exically = malloc(size_message + size_number + 3);
	exically = _strcpy(exically, info->argv[0]);
	exically = _strcat(exically, ": ");
	exically = _strcat(exically, merics);

	exics = malloc(_strlen(gsms) + size_extra + 3);
	exics = _strcpy(exics, gsms);
	exics = _strcat(exics, ": ");
	exics = _strcat(exics, extra);

	gsms = join_words(exically, info->command, exics, ": ");
	print_err(gsms);

	free(gsms);
	free(merics);
	free(exically);
	free(exics);
}

