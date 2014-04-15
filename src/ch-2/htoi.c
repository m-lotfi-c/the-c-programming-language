#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int htoi(const char *input)
{
	int i, c, ret, len, start;

	/* Find the beginning of the hex string: ignore 0x or 0X prefix */
	if (input[0] != '\0' && input[0] == '0' && input[1] != '\0' &&
		(input[1] == 'x' || input[1] == 'X')) {
		start = 2;
	} else {
		start = 0;
	}

	len = strlen(input);
	ret = 0;

	for (i = len - 1, c = 1; i >= start; i--, c++) {
		int j, factor = 1;
		/* I havent been told about pow yet so figure out the factor for
		 * the digit by multiplying up */
		for (j = 1; j < c; j++) {
			factor = factor * 16;
		}

		if (input[i] >= '0' && input[i] <= '9') {
			ret += factor * (input[i] - '0');
		} else if (input[i] >= 'a' && input[i] <= 'f') {
			ret += factor * (input[i] - 'a' + 10);
		} else if (input[i] >= 'A' && input[i] <= 'F') {
			ret += factor * (input[i] - 'A' + 10);
		} else {
			exit (EXIT_FAILURE);
		}
	}

	return ret;
}

int main (void)
{
	printf ("0x1 is %d\n", htoi ("0x1")); // 1
	printf ("f is %d\n", htoi ("f")); //15
	printf ("ef is %d\n", htoi ("ef")); // 239
	printf ("0X5B7c is %d\n", htoi ("0X5B7c")); // 23420
	return 0;
}
