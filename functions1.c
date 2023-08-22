#include "main.h"

/*- print unsigned number -*/
/**
 * print_unsigned - Prints an unsigned number
 * @buffer: this is the buffer array that will handle print
 * @flags:  active flags is calculated by this.
 * @precision: precision spcfctn
 * @size: enumerates size
 * @types: List a of argmts
 * @width: gets the width
 * Return: the number of characters printed
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/*- print unsigned number in octal -*/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @buffer: this is the buffer array that will handle print
 * @flags:  active flags is calculated by this.
 * @precision: precision spcfctn
 * @size: enumerates size
 * @types: List a of argmts
 * @width: gets the width
 * Return: the number of characters printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/*- print unsigned number in hexadecimal -*/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @buffer: this is the buffer array that will handle print
 * @flags:  active flags is calculated by this.
 * @precision: precision spcfctn
 * @size: enumerates size
 * @types: List a of argmts
 * @width: gets the width
 * Return: the number of characters printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/*- print unsigned number in upper hexadecimal -*/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @buffer: this is the buffer array that will handle print
 * @flags:  active flags is calculated by this.
 * @precision: precision spcfctn
 * @size: enumerates size
 * @types: List a of argmts
 * @width: gets the width
 * Return: the number of characters printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/*- print hexa number in lower/upper -*/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @map_to: Array of values to map the number to
 * @flag_ch: Calculates active flags
 * @size: Size specifier
 * @size: Size specification
 * @buffer: this is the buffer array that will handle print
 * @flags:  active flags is calculated by this.
 * @precision: precision spcfctn
 * @size: enumerates size
 * @types: List a of argmts
 * @width: gets the width
 * Return: the number of characters printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

