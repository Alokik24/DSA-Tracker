// Leetcode Problem: N Meetings in One Room

// Category: Greedy Algorithms
// Difficulty: Medium

// Problem Statement: Given N meetings in one room, find the maximum number of meetings that can be accommodated in the room.
// Approach: Greedy Algorithm

#include <vector>
#include <algorithm>
using namespace std;

class Meeting {
public:
    int start;
    int end;        
    int index;       // To keep track of the original index of the meeting
    Meeting(int s, int e, int i) : start(s), end(e), index(i) {}
};

bool compare(Meeting m1, Meeting m2) {
    return m1.end < m2.end; // Sort by end time
}

class Solution {
public:
    vector<int> maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<Meeting> meetings;
        for (int i = 0; i < n; i++) {
            meetings.push_back(Meeting(start[i], end[i], i + 1)); // Store original index
        }
        sort(meetings.begin(), meetings.end(), compare); // Sort meetings by end time
        vector<int> result;
        int lastEndTime = 0; // Track the end time of the last selected meeting
        for (const Meeting& meeting : meetings) {
            if (meeting.start > lastEndTime) { // If the meeting starts after the last selected meeting ends
                result.push_back(meeting.index); // Add the meeting index to the result
                lastEndTime = meeting.end; // Update the end time
            }
        }
        return result; // Return the indices of the meetings that can be accommodated
    }
};  

// Example usage:
// int main() {
//     Solution sol;
//     vector<int> start = {1, 3, 0, 5, 5, 8, 5};
//     vector<int> end =   {2, 4, 6, 7, 9, 9, 10};
//     vector<int> result = sol.maxMeetings(start, end);
//     for (int index : result) {
//         cout << index << " "; // Output the indices of the meetings
//     }
//     return 0;
// }

// Note: The above code assumes that the input vectors 'start' and 'end' are of the same size and contain valid meeting times.
// The meetings are represented by their start and end times, and the output is a vector of indices of the meetings that can be accommodated in the room.
