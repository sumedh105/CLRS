#include <stdio.h>
#define MAXNUM 10

static int bin_search(int arr[], int low, int high, int ele, int num);

int main()
{
	int num = 0;
	int ele = 0;
	int index = 0;
	int result = 0;
	int arr[MAXNUM] = {0};

	printf("\nEnter the number of elements that needs to be entered in an array\n");
	scanf("%d", &num);
	printf("\nThe number of elements entered are: %d\n", num);

	printf("\nENter the number of elements in an array in a sorted order\n");
	for (index = 0; index < num; ++index)
	{
		scanf("%d", &arr[index]);
	}

	printf("\nThe elements entered in an array are:\n");
	for (index = 0; index < num; ++index)
	{
		printf("\n%d\n", arr[index]);
	}

	printf("\nEnter the element that needs to be searched in an array\n");
	scanf("%d", &ele);

	result = bin_search(arr, 0, num - 1, ele, num);

	if (result == -1)
	{
		printf("\nThe element is not present in an array\n");
	}
	else
	{
		printf("\nThe element is present in an array at position: %d\n", result);
	}

	return 0;
}

static int bin_search(int arr[], int low, int high, int ele, int num)
{
	int mid = 0;

	if (low > high)
	{
		return -1;
	}

	else
	{
		mid = (low + high) / 2;

		if (ele == arr[mid])
		{
			return mid;
		}

		else if (ele < arr[mid])
		{
			bin_search(arr, low, mid - 1, ele, num);
		}

		else if (ele > arr[mid])
		{
			bin_search(arr, mid + 1, high, ele, num);
		}
	}
}
