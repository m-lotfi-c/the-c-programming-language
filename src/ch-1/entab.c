#include <stdio.h>

#define TABSTOP       4    /* number of spaces that represent a tab */
#define MAXWHITESPACE 1000 /* maximum contiguous whitespace characters */

void capture(char first, char buf[]);
int entab(int tabstop, char whitespace[]);

int main()
{
	int c, lineidx, offset, capturing;
	char captured[MAXWHITESPACE];

	lineidx = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\t' || c == ' ') {
			capture(c, captured);
			lineidx = entab(TABSTOP, captured);
		}
		else if (c == '\n') {
			lineidx = 0;
			putchar(c);
		}
		else {
			++lineidx;
			putchar(c);
		}
	}

	return 0;
}

int capture(char first, char buf[])
{
	int c;

	buf[0] = first;
	while ((c = getchar()) != EOF) {
	
	}

}

int entab(int tabstop, char whitespace[])
{
	int spaces, i;

	spaces = tabstop - (lineidx % tabstop);
	for (i = 0; i < spaces; ++i) {
		putchar(' ');
	}
}
