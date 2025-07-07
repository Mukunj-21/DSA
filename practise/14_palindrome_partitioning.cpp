//Problem : https://leetcode.com/problems/palindrome-partitioning/

// backtracking ki hi basic application yaad rkho bas ek word lo usko palindrome check kro if yes to add krdo fir use pop krke
// next possibility bhi check krlo 

class Solution {
    public:
        bool isPalindrome(string &s , int left , int right){
            while (left < right)
                if (s[left++] != s[right--])
                    return false;
            return true;
        }
        void solve(string &s , vector<vector<string>> &ans , vector<string> &word , int start){
            if(start == s.size()){
                ans.push_back(word);
                return;
            }
            for(int end = start ; end < s.size() ; end++){
                if(isPalindrome(s , start , end)){
                    word.push_back(s.substr(start , end - start + 1));
                    solve(s , ans , word , end + 1);
                    word.pop_back();
                }
            }
        }
        vector<vector<string>> partition(string s) {
            vector<vector<string>> ans;
            vector<string> word;
            solve(s , ans , word , 0);
            return ans;
        }
    };