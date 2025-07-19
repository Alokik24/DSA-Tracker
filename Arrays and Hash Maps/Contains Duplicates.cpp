
// LeetCode Problem: 217. Contains Duplicates
// Link: https://leetcode.com/problems/contains-duplicate/description/
// Category: Array, HashMap, Sortign
// Difficulty: Easy

// Approach 1

// Using Sorting
// T.C. -> O(n log n)
// S.C. -> O(1) if we sort in place, O(n) if we use extra space for sorting
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
                return true;
        }
        return false;
    }
};

// Approach 2
// Using HashSet
// T.C. -> O(n)
// S.C. -> O(n)

#include <unordered_set>
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> s(nums.begin(), nums.end());
        return s.size() != nums.size();
    }
};

// Approach 3
// Using HashMap
// T.C. -> O(n)
// S.C. -> O(n)

#include <unordered_map>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(const int& num: nums){
            freq[num]++;
            if(freq[num]>1) return true;
        }
        return false;
    }
};