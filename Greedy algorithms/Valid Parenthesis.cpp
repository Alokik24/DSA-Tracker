// LeetCode 678. Valid Parenthesis String
// Link: https://leetcode.com/problems/valid-parenthesis-string/description/
// Category: Greedy Algorithms, Stack, Dynamic Programming
// Difficulty: Medium

// T.C. -> O(n)
// S.C. -> O(1)

// Approach: Greedy Algorithm


#include <string>
using namespace std;


class Solution {
public:
    bool checkValidString(string s) {
        // 'min' = minimum possible number of unmatched '(' so far
        // 'max' = maximum possible number of unmatched '(' so far
        int min = 0, max = 0;

        // Loop through each character in the string
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                // A '(' always increases both min and max
                // → Minimum possible '(' increases by 1
                // → Maximum possible '(' also increases by 1
                min = min + 1;
                max = max + 1;
            }
            else if (s[i] == ')') {
                // A ')' always decreases both min and max
                // → Minimum possible '(' decreases by 1
                // → Maximum possible '(' also decreases by 1
                min = min - 1;
                max = max - 1;
            }
            else { // s[i] == '*'
                // '*' can act as '(' or ')' or empty
                // → If we treat '*' as ')', min decreases by 1
                // → If we treat '*' as '(', max increases by 1
                min = min - 1;
                max = max + 1;
            }

            // 'min' should never go below 0
            // If it becomes negative, it means in the "most closing-heavy" interpretation,
            // we closed more '(' than we had — but we can treat extra ')' as empty in this case.
            if (min < 0) min = 0;

            // If 'max' is negative, even in the "most opening-heavy" interpretation,
            // we have more ')' than '(' — this is invalid immediately.
            if (max < 0) return false;
        }

        // If 'min' is 0 at the end, it means there exists at least one valid interpretation
        // where all '(' are matched and closed.
        return (min == 0);
    }
};
