// Problem : https://leetcode.com/problems/two-city-scheduling/description/

// sort to normally krdenge lekin dono cities me kam se kam costs me pahuchana h isliye sort unke difference ke basis pe krdo

class Solution {
    public:
        int twoCitySchedCost(vector<vector<int>>& costs) {
            int ans = 0;
            sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[0] - a[1]) < (b[0] - b[1]);
            });
            int n = costs.size();
            for(int i=0 ; i<n/2 ; i++)
                ans += costs[i][0];
            for(int i=n/2 ; i<n ; i++)
                ans += costs[i][1];
            return ans;
        }
    };