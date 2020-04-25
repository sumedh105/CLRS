#include <stdio.h>
#define NUM_OF_ELEMS 10

int main()
{
	int arr[NUM_OF_ELEMS];
	int indexOne = 0;
	int indexTwo = 0;
	int noOfItems = 0;
	int temp = 0;

	printf("\nEnter the number of elements that needs to be sorted\n");	
	scanf("%d", &noOfItems);
	printf("\nThe no of items that needs to be sorted are: %d\n", noOfItems);

	printf("\nEnter the numbers that needs to be sorted\n");
	for (indexOne = 0; indexOne < noOfItems; ++indexOne)
	{
		scanf("%d", &arr[indexOne]);
	}

	printf("\nThe numbers entered are:\n");
	for (indexOne = 0; indexOne < noOfItems; ++indexOne)
	{
		printf("\narr[%d]: %d\n", indexOne, arr[indexOne]);
	}

	for (indexTwo = 0; indexTwo < noOfItems; ++indexTwo)
	{
		indexOne = 0;
		while (indexOne < indexTwo)
		{
			if (arr[indexTwo] < arr[indexOne])
			{
				temp = arr[indexTwo];
				arr[indexTwo] = arr[indexOne];
				arr[indexOne] = temp;
			}

			++indexOne;
		}
	}	

	printf("\nThe sorted array is:\n");
	for (indexOne = 0; indexOne < noOfItems; ++indexOne)
	{
		printf("\narr[%d]: %d\n", indexOne, arr[indexOne]);
	}

	return 0;
}
