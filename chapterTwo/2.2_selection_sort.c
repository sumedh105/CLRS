#include <stdio.h>
#define NUM_OF_ELEMENTS 10

int main()
{
	int arr[NUM_OF_ELEMENTS];
	int index = 0;
	int temp = 0;
	int flag = 0;
	int indexOne = 0;
	int smallNum = 0;
	int smallNumIndex = 0;
	int noOfElements = 0;

	printf("\nEnter the no of elements that needs to be entered in an array\n");
	scanf("%d", &noOfElements);
	printf("\nThe number of elements that needs to be entered in an array are: %d\n", noOfElements);

	printf("\nEnter the elements in an array that needs to be sorted\n");
	for (index = 0; index < noOfElements; ++index)
	{
		scanf("%d", &arr[index]);
	}

	printf("\nThe elements entered in an array that needs to be sorted are:\n");
	for (index = 0; index < noOfElements; ++index)
	{
		printf("\narr[index]: %d\n", arr[index]);
	}

	//Selection sort algorithm
	for (index = 0; index < noOfElements; ++index)
	{
		smallNum = arr[index];

		for (indexOne = index + 1; indexOne < noOfElements; ++indexOne)
		{
			if (arr[indexOne] < smallNum)
			{
				flag = 1;
				smallNum = arr[indexOne];
				smallNumIndex = indexOne;
			}
		}

		if (flag == 1)
		{
			temp = arr[index];
			arr[index] = arr[smallNumIndex];
			arr[smallNumIndex] = temp;
		}

		flag = 0;
	}

	//Display the array
	printf("\nThe elements of an array after sorting are:\n");
	for (index = 0; index < noOfElements; ++index)
	{
		printf("\n%d\n", arr[index]);
	}

	return 0;
}
