// Problem: https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/



class Solution {
    public:
        int minDeletions(string s) {
            vector<int> count(26,0);
            for(char &ch:s)
                count[ch-'a']++;
            sort(count.rbegin() , count.rend());
            
            // int ans = 0;
            // unordered_set<int> freq;
            // for(auto &c : count){
            //     while(c>0 && freq.count(c)){
            //         c--;
            //         ans++;
            //     }
            //     freq.insert(c);
            // }
            // return ans;
    
            int ans = 0 , max = count[0]-1;
            for(int i=1;i<26;i++){
                if(count[i]>max)
                    ans += count[i] - max;
                if(max > 0 && count[i] !=0)
                    max = min(max-1 , count[i]-1);
            }
            return ans;
        }
    };