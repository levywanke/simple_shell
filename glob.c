#include "parts.h"

/**
 * bin_env - this is the func to empty env
 *
 * @info: overalll instructs about the shell
 * @arguments: instructions to be outputed
 **/
void bin_env(general_t *info, char **arguments)
{
	(void) info;
	(void) arguments;

	get_full_env();
}
