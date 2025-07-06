//Problem : https://leetcode.com/problems/group-anagrams/

// Simple sochoge to agar har string ko sort krdo to anagrams same ho jayenge to bas ek map lo aur har sorted word me uska original
// word daal do.

class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string , vector<string>> m;
            vector<vector<string>> ans;
            for(auto str:strs){
                string temp = str;
                sort(temp.begin() , temp.end());
                m[temp].push_back(str);
            }
            for(auto& [a,b]:m)
                ans.push_back(b);
            return ans;
        }
    };