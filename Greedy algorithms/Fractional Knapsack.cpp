// Fractional Knapsack Problem

// Category: Greedy Algorithms

// Difficulty: Medium

// Problem Statement: Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that you can break items for maximizing the total value in the knapsack.
#include <iostream>
#include <vector>
#include <algorithm>  // for std::sort
using namespace std;        

struct Item {
    int value;
    int weight;
    double ratio;
    Item(int v, int w) : value(v), weight(w) {
        ratio = static_cast<double>(v) / w;

    }
};

bool compare(const Item& a, const Item& b){
    return a.ratio > b.ratio; 
}

double fractionalKnapsack(int W, vector<int> Items){
    vector<Item> itemList;
    for (int i = 0; i < Items.size(); i += 2) {
        itemList.emplace_back(Items[i], Items[i + 1]);
    }

    // Sort items by value-to-weight ratio in descending order
    sort(itemList.begin(), itemList.end(), compare);

    double totalValue = 0.0;  // Total value in the knapsack
    int currentWeight = 0;     // Current weight in the knapsack

    for (const auto& item : itemList) {
        if (currentWeight + item.weight <= W) {
            // If the whole item can be added
            currentWeight += item.weight;
            totalValue += item.value;
        } else {
            // If only a fraction of the item can be added
            int remainingWeight = W - currentWeight;
            totalValue += item.ratio * remainingWeight;
            break;  // Knapsack is full
        }
    }

    return totalValue;  // Return the maximum value that can be obtained
}

int main() {
    int W = 50;  // Capacity of the knapsack
    vector<int> Items = {60, 10, 100, 20, 120, 30};  // {value1, weight1, value2, weight2, ...}

    double maxValue = fractionalKnapsack(W, Items);
    cout << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;
}

// Approach: Greedy algorithm
// T.C. -> O(n log n) for sorting the items, where n is the
// number of items
// S.C. -> O(n) for storing the items in a vector
// Note: The function calculates the maximum value that can be obtained in a knapsack of capacity
// W by sorting the items based on their value-to-weight ratio and adding them to the knapsack until it is full.
// If an item cannot be fully added, it adds a fraction of the item to maximize the
// total value. The greedy approach ensures that we always take the most valuable items first, leading to an optimal solution for the fractional knapsack problem.
// The function returns the maximum value that can be obtained in the knapsack, which is the
// sum of the values of the items added to the knapsack, including any fractions of items that were added.
// The greedy approach ensures that we always take the most valuable items first, leading to an optimal
// solution for the fractional knapsack problem.
