// Problem : Minimum Platforms Required for a Railway Station
// Category: Greedy Algorithms
// Difficulty: Medium

// Problem Statement: Given arrival and departure times of trains at a railway station, find the minimum number of platforms required
// such that no train waits at the station.

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        sort(arr.begin(), arr.end()); // Sort arrival times
        sort(dep.begin(), dep.end()); // Sort departure times
        int platforms = 0, maxPlatforms = 0;
        int i = 0, j = 0;
        while(i < n){
            if(arr[i] <= dep[j]){
                platforms++; // A train arrives, increase platform count
                maxPlatforms = max(maxPlatforms, platforms); // Update maximum platforms needed
                i++; // Move to the next train arrival
            } else {
                platforms--; // A train departs, decrease platform count
                j++; // Move to the next train departure    
            }
        }
        return maxPlatforms; // Return the maximum number of platforms needed
    }
};  


// Example usage:
// int main() {
//     Solution sol;
//     vector<int> arr = {10, 15, 20};
//     vector<int> dep = {12, 17, 25};
//     int result = sol.findPlatform(arr, dep);
//     cout << "Minimum number of platforms required: " << result << endl;
//     return 0;
// }

// Note: The above code assumes that the input vectors 'arr' and 'dep' contain the arrival and departure times of trains respectively.
// The output is an integer indicating the minimum number of platforms required at the railway station to ensure
// that no train has to wait. The algorithm uses a greedy approach by sorting the arrival and
// departure times and then iterating through them to count the number of platforms needed at any point in time.
// The time complexity is O(n log n) due to sorting, and the space complexity is O(1) for the platform count.
