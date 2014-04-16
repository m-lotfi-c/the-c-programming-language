#include <stdio.h>

int any (char source[], const char searchlist[]) {
	int i, j;

	for (i = 0; source[i] != '\0'; i++) {
		for (j = 0; searchlist[j] != '\0'; j++) {
			if (source[i] == searchlist[j]) {
				return i;
			}
		}
	}

	return -1;
}

int main (void)
{
	char src[] = "The quick brown fox jumped over the lazy dog.";
	int first_vowel;

	first_vowel = any (src, "aeiou");
	if (first_vowel == -1) {
		printf ("No vowels found\n");
	} else {
		printf ("vowel found at index %d\n", first_vowel);
	}

	return 0;
}
