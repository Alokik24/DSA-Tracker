// Minimum Coins Problem

// Problem Statement: Given a set of coin denominations and a target amount, find the minimum number
// of coins needed to make that amount. If it's not possible to make the amount, return -1.

// Link: https://leetcode.com/problems/coin-change/description/
// Category: Greedy Algorithms


#include <iostream>
#include <vector>
#include <algorithm>  // for std::min
using namespace std;    

int minCoins(vector<int>& coins, int amount){
    int n= coins.size();
    int count = 0;
    for(int i = n-1; i>=0; i++){
        if(coins[i] > amount || coins[i] == 0){
            continue;
        }
        // Use as many coins of this denomination as possible
        count += amount/coins[i];
        amount %= coins[i]; 
        // If the amount becomes zero, we can stop
        if(amount == 0){
            return count;  // Return the total count of coins used
        }

    }
    return -1;  // If we cannot make the amount with the given coins, return -1
}

int main() {
    vector<int> coins = {1, 5, 10, 25};  // Coin denominations
    int amount = 63;  // Target amount

    int result = minCoins(coins, amount);
    if (result != -1) {
        cout << "Minimum coins needed: " << result << endl;
    } else {
        cout << "Cannot make the amount with the given coins." << endl;
    }
    return 0;  // Exit the program
}