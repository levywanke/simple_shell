#include "theme.h"

/**
 * split_words - divide arrays of chars
 *
 * @line: variable to divide
 * @sep: keywords,punctuation and so ford
 *
 * Return: array of chars
 **/
char **split_words(char *line, const char *sep)
{
	char **srs, **temp, *lexeme;
	size_t nss, sos;

	sos = sizeof(char *);
	srs = malloc(sos);
	if (srs != NULL)
	{
		nss = 1;
		lexeme = strtok(line, sep);
		while (lexeme)
		{
			if (lexeme[0] == '#')
				break;
			temp = _realloc(srs, sos, (nss + 1) * sizeof(char *));
			sos = (nss + 1) * sizeof(char *);
			if (temp == NULL)
				break;

			srs = temp;
			++nss;

			srs[nss - 2] = malloc(_strlen(lexeme) + 1);
			if (srs == NULL)
			{
				free(srs);
				free(temp);
			}

			if (srs[nss - 2] != NULL)
				_strcpy(srs[nss - 2], lexeme);

			lexeme = strtok(NULL, sep);

			temp = NULL;
		}

		srs[nss - 1] = NULL;
	}

	return (srs);
}

/**
 * join_words - Jconcat strs
 * Description: output should be in order
 * @word1: var
 * @word2: varr
 * @word3: varrr
 * @sep: null byte
 *
 * Return: divided and a nl
 **/
char *join_words(char *word1, char *word2, char *word3, const char *sep)
{
	char *exically;
	int ring1, ring2, ring3, bitesep;

	ring1 = ring2 = bitesep = 0;

	if (word1 != NULL)
		ring1 = _strlen(word1);
	else
		word1 = "";

	if (word2 != NULL)
		ring2 = _strlen(word2);
	else
		word2 = "";

	if (word3 != NULL)
		ring3 = _strlen(word3);
	else
		word3 = "";

	if (sep != NULL)
		bitesep = _strlen((char *)sep);
	else
		sep = "";

	exically = malloc(ring1 + ring2 + bitesep + ring3 + bitesep + 2);
	if (exically == NULL)
		return (NULL);

	exically = _strcpy(exically, word1);
	exically = _strcat(exically, (char *)sep);
	exically = _strcat(exically, word2);
	exically = _strcat(exically, (char *)sep);
	exically = _strcat(exically, word3);
	exically = _strcat(exically, "\n");

	return (exically);
}
