#include <stdio.h>

#define IN 1     /* inside a word */
#define OUT 0    /* outside a word */

/* splitwords: print each word from input on a new line */
int main()
{
	int c, state;

	state = OUT;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			state = OUT;
			continue;
		}
		else if (state == OUT) {
			state = IN;
			putchar('\n');
		}
		putchar(c);
	}

	return 0;
}
