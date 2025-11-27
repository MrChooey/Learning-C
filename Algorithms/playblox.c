#include <stdio.h>
#define MAX 6

typedef struct {
	int elements[MAX];
	int lastIndx;
} *Tree;

// {5, 3, 2, 6, 1, 4}

void bubbleSortASC(int arr[]) {
	for (int i = 0; i < MAX - 1; i++) {
		for (int j = 0; j < MAX - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void bubbleSortDESC(int arr[]) {
	for (int i = MAX - 1; i > 0; i--) {
		for (int j = MAX - i; j > 0; j--) {
			if (arr[j] > arr[j - 1]) {
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}
}

void insertionSort(int arr[]) {
	for (int i = 1; i < MAX; i++) {
		int temp = arr[i];
		int j = i;
		for (; j > 0 && arr[j - 1] > temp; j++) {
			arr[j] = arr[j - 1];
		}
		arr[j] = temp;
	}
}

void selectionSort(int arr[]) {
	for (int i = 0; i < MAX; i++) {
		int smallest = i;
		int j = i + 1;
		for (; j < MAX; j++) {
			if (arr[j] < arr[smallest]) {
				smallest = j;
			}
		}
		if (smallest != i) {
			int temp = arr[smallest];
			arr[smallest] = arr[i];
			arr[i] = temp;
		}
	}
}

void maxHeapify(Tree T, int size, int parent) {
	int largest = parent;
	int left = parent * 2 + 1;
	int right = left + 1;

	if (largest < size && T->elements[left] > T->elements[largest]) {
		largest = left;
	}
	if (largest < size && T->elements[right] > T->elements[largest]) {
		largest = right;
	}

	// ...
}