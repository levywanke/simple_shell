#include "theme.h"
#include "overall.h"

/**
 * digits - bring te mericals
 *
 * @n: mericals
 *
 * Return: umericals
 **/
int digits(int n)
{
	int cmp;

	for (cmp = 0; n != 0; cmp++, n /= 10)
		;

	return (cmp);
}

/**
 * to_string - merical to arrs of chars
 *
 * @number: merical
 *
 * Return: merical to chars
 **/
char *to_string(int number)
{
	int n_digits, cmp;
	char *_number;

	n_digits = digits(number);
	_number = malloc(n_digits * sizeof(char) + 2);
	if (number == 0)
	{
		_number[0] = '0';
		_number[1] = '\0';
		return (_number);
	}
	/* Check NULL */

	_number[n_digits] = '\0';
	for (cmp = n_digits - 1; number != 0; number /= 10, cmp--)
		_number[cmp] = (number % 10) + '0';

	return (_number);
}


/**
 * is_numerical - merical?
 *
 * @n: imerucals
 *
 * Return: merical?,one or zero
 */
int is_numerical(unsigned int n)
{
	return (n >= '0' && n <= '9');
}

/**
 * _atoi - arr of chars to umericals
 *
 * @s: variable chars
 *
 * Return: mericals
 */
int _atoi(char *s)
{
	unsigned int number, cmp;
	int sign;

	sign = 1;
	number = 0;
	for (cmp = 0; s[cmp] != '\0'; cmp++)
	{
		if (is_numerical(s[cmp]))
		{
			number = (s[cmp] - 48)	+ number * 10;

			if (s[cmp + 1] == ' ')
				break;
		}
		else if (s[cmp] == '-')
		{
			sign *= -1;
		}

	}

	return (number * sign);
}

/**
 * contains_letter - look for nonmericals
 *
 * @s: arr of chars for lookup
 *
 * Return: true or false
 **/
int contains_letter(char *s)
{
	int cmp;

	for (cmp = 0; s[cmp] != '\0'; cmp++)
	{
		if (is_numerical(s[cmp]) == _FALSE)
			return (_TRUE);
	}

	return (_FALSE);
}

