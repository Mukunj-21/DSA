// Problem : https://leetcode.com/problems/brick-wall/description/

// Ek hash map create krlo jisme har ke ek ek value ke liye count store hoga
// aur last me jo maximum count hoga usko n se minus krdo

class Solution {
    public:
        int leastBricks(vector<vector<int>>& wall) {
            unordered_map<long long , int> m;
            int ans = 0;
            int n = wall.size();
            for(int row = 0;row < n;row++){
                long long count = 0;
                for(int i=0;i<wall[row].size() - 1;i++){
                    count += wall[row][i];
                    m[count]++;
                    ans = max(ans , m[count]);
                    if(ans == n)
                        return 0;
                }
            }
            return wall.size() - ans;
        }
    };