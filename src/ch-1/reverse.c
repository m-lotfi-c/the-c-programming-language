#include <stdio.h>

#define MAXLINE    1000    /* maximum input line length */

void reverse(char to[], char from[], int len);
int readline(char line[], int maxline);

int main()
{
	int len;               /* the length of the last line read */
	char line[MAXLINE];    /* the last line read */
	char reversed[MAXLINE];

	while ((len = readline(line, MAXLINE)) > 0) {
		reverse(reversed, line, len);
		printf("%s\n", reversed);
	}

	return 0;
}

/* reverse: copy the characters in reverse order from `from` to `to` */
void reverse(char to[], char from[], int len)
{
	int i, max;

	max = len; /* the number of characters to copy less the newline */
	if (from[max - 1] == '\n') {
		--max;
		--len;
	}

	for (i = 0; i < max; ++i) {
		--len;
		to[i] = from[len];
	}

	to[i] = '\0';
}

/* readline: read a line into s and return its length */
int readline(char s[], int lim) 
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}

	if (c == '\n') {
		s[i] = c;
		++i;
	}

	s[i] = '\0';

	return i;
}
