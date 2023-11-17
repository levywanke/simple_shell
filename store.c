#include "store.h"

/**
 * _realloc - issuance of the storage
 *
 * @ptr: directed to finitila storage
 * @old_size: amount of storage at first
 * @new_size: amount of storage at last
 *
 * Return: issuance storage
 **/
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	char *s, *exically;
	unsigned int bel;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		s = malloc(new_size);
		if (s == NULL)
			return (NULL);

		return (s);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	s = malloc(new_size);
	if (s == NULL)
		return (NULL);

	exically = ptr;
	for (bel = 0; bel < old_size; bel++)
		s[bel] = exically[bel];

	free(ptr);

	return (s);
}


