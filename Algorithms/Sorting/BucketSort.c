#include <stdio.h>
#include <stdlib.h>

void bucketSort(int arr[], int n) {
	int i, j;
	int count[n];
	
	for (i = 0; i < n; i++) count[i] = 0;
	
	for (i = 0; i < n; i++) (count[arr[i]])++;
	
	for (i = 0, j = 0; i < n; i++) {
		for (; count[i] > 0; (count[i])--) {
			arr[j++] = i;
		}
	}
}

int main(void) {
	int arr[] = {5, 3, 2, 6, 1, 4};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	printf("Unsorted List: {5, 3, 2, 6, 1, 4}\n");
	bucketSort(arr, n);
	
	printf("Bucket Sort:");
	for (int i = 0; i < n; i++) printf(" %d", arr[i]);
	
	return 0;
}