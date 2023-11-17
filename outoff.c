#include "store.h"

/**
 * free_memory_p - release storage
 *
 * @ptr: direct to released
 **/
void free_memory_p(void *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}

	ptr = NULL;
}

/**
 * free_memory_pp - release binary storage
 *
 * @ptr: binary direct to released storarrge
 **/
void free_memory_pp(void **ptr)
{
	void **tmp;

	for (tmp = ptr; *tmp != NULL; tmp++)
		free_memory_p(*tmp);

	free_memory_p(ptr);
}
