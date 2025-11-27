#include <stdio.h>  

// Structure to store item details
typedef struct {
	int weight;
	int value;
} Item;

// Function to solve the knapsack problem
void knapsack(int capacity, Item items[], int n) {
	int dp[n + 1][capacity + 1];

	// Fill the DP table
	for (int i = 0; i <= n; i++) {
		for (int w = 0; w <= capacity; w++) {
			if (i == 0 || w == 0) {
				dp[i][w] = 0;  // Base case: no items or no capacity
			} else if (items[i - 1].weight <= w) {
				dp[i][w] = (items[i - 1].value + dp[i - 1][w - items[i - 1].weight] > dp[i - 1][w]) ? items[i - 1].value + dp[i - 1][w - items[i - 1].weight] : dp[i - 1][w];
			} else {
				dp[i][w] = dp[i - 1][w];  // Exclude item
			}
		}
	}

	// Maximum value
	int max_value = dp[n][capacity];
	printf("Maximum Value: %d\n", max_value);

	// Backtracking to find selected items
	int w = capacity;
	printf("Selected Items: ");
	for (int i = n; i > 0 && max_value > 0; i--) {
		if (max_value != dp[i - 1][w]) {
			printf("Item%d (Weight: %d, Value: %d) ", i, items[i - 1].weight, items[i - 1].value);
			max_value -= items[i - 1].value;
			w -= items[i - 1].weight;
		}
	}
	printf("\n");
}

// Main function
int main() {
	Item items[] = {
		{3, 4},	 // Item A (weight = 3, value = 4)
		{2, 3},	 // Item B (weight = 2, value = 3)
		{3, 5},	 // Item C (weight = 3, value = 5)
		{1, 2},	 // Item D (weight = 1, value = 2)
		{5, 9}	 // Item E (weight = 5, value = 9)
	};

	int n = sizeof(items) / sizeof(items[0]);
	int capacity = 7;  // Knapsack capacity

	knapsack(capacity, items, n);

	return 0;
}
