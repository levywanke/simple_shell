#include "theme.h"

/**
 * _strlen - dimension of arr of chars
 *
 * @msg: array of chars
 *
 * Return: dimension
 **/
int _strlen(char *msg)
{
	int cmp;

	for (cmp = 0; msg[cmp] != '\0'; cmp++)
		;

	return (cmp);
}

/**
 * _strcat - combine arr of chars
 *
 * @dest: variable
 * @src: first var
 *
 * Return: combined
 */
char *_strcat(char *dest, char *src)
{
	int l_dest, cmp;

	l_dest = _strlen(dest);

	for (cmp = 0; src[cmp] != '\0'; cmp++, l_dest++)
		dest[l_dest] = src[cmp];

	dest[l_dest] = '\0';

	return (dest);
}

/**
 * _strcpy - take a dup
 *
 * @dest: first var
 * @src: last var
 *
 * Return: duplicated
 */
char *_strcpy(char *dest, char *src)
{
	int cmp;

	for (cmp = 0; src[cmp] != '\0'; cmp++)
		dest[cmp] = src[cmp];

	dest[cmp] = '\0';

	return (dest);
}


/**
 * _strdup - funct to take a look alike
 *
 * @str: variable
 *
 * Return: take arr of chars
 **/
char *_strdup(char *str)
{
	int bites, cmp;
	char *dest;

	if (str == NULL)
		return (NULL);

	bites = _strlen(str) + 1;
	dest = malloc(bites * sizeof(char));
	if (dest == NULL)
		return (NULL);

	for (cmp = 0; cmp < bites; cmp++)
		*(dest + cmp) = *(str + cmp);

	/* (dest + cmp) = 0; */

	return (dest);
}

/**
 * _strcmp - diferentiate two arr of chars
 *
 * @s1: first
 * @s2: second
 *
 * Return: comparedone
 */
int _strcmp(char *s1, char *s2)
{
	int cmp;

	for (cmp = 0; s1[cmp] != '\0'; cmp++)
	{
		if (s1[cmp] != s2[cmp])
			return (s1[cmp] - s2[cmp]);
	}

	return (0);
}

