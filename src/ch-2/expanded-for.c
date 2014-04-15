#include <stdio.h>
#define LIM 20

int main (void)
{
	int i, c, lim = LIM;
	char s[LIM];

	for (i = 0; i < lim - 1; i++) {
		c = getchar();
		if (c == '\n')
			break;
		if (c == EOF)
			break;

		s[i] = c;
	}

	s[i] = '\0';
	printf ("%s\n", s);

	return 0;
}
