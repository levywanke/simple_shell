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
	void **temp;

	for (temp = ptr; *temp != NULL; temp++)
		free_memory_p(*temp);

	free_memory_p(ptr);
}
