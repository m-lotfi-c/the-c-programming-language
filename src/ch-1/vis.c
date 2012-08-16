#include <stdio.h>

/* vis: print visible escape sequences for newlines, tabs and escaped
 * backslashes */
int main()
{
	int c;

	while ((c = getchar()) != EOF) {
		if (c == '\t')
			printf("\\t");
		else if (c == '\n')
			printf("\\n\n");
		else if (c == '\\')
			printf("\\\\");
		else
			putchar(c);
	}

	return 0;
}
