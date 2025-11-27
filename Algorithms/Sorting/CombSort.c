#include <stdio.h>
#define MAX 6

void combSort(int arr[]) {
	int gap = MAX;
	float shrink = 1.3;
	int sorted = 0;

	while (gap > 1 || sorted == 0) {
		gap = (int)(gap / shrink);
		if (gap < 1) gap = 1;

		sorted = 1;
		for (int i = 0; i < MAX - gap; i++) {
			if (arr[i] > arr[i + gap]) {
				int temp = arr[i];
				arr[i] = arr[i + gap];
				arr[i + gap] = temp;
				sorted = 0;
			}
		}
	}

	printf("Comb Sort:");
	for (int i = 0; i < MAX; i++) printf(" %d", arr[i]);
}

int main(void) {
	int arr[] = {5, 3, 2, 6, 1, 4};

	printf("Unsorted List: {5, 3, 2, 6, 1, 4}\n");
	combSort(arr);

	return 0;
}