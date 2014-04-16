#include <stdio.h>

void squeeze (char source[], const char blacklist[]) {
	int i, j, k;

	/* loop through each blacklisted char */
	for (i = 0; blacklist[i] != '\0'; i++) {
		for (j = k = 0; source[j] != '\0'; j++) {
			if (source[j] != blacklist[i]) {
				source[k++] = source[j];
			}
		}

		source[k] = '\0';
	}
}

int main (void)
{
	char src[] = "The quick brown fox jumped over the lazy dog.";

	squeeze (src, "aeiou");

	printf ("%s\n", src);

	return 0;
}
