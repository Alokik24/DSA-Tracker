// Leetcode Problem 344: Reverse String
// Link: https://leetcode.com/problems/reverse-string/description/
// Category: String
// Difficulty: Easy

#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            swap(s[left], s[right]);  // Swap characters at left and right indices
            left++;                    // Move left pointer to the right
            right--;                   // Move right pointer to the left
        }
    }
};

// Approach: Two-pointer technique
// T.C. -> O(n)
// S.C. -> O(1) (in-place reversal)

// Note: The input is a vector of characters, and the function modifies it in place to reverse the string.
// This solution is efficient and straightforward, leveraging the two-pointer technique to swap characters until the entire string is reversed.
// The function does not return anything as it modifies the input vector directly.
