#include <stdio.h>

#define NUMDIGITS 10

/* countdigits: count occurrences of all digits, whitespace and other */
int main()
{
	int i, c, nwhite, nother;
	int ndigit[NUMDIGITS];

	nwhite = nother = 0;
	for (i = 0; i < NUMDIGITS; i++) {
		ndigit[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		if (c >= '0' && c <= '9') {
			ndigit[c - '0']++;
		}
		else if (c == ' ' || c == '\n' || c == '\t') {
			nwhite++;
		}
		else {
			nother++;
		}
	}

	printf("digits =");
	for (i = 0; i < NUMDIGITS; i++) {
		printf(" %d", ndigit[i]);
	}

	printf(", white space = %d, other = %d\n", nwhite, nother);
	return 0;
}
