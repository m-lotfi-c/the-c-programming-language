#include <stdio.h>
#include <math.h>

#define BYTE 8

void print_type_info (const char *name, long max, ssize_t sz)
{
	printf ("%s is %ld bytes\n", name, sz);
	printf ("%s from %ld to %ld\n", name, max / 2, -(max / 2));
	printf ("unsigned %s from 0 to %ld\n", name, max);
}

int main (void)
{
	double char_max, int_max, long_max, short_max;

	char_max = pow (2, sizeof(char) * BYTE);
	short_max = pow (2, sizeof(short) * BYTE);
	int_max = pow (2, sizeof(int) * BYTE);
	long_max = pow (2, sizeof(long) * BYTE);

	print_type_info ("char", (long)char_max, sizeof(char));
	print_type_info ("short", (long)short_max, sizeof(short));
	print_type_info ("int", (long)int_max, sizeof(int));
	print_type_info ("long", (long)long_max, sizeof(long));


	return 0;
}
