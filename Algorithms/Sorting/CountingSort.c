#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n) {
	int i, j, k;
	int max = arr[0];
	
	for (i = 1; i < n; i++) {
		if (arr[i] > max) max = arr[i];
	}
	
	int count[max + 1];
	
	for (i = 0; i <= max; i++) count[i] = 0;
	
	for (i = 0; i < n; i++) (count[arr[i]])++;
	
	for (i = 0, j = 0; i <= max; i++) {
		for (k = 0; k < count[i]; k++) {
			arr[j++] = i;
		}
	}
}

int main(void) {
	int arr[] = {5, 3, 2, 6, 1, 4};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	printf("Unsorted List: {5, 3, 2, 6, 1, 4}\n");
	countingSort(arr, n);
	
	printf("Counting Sort:");
	for (int i = 0; i < n; i++) printf(" %d", arr[i]);
	
	return 0;
}