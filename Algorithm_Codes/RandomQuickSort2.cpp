#include <iostream>
#include<time.h>

using namespace std;

void printArray(int[], int);

int partition(int arr[], int low, int high, int n)
{
	int pivot = arr[low];
	int i = low - 1, j = high + 1;

	cout<<"Index, Pivot: "<<arr[i]<<" "<<pivot<<"\n";
	while (true)
    {
		do
        {
			i++;
		} while (arr[i] < pivot);

		do
        {
			j--;
		} while (arr[j] > pivot);

		if (i >= j)
        {
            printArray(arr, n);
            return j;
        }

		swap(arr[i], arr[j]);
	}
}

int partition_r(int arr[], int low, int high, int n)
{
	srand(time(NULL));
	int random = low + rand() % (high - low);

	swap(arr[random], arr[low]);

	return partition(arr, low, high, n);
}

void quickSort(int arr[], int low, int high, int n)
{
	if (low < high)
    {
		int pi = partition_r(arr, low, high, n);

		quickSort(arr, low, pi, n);
		quickSort(arr, pi + 1, high, n);
	}
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout<<arr[i]<<" ";

	cout<<"\n\n";
}

int main()
{
	int arr[] = {10, 5, 7, 9, 12, 17, 4, 8, 2, 11};
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1, n);

	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}

