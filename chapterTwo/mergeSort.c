#include <stdio.h>
#define NUM_OF_ELEMS 10

static void merge(int arr[], int low, int mid, int high);
static void merge_sort(int arr[], int low, int high);

int main()
{
	int index = 0;
	int no_of_elements = 0;
	int arr[NUM_OF_ELEMS];

	printf("\nEnter the number of elements that needs to be sorted\n");
	scanf("%d", &no_of_elements);
	printf("\nThe number of elements that needs to be sorted are: %d\n", no_of_elements);

	printf("\nEnter the elements in an array that needs to be sorted\n");	
	for (index = 0; index < no_of_elements; ++index)
	{
		scanf("%d", &arr[index]);
	}

	printf("\nThe elements entered in an array are: \n");
	for (index = 0; index < no_of_elements; ++index)
	{
		printf("\narr[%d]: %d\n", index, arr[index]);
	}

	merge_sort(arr, 0, (no_of_elements - 1));

	printf("\nThe sorted array is:\n");
	for (index = 0;index < no_of_elements; ++index)
	{
		printf("%d\t", arr[index]);
	}

	return 0;
}

static void merge_sort(int arr[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		merge_sort(arr, low, mid);
		merge_sort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}

static void merge(int arr[], int low, int mid, int high)
{
	int nL = 0;
	int nR = 0;
	int i = 0;
	int j = 0;
	int k = 0;

	printf("\nI am in merge function\n");

	nL = (mid - low + 1);
	nR = (high - mid);

	int L[nL];
	int R[nR];

	for (i = 0; i < nL; ++i)
	{
		L[i] = arr[low + i];
	}
	for (j = 0; j < nR; ++j)
	{
		R[j] = arr[mid + 1 + j];
	}
	i = 0;
	j = 0;
	k = low;

	while ((i < nL) && (j < nR))
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			++k;
			++i;
		}

		else
		{
			arr[k] = R[j];
			++k;
			++j;
		}
	}

	while (i < nL)
	{
		arr[k] = L[i];
		++k;
		++i;
	}
	while (j < nR)
	{
		arr[k] = R[j];
		++k;
		++j;
	}
}
