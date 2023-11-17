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
	char **arrs, **temp, *lexemes;
	size_t nss, oss;

	oss = sizeof(char *);
	arrs = malloc(oss);
	if (arrs != NULL)
	{
		nss = 1;
		lexemes = strtok(line, sep);
		while (lexemes)
		{
			if (lexemes[0] == '#')
				break;
			temp = _realloc(arrs, oss, (nss + 1) * sizeof(char *));
			oss = (nss + 1) * sizeof(char *);
			if (temp == NULL)
				break;

			arrs = temp;
			++nss;

			arrs[nss - 2] = malloc(_strlen(lexemes) + 1);
			if (arrs == NULL)
			{
				free(arrs);
				free(temp);
			}

			if (arrs[nss - 2] != NULL)
				_strcpy(arrs[nss - 2], lexemes);

			lexemes = strtok(NULL, sep);

			temp = NULL;
		}

		arrs[nss - 1] = NULL;
	}

	return (arrs);
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
	char *exics;
	int arr1, arr2, arr3, bitessep;

	arr1 = arr2 = bitessep = 0;

	if (word1 != NULL)
		arr1 = _strlen(word1);
	else
		word1 = "";

	if (word2 != NULL)
		arr2 = _strlen(word2);
	else
		word2 = "";

	if (word3 != NULL)
		arr3 = _strlen(word3);
	else
		word3 = "";

	if (sep != NULL)
		bitessep = _strlen((char *)sep);
	else
		sep = "";

	exics = malloc(arr1 + arr2 + bitessep + arr3 + bitessep + 2);
	if (exics == NULL)
		return (NULL);

	exics = _strcpy(exics, word1);
	exics = _strcat(exics, (char *)sep);
	exics = _strcat(exics, word2);
	exics = _strcat(exics, (char *)sep);
	exics = _strcat(exics, word3);
	exics = _strcat(exics, "\n");

	return (exics);
}
