#include "overall.h"
#include "instructs.h"

/**
 * is_executable - look if aggreements are available
 * @filename: folder to look
 *
 * Return: succ or err according to macros
 **/
int is_executable(char *filename)
{
	struct stat stats;

	if (stat(filename, &stats) == 0)
	{
		if (stats.st_mode & X_OK)
			return (PERMISSIONS);
		else
			return (NON_PERMISSIONS);
	}

	return (NON_FILE);
}

/**
 * is_file - enquire for a folder or dualnum
 * Description: check for agrrements when its a folder
 * @file: folder
 *
 * Return: return according to description in  macros
 **/
int is_file(char *file)
{
	int cmp, bitess;

	bitess = _strlen(file);
	for (cmp = 0; cmp < bitess; cmp++)
		if (file[cmp] == '/')
			return (is_executable(file));

	return (NON_FILE);
}
