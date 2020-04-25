#include <stdio.h>
#define MAXNUM 10

static void sum_of_binary_integers(int num, int arr_one[], int arr_two[], int sum_array[]);

int main()
{
	int num = 0;
	int index = 0;
	int arr_one[MAXNUM];
	int arr_two[MAXNUM];
	int sum_array[MAXNUM] = {0};

	printf("\nEnter the number of integers that needs to be entered in an array\n");
	scanf("%d", &num);
	printf("\nThe number of elements entered are: %d\n", num);

	printf("\nEnter the binary integers in the first array\n");
	for (index = 0; index < num; ++index)
	{
		scanf("%d", &arr_one[index]);
	}

	printf("\nEnter the binary integers in the second array\n");
	for (index = 0; index < num; ++index)
	{
		scanf("%d", &arr_two[index]);
	}

	sum_of_binary_integers(num, arr_one, arr_two, sum_array);

	printf("\nThe sum of the two array is:\n");
	for (index = 0; index <= num; ++index)
	{
		printf("%d\t", sum_array[index]);
	}
	printf("\n");

	return 0;
}

static void sum_of_binary_integers(int num, int arr_one[], int arr_two[], int sum_array[])
{
	int carry = 0;
	int index = 0;

	for (index = num - 1; index >= 0; --index)
	{
		sum_array[index] = (arr_one[index] + arr_two[index] + carry) % 2;
		carry = (arr_one[index] + arr_two[index] + carry) / 2;
	}	
	sum_array[index] = carry;
}
