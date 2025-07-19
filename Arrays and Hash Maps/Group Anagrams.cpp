
// LeetCode Problem: 49. Group Anagrams
// Link: https://leetcode.com/problems/group-anagrams/description/
// Category: HashMap, Sorting, String
// Difficulty: Medium


// Input: ["eat", "tea", "tan", "ate", "nat", "bat"]

// After sorting:
// - "eat" → "aet"
// - "tea" → "aet"
// - "tan" → "ant"
// - "ate" → "aet"
// - "nat" → "ant"
// - "bat" → "abt"

// Groups:
// {
//   "aet": ["eat", "tea", "ate"],
//   "ant": ["tan", "nat"],
//   "abt": ["bat"]
// }


// Approach 1
// Using Sorting and HashMap
// T.C. -> O(n * k log k) where n is the number of strings
// and k is the maximum length of a string
// S.C. -> O(n * k) for storing the result

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;
        for(string s: strs){
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }

        vector<vector<string>> result;
        for(auto &pair: mp){
            result.push_back(pair.second);
        }
        return result;
    }
};