//Problem : https://leetcode.com/problems/generate-parentheses/description/

// Recursion se solve krne ki try kro kyuki kaafi possibilities ho skti hai ek baar open bracket daalo 
// fir agar close ka count open se jda h to close ko daal do

class Solution {
    public:
        void solve(int m , int n , char a , char b , vector<string> &ans , string &temp){
            if(m==0 && n==0){
                ans.push_back(temp);
                return;
            }
            if(m>0){
                temp.push_back(a);
                solve(m-1 , n , a , b , ans , temp);
                temp.pop_back();
            }
            if(n>m){
                temp.push_back(b);
                solve(m , n-1 , a , b , ans , temp);
                temp.pop_back();
            }
        }
        vector<string> generateParenthesis(int n) {
            char a = '(' , b = ')';
            vector<string> ans;
            string temp="";
            solve(n ,n ,a , b , ans , temp);
            return ans;
        }
    };