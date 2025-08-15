// Leetcode 238 : Product of Array Except Self
// https://leetcode.com/problems/product-of-array-except-self/

#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1);
        for(int i = 1; i<n; i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }
        int suffix = 1;
        for(int i = n-1; i>=0; i--){
            prefix[i] *= suffix; 
            suffix *= nums[i];
        }
        return prefix;
    }
};

// Example usage:
// int main() {
//     Solution sol;
//     vector<int> nums = {1, 2, 3, 4};
//     vector<int> result = sol.productExceptSelf(nums);
//     for(int val : result) {
//         cout << val << " ";
//     }
//     cout << endl;
//     return 0;
// }
// Note: The above code calculates the product of all elements in the array except the current element
// using a prefix and suffix product approach. The time complexity is O(n) and the space
// complexity is O(n) for the prefix array. The algorithm avoids using division and handles cases
// where the array contains zeros correctly by calculating products in two passes: one for prefix products
// and another for suffix products. The final result is stored in the prefix array, which is returned as the output.