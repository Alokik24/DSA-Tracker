// Leetcode Problem : 347 Top K Frequent Elements
// Link: https://leetcode.com/problems/top-k-frequent-elements/
// Category: HashMap, Sorting, Heap
// Difficulty: Medium

// Approach 1
// Using a HashMap to count frequncies and then sorting the elements based on their frequencies

// Time Complexity: O(n + m log m)
// (in worst case m = n, so becomes O(n log n))
// Space Complexity: O(n) for storing frequencies

#include <algorithm>
#include <unordered_map>
#include <vector>
#include <utility> // for std::pair
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) freq[num]++;
        
        vector<pair<int, int>> freqVec(freq.begin(), freq.end());
        sort(freqVec.begin(), freqVec.end(), [](auto& a, auto& b) {
            return a.second > b.second;  // sort by frequency descending
        });

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(freqVec[i].first);
        }

        return result;
    }
};

// Approach 2
// Using a min-heap to keep track of the top k frequent elements
// Time Complexity: O(n log k)
// Space Complexity: O(n) for storing frequencies

#include <queue>

class Solution {
public:
    typedef pair<int, int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) freq[num]++;
        
        priority_queue<P, vector<P>, greater<P>> pq;

        // Push element in min-heap maintaining size of k only
        for(auto &it: freq){
            int value = it.first;
            int freq = it.second;

            pq.push({freq, value});

            if(pq.size() > k) pq.pop();
        }

        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};

// Approach 3
// Using Bucket Sort to group elements by frequency
// T.C. -> O(n)
// S.C. -> O(n)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(auto &num: nums) mp[num]++;

        vector<vector<int>> bucket(n+1);
        // index -> freq, value -> elements
        // bucket[i] = elements having i frequency

        for(auto &it : mp){
            int element = it.first;
            int freq = it.second;

            bucket[freq].push_back(element);
        }

        // result - pick elements from right of bucket
        vector<int> result;
        for(int i = n; i>=0; i--){
            if(bucket.size() == 0) continue;
            while(bucket[i].size() > 0 && k > 0){
                result.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }
        return result;
    }
};