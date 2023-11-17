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
	int i;

	for (i = 0; n != 0; i++, n /= 10)
		;

	return (i);
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
	int n_digits, i;
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
	for (i = n_digits - 1; number != 0; number /= 10, i--)
		_number[i] = (number % 10) + '0';

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
	unsigned int number, i;
	int sign;

	sign = 1;
	number = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (is_numerical(s[i]))
		{
			number = (s[i] - 48)	+ number * 10;

			if (s[i + 1] == ' ')
				break;
		}
		else if (s[i] == '-')
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
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (is_numerical(s[i]) == _FALSE)
			return (_TRUE);
	}

	return (_FALSE);
}

