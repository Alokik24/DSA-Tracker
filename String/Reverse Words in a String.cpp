// Problem Statement: Reverse Words in a String
// Leetcode Problem 151: Reverse Words in a String
// Link: https://leetcode.com/problems/reverse-words-in-a-string/description/
// Category: String
// Difficulty: Medium

#include <string>
#include <sstream>
#include <algorithm>  // for std::reverse
#include <vector>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // Remove leading and trailing spaces
        while (!s.empty() && s.back() == ' ') {
            s.pop_back();
        }
        while (!s.empty() && s.front() == ' ') {
            s.erase(s.begin());
        }

        // Split the string into words
        istringstream iss(s);
        vector<string> words;
        string word;
        while (iss >> word) {
            words.push_back(word);
        }

        // Reverse the order of words
        reverse(words.begin(), words.end());

        // Join the words with a single space
        string result;
        for (const auto& w : words) {
            if (!result.empty()) {
                result += ' ';
            }
            result += w;
        }

        return result;  // Return the final reversed string
    }
};