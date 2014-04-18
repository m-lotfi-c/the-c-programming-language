#include <stdio.h>

#define MAXLEN 100     /* maximum word length */
#define IN     0       /* inside a word */
#define OUT    1       /* outside a word */

int main()
{
	int i, j, c, state, nchar;
	int nwords[MAXLEN];

	for (i = 0; i < MAXLEN; i++) {
		nwords[i] = 0;
	}

	state = OUT;
	nchar = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (state == IN) {
				state = OUT;
				/* overflows if nchar > MAXLEN */
				nwords[nchar]++;
				nchar = 0;
			}
		}
		else {
			state = IN;
			nchar++;
		}
	}

	for (i = 0; i < MAXLEN; i++) {
		if (nwords[i] > 0) {
			/* print label */
			printf("%4d: ", nwords[i]);

			/* print bar */
			for (j = 0; j < nwords[i]; j++) {
				printf("#");
			}

			printf("\n");
		}
	}

	return 0;
}
