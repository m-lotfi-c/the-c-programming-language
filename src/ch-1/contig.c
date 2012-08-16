#include <stdio.h>

#define TRUE 1
#define FALSE 0

/* contig: collapse contiguous spaces into a single space */
int main()
{
	int c, inspace = FALSE;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			if (!inspace) {
				inspace = TRUE;
			} else {
				continue;
			}
		}
		else if (c != ' ' && inspace)
			inspace = FALSE;

		putchar(c);
	}

	return 0;
}
