#include <stdio.h>

void findBestDays(int prices[], int size, int *buyDay, int *sellDay) {
    if (size < 2) {
        *buyDay = -1;
        *sellDay = -1;
        return; // Not enough days to make a profit
    }

    int minPriceIndex = 0; // Index of the minimum price seen so far
    int maxProfit = 0;     // Maximum profit
    *buyDay = 0;
    *sellDay = 0;

    for (int i = 1; i < size; i++) {
        int profit = prices[i] - prices[minPriceIndex];

        // Update maximum profit and the sell day
        if (profit > maxProfit) {
            maxProfit = profit;
            *buyDay = minPriceIndex;
            *sellDay = i;
        }

        // Update the minimum price index if a lower price is found
        if (prices[i] < prices[minPriceIndex]) {
            minPriceIndex = i;
        }
    }
}

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4}; // Example prices
    int size = sizeof(prices) / sizeof(prices[0]);
    int buyDay, sellDay;

    findBestDays(prices, size, &buyDay, &sellDay);

    if (buyDay == -1 || sellDay == -1) {
        printf("Not enough data to determine the best days to buy and sell.\n");
    } else {
        printf("Best day to buy: Day %d (Price: %d)\n", buyDay + 1, prices[buyDay]);
        printf("Best day to sell: Day %d (Price: %d)\n", sellDay + 1, prices[sellDay]);
    }

    return 0;
}
