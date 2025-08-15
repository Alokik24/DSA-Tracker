// Leetcode 45 : Jump Game II
// Category: Greedy Algorithms
// Difficulty: Hard

// Problem Statement: Given an array of non-negative integers, where each element represents the maximum jump length at that position,
// find the minimum number of jumps to reach the last index from the first index.
// T.C. O(n), S.C. O(1)

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0, l = 0, r = 0;

        while(r < n-1){
            int farthest = 0;
            for(int i = l; i<= r; i++){
                farthest = max(nums[i] + i, farthest);
            }
            l = r+1;
            r = farthest;
            jumps++;
        }
        return jumps;
    }
};

// Example usage:
// int main() {
//     Solution sol;        
//     vector<int> nums = {2, 3, 1, 1, 4};
//     int result = sol.jump(nums);
//     cout << "Minimum jumps to reach the last index: " << result << endl;
//     return 0;
// }

// Note: The above code assumes that the input vector 'nums' contains non-negative integers representing
// the maximum jump length at each index. The output is an integer indicating the minimum number of
// jumps required to reach the last index from the first index.
// The algorithm uses a greedy approach to find the farthest reachable index in each jump, updating
// the left and right boundaries of the current jump range until it reaches the last index.
// The time complexity is O(n) and the space complexity is O(1).