// Leetcode Problem 455: Assign Cookies
// Link: https://leetcode.com/problems/assign-cookies/description/
// Category: Greedy Algorithms
// Difficulty: Easy

#include <vector>
#include <algorithm>  // for std::sort
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Sort the greed factor of children and the size of cookies
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());           

        int childIndex = 0;  // Index for children
        int cookieIndex = 0; // Index for cookies

        // Iterate through both arrays to find content children
        while (childIndex < g.size() && cookieIndex < s.size()) {
            // If the current cookie can satisfy the current child's greed
            if (s[cookieIndex] >= g[childIndex]) {
                childIndex++;  // Move to the next child
            }
            cookieIndex++;  // Move to the next cookie
        }
        return childIndex;  // Return the number of content children
    }
};
// Approach: Greedy algorithm
// T.C. -> O(n log n + m log m) where n is the number
// of children and m is the number of cookies (due to sorting)
// S.C. -> O(1) (in-place sorting)
// Note: The function finds the maximum number of children that can be content with the given cookies
// by sorting both arrays and using a two-pointer technique to match cookies to children based on their
// greed factor. It ensures that each child is satisfied with the smallest possible cookie that meets their need.
// This approach is efficient and straightforward, making it suitable for the problem at hand.
// The function returns the count of content children, which is the maximum number of children that can be satisfied with the available cookies.
// The greedy approach ensures that we always try to satisfy the least greedy child first with the smallest available cookie.
// This way, we maximize the number of content children.
