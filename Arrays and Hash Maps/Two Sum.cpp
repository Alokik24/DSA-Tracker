// LeetCode Problem: 1. Two Sum
// Link: https://leetcode.com/problems/two-sum/description/
// Category: Array, HashMap
// Difficulty: Easy

// Approach 1
// Using Brute Force
// T.C. -> O(n^2)
// S.C. -> O(1)

#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++)
                if(nums[i] + nums[j] == target) return {i, j}; 
            }
            return {-1,-1};
        }
};


// Approach 2
// Using HashMap
// T.C. -> O(n)
// S.C. -> O(n)

#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;  // value -> index

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];

            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};  // Found the pair
            }

            mp[nums[i]] = i;  // Store current number with its index
        }

        return {-1, -1};  // Safe return, though usually guaranteed a solution exists
    }
};
