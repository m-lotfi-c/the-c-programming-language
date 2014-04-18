#include <stdio.h>
#include <stdlib.h>

#define TABSTOP       4    /* number of spaces that represent a tab */
#define MAXWHITESPACE 1000 /* maximum contiguous whitespace characters */

int capture(char first, char buf[]);
void entab(int tabstop, char whitespace[]);

int main()
{
	int c;
	char captured[MAXWHITESPACE];

	while ((c = getchar()) != EOF) {
		if (c == '\t' || c == ' ') {
			c = capture(c, captured);
			entab(TABSTOP, captured);
			putchar(c);
		}
		else if (c == '\n') {
			putchar(c);
		}
		else {
			putchar(c);
		}
	}

	return 0;
}

int capture(char first, char buf[])
{
	int c, idx = 0;

	buf[idx++] = first;
	while ((c = getchar()) != EOF && (c == ' ' || c == '\t')) {
		buf[idx++] = c;
		if (idx >= MAXWHITESPACE) {
			fprintf (stderr, "Too much whitespace");
			exit (EXIT_FAILURE);
		}
	}
	buf[idx] = '\0';

	return c;
}

void entab(int tabstop, char whitespace[])
{
	int i = 0, j = 0, k;

	while (whitespace[i] != '\0') {
		if (whitespace[i] == '\t') {
			putchar(whitespace[i++]);
			continue;
		}

		/* consume up to tabstop more whitespaces */
		while (j++ < tabstop) {
			/* just output a tab if we encounter one */
			if (whitespace[++i] == '\t' ) {
				i++;
				break;
			}
			else if (whitespace[i] == '\0') { 
				/* if we had tabstop spaces output a tab */
				if (j == tabstop)
					break;

				/* otherwise output trailing spaces */
				for (k = 0; k < j; k++) {
					putchar(' ');
				}
				return;
			}
		}

		putchar('\t');
		j = 0;
	}
}
