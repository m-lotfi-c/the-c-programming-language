#include <stdio.h>

/* cpio: copies standard input onto standard output */
int main()
{
	int c;

	while ((c = getchar()) != EOF)
			putchar(c);

	return 0;

}
