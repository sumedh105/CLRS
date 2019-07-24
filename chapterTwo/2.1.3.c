#include <stdio.h>
#define NUM_OF_ITEMS 10

int main()
{
	int arr[NUM_OF_ITEMS];
	int noOfItemsInArray;
	int index = 0;
	int value = 0;
	int flag = 0;

	printf("\nEnter the no of elements that needs to be entered in an array\n");
	scanf("%d", &noOfItemsInArray);
	printf("\nThe no of items that needs to be entered in an array are: %d\n", noOfItemsInArray);

	printf("\nEnter the elements in an array\n");
	for(index = 0; index < noOfItemsInArray; ++index)
	{
		scanf("%d", &arr[index]);
	}

	printf("\nThe elements entered in an array are:\n");
	for (index = 0; index < noOfItemsInArray; ++index)
	{
		printf("\narr[index]: %d\n", arr[index]);
	}

	printf("\nEnter the element that needs to be searched\n");
	scanf("%d", &value);
	printf("\nThe element that needs to be searched is: %d\n", value);

	for (index = 0; index < noOfItemsInArray; ++index)
	{
		if (arr[index] == value)
		{
			flag = 1;
			break;
		}
		else
		{
			flag = 0;
		}
	}

	if (flag == 1)
	{
		printf("\nThe element is found at the index: %d\n", index);
	}
	else if(flag == 0)
	{
		printf("\nThe element is not found in an array\n");
	}

	return 0;
}	
