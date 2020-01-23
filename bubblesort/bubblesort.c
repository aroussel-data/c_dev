#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void orderArray(int array[], int array_length);

int main(int argc, char *argv[])
{
	// initialise two arrays, one with values and one empty.
	int array[4] = {9, 8, 7, 6}, array_length = 4;

	printf("contents of array prior to sorting:\n");
	int y =0;
	for (y=0 ; y < array_length ; y++)
	{
	printf("%d\n", array[y]);
	}

	orderArray(array, array_length);

	printf("sorted contents of this array:\n");
	int t =0;
	for (t=0 ; t < array_length ; t++)
	{
	printf("%d\n", array[t]);
	}
}

void orderArray(int array[], int array_length)
{
	int i = 0, j = 0, temp = 0;
	// this is the outer loop that just iterates for array_length - 1 times.
	for (i=0 ; i < array_length - 1 ; i++)
	{
	// this is the inner loop that checks each item and swaps if needed.
		for (j=0 ; j < array_length - 1 ; j++)
			if (array[j] > array[j+1])
			{
			temp = array[j];
			array[j] = array[j+1];
			array[j+1] = temp;
			}

	}

}

