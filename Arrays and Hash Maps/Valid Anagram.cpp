
// LeetCode Problem: 242. Valid Anagram
// Link: https://leetcode.com/problems/valid-anagram/description/
// Category: HashMap, Sorting, String
// Difficulty: Easy

// Approach 1
// Using Sorting and Two Pointers
// T.C. -> O(n log n)
// S.C. -> O(1) if we sort in place, O(n) if we use extra space for sorting

#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};

// Approach 2
// Using HashMap - works for any character set (follow up for Unicode characters)
// T.C. -> O(n)
// S.C. -> O(1) – since English lowercase letters are bounded (max 26 keys in map)

#include <unordered_map>
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        unordered_map<char, int> freq;
        for(char c: s) freq[c]++;
        for(char c: t){
            freq[c]--;
            if(freq[c] < 0) return false;
        }
        return true;
    }
};

// Approach 3
// Using Array as a HashMap - even more optimized for English lowercase letters
// T.C. -> O(n)
// S.C. -> O(1) – since English lowercase letters are bounded (max
// 26 keys in array)

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        int count[26] = {0};
        for(char c: s) count[c - 'a']++;
        for(char c: t){
            count[c - 'a']--;
            if(count[c - 'a'] < 0) return false;
        }
        return true;
    }
};

