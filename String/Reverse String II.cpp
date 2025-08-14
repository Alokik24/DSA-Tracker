// Leetcode Problem 541: Reverse String II
// Link: https://leetcode.com/problems/reverse-string-ii/description/
// Category: String
// Difficulty: Easy

#include <vector>
#include <string>
#include <algorithm>  // for std::swap
using namespace std;        
class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for (int i = 0; i < n; i += 2 * k) {
            // Reverse the first k characters in the current segment
            int left = i, right = min(i + k - 1, n - 1);
            while (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;  // Return the modified string
    }
};

// Approach: Two-pointer technique
// T.C. -> O(n) where n is the length of the string
// S.C. -> O(1) (in-place reversal)
// Note: The function reverses every 2k characters in the string, reversing the first k characters and leaving the next k characters unchanged. 
