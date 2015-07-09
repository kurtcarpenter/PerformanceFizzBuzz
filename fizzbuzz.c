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
	if(file == NULL)
	{
		exit(-1);
	}

	int start = 1;
	int stop = 100;
	/*
	printf("Please enter upper bound of fizzbuzz, at least 1: ");
	scanf("%d", &stop);*/

	nibbles.fifteen = 15;
	nibbles.two = 2;
	char *vals[15];

	while(1)
	{
		if(!(nibbles.i ^ nibbles.fifteen))
		{
			vals[nibbles.i - 1] = "FizzBuzz\n";
			break;
		}
		if (!((nibbles.i ^ left_shift_circular(nibbles.i, nibbles.two)) ^  nibbles.fifteen)) {
			vals[nibbles.i - 1] = "Fizz\n";
		}	else if (!((nibbles.i ^ 10) ^ nibbles.fifteen)
			|| !((nibbles.i ^ 10) ^ 0)) {
			vals[nibbles.i - 1] = "Buzz\n";
		}	else {
			vals[nibbles.i - 1] = "%d\n";
		}
		nibbles.i++;
	}

	for (int start = 1; start <= end; start++) {
		fprintf(file, vals[(start - 1) % 15], start);
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
