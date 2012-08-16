#include <stdio.h>

float tocelcius(float fahr);

/* fahr2celc: prints a conversion table of fahrenheit to celcius
 * for fahr = 0, 20, ... 300 */
int main()
{
	float fahr;
	int upper, lower, step;

	upper = fahr = 300;
	lower = 0;
	step = 20;

	while (fahr >= lower) {
		printf("%3.0f\t%6.2f\n", fahr, tocelcius(fahr));
		fahr -= step;
	}

	return 0;
}

float tocelcius(float fahr)
{
	return (5.0 / 9.0) * (fahr - 32);
}
