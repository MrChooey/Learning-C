#include <stdio.h>
#define MAX 6

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pivot = arr[low];
		int i = low - 1;
		int j = high + 1;

		while (1) {
			do {
				i++;
			} while (arr[i] < pivot);

			do {
				j--;
			} while (arr[j] > pivot);

			if (i >= j) break;

			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}

		quickSort(arr, low, j);
		quickSort(arr, j + 1, high);
	}
}

int main(void) {
	int arr[] = {5, 3, 2, 6, 1, 4};

	printf("Unsorted List: {5, 3, 2, 6, 1, 4}\n");
	quickSort(arr, 0, MAX - 1);

	printf("Quick Sort:");
	for (int i = 0; i < MAX; i++) printf(" %d", arr[i]);

	return 0;
}