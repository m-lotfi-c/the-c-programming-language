#include <stdio.h>

/* celc2fahr: prints a conversion table of celcius to fahrenheit
 * for celc = 0, 20, ... 300 */
int main()
{
	float fahr, celcius;
	int lower, step;

	celcius= 300;
	lower = 0;
	step = 20;

	while (celcius>= lower) {
		fahr = (celcius/ (5.0 / 9.0)) + 32;
		printf("%3.0f\t%6.2f\n", fahr, celcius);
		celcius-= step;
	}

	return 0;
}
