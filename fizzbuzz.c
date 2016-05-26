#include <stdio.h>

#define THREE 3
#define FIVE 5
#define FIFTEEN 15

int main()
{
	FILE *file = fopen("fizzbuzz-out.txt", "w");
	if(file == NULL)
	{
		exit(-1);
	}

	char i = 1;
	char stop = 100;
	char fizzed;
	
	for (i; i <= stop; i++) {
		fizzed = 0;
		if (divsByThree(i))
		{
			fizzed = 1;
			fprintf(file, "Fizz");
		}
		if (divsByFive(i))
		{
			fprintf(file, "Buzz");
		}
		else if (!fizzed)
		{
			fprintf(file, "%d", i);
		}
		fprintf(file, "\n");
	}

	fclose(file);
	return 0;
}

int divsByThree(int a) /* Mersenne Prime */
{
	char intermediate = (a & THREE) + (a >> 0b10);
	if (!(intermediate ^ THREE)) /* equals 3 */
	{
		return 1;
	}
	if (intermediate >> 0b10 ^ 0) /* larger than 3 */
	{
		return divsByThree(intermediate);
	}
	else
	{
		return 0;
	}
}

int divsByFive(int a) /* Mod by 15, bring close to 5 */
{
	char r = modFifteen(a);
	if (!r) /* a % 15 == 0 */
	{
		return 1;
	}
	if (r > 9)
	{
		r = r - 5;
	}
	return (!(r ^ FIVE)); /* a % 5 == 0 */
}

int modFifteen(int a) /* Mersenne Number */
{
	char intermediate = (a & FIFTEEN) + (a >> 0b100);
	if (!(intermediate ^ FIFTEEN)) /* equals 15 */
	{
		return 0;
	}
	if (intermediate >> 0b100 ^ 0) /* larger than 15 */
	{
		return modFifteen(intermediate);
	}
	else
	{
		return intermediate;
	}
}
