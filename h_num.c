#include "shell.h"

/**
 * long_to_string - converts a number to a string
 * @num: number to be converted in a string
 * @string: buffer to save the number as string
 * @base: base to convert number
 */

void long_to_string(long num, char *string, int base)
{
	int index = 0, inNegative = 0;
	long cociente = num;
	char letters[] = {"0123456789abcdef"};

	if (cociente == 0)
		string[index++] = '0';
	if (string[0] == '-')
		inNegative = 1;
	while (cociente)
	{
		if (cociente < 0)
			string[index++] = letters[-(cociente % base)];
		cociente /= base;
	}
	if (inNegative)
		string[index++] = '-';
	string[index] = '\0';
	str_reverse(string);
}

/**
 * _atoi - converts a string to an integer
 * @s: pointer to string origin
 * Return: integer of string or 0
 */

int _atoi(char *s)
{
	int sign = 1;
	unsigned int num = 0;

	while (!('0' <= *s && *s <= '9') && *s != '\0')
	{
		if (*s == '-')
			sign *= -1;
		if (*s == '+')
			sign *= +1;
		s++;
	}
	while ('0' <= *s && *s <= '9' && *s != '\0')
	{
		num = (num * 10) + (*s - '0');
		s++;
	}
	return (num * sign);
}

/**
 * count_characters - count the coincedences of characters in string
 * @string: pointer to string origin
 * @character: string with characters to be counted
 * Return: integer of string or 0
 */

int count_characters(char *string, char *character)
{
	int i = 0, counter = 0;

	for (; string[i]; i++)
	{
		if (string[i] == character[0])
			counter++;
	}
	return (counter);
}
