#include <stdio.h>

struct
{
	unsigned int i : 4;
	unsigned int fifteen : 4;
	unsigned int math : 4;
	unsigned int val1 : 4;
	unsigned int val2 : 4;
	unsigned int two : 4;
} nibbles;

int main()
{
	FILE *file = fopen("fizzbuzz-out.txt", "w");
	if(fp == NULL)
	{
		exit(-1);
	}

	int start = 1;
	int stop;
	printf("Please enter upper bound of fizzbuzz, at least 1: ");
	scanf("%d", &stop);

	nibbles.fifteen = 15;
	nibbles.two = 2;
	for (nibbles.i = 1; nibbles.i <=15; nibbles.i++)
	{
		if(nibbles.i == nibbles.fifteen)
		{
			fprintf(file, "FizzBuzz\n");
			break;
		}
		if (!((nibbles.i ^ left_shift_circular(nibbles.i, nibbles.two)) ^  nibbles.fifteen))
		{
			fprintf(file, "Fizz\n");
		}
		else if (!((nibbles.i ^ 10) ^ nibbles.fifteen)
			|| !((nibbles.i ^ 10) ^ 0))
		{
			fprintf(file, "Buzz\n");
		}
		else
		{
			fprintf(file, "%d\n", nibbles.i);
		}
	}
	fclose(file);
	return 0;
}

int left_shift_circular(input, shift)
{
	nibbles.val1 = input;
	nibbles.val2 = shift;
	nibbles.math = (nibbles.val1 << nibbles.val2) | (nibbles.val1 >> (4 - nibbles.val2));
	return nibbles.math;
}
