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
	char *s, *aux;
	unsigned int b;

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

	aux = ptr;
	for (b = 0; b < old_size; b++)
		s[b] = aux[b];

	free(ptr);

	return (s);
}


