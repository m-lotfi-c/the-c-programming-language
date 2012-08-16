#include <stdio.h>

#define MAXLINE  1000    /* maximum input line size */
#define OVERFLOW 80      /* print lines longer than this */

int readline(char line[], int maxline);

/* longestline: print longest line */
int main()
{
	int len;                /* current line length */
	char line[MAXLINE];     /* current input line */

	len = 0;
	while ((len = readline(line, MAXLINE)) > 0){
		if (len > OVERFLOW) {
			printf("%s", line);
		}
	}

	return 0;
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
