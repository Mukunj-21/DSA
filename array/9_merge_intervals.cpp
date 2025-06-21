//Problem : https://leetcode.com/problems/merge-intervals/

// sort the given intervals based on the starting value
// agar khaali hai ans to insert krdo next agar starting value ans me dale hue end ki value se choti hai to merge kr rha h 
// to fir jiske end ki value badi hogi vo add hojaega 

class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            vector<vector<int>> ans;
            int n = intervals.size();
            sort(intervals.begin(),intervals.end());
            for(int i=0;i<n;i++){
                if(ans.empty() || ans.back()[1] < intervals[i][0])
                    ans.push_back(intervals[i]);
                else
                    ans.back()[1] = max(ans.back()[1] , intervals[i][1]);
            }
            return ans;
        }
    };