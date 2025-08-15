// Leetcode Problem : Jump Game
// Category: Greedy Algorithms
// Difficulty: Medium

// Problem Statement: Given an array of non-negative integers, where each element represents the maximum jump length at that position,
// determine if you can reach the last index starting from the first index. 

// T.C. O(n), S.C. O(1)

#include <vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0; // The maximum index we can reach so far
        for (int i = 0; i < n; i++) {
            if (i > maxReach) {
                return false; // If we reach an index that is beyond the maximum reachable index, return
            }
            maxReach = max(maxReach, i + nums[i]); // Update the maximum reachable index
            if (maxReach >= n - 1) {
                return true; // If we can reach or exceed the last index, return true
            }
        }
        return false; // If we finish the loop without reaching the last index, return false
    }
};          

// Example usage:
// int main() {
//     Solution sol;
//     vector<int> nums = {2, 3, 1, 1, 4};
//     bool result = sol.canJump(nums);
//     cout << (result ? "Can jump to the last index" : "Cannot jump to the last index") << endl;
//     return 0;
// }
// Note: The above code assumes that the input vector 'nums' contains non-negative integers representing
// the maximum jump length at each index. The output is a boolean indicating whether it is possible
// to reach the last index from the first index.

