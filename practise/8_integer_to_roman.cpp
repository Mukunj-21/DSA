//Problem: https://leetcode.com/problems/integer-to-roman/

class Solution {
    public:
        string intToRoman(int num) {
            vector<pair<int, string>> roman = {
                {1000,"M"},
                {900,"CM"},
                {500,"D"},
                {400,"CD"},
                {100,"C"},
                {90,"XC"},
                {50,"L"},
                {40,"XL"},
                {10,"X"},
                {9,"IX"},
                {5,"V"},
                {4,"IV"},
                {1,"I"}
            };
            string ans = "";
            while(num){
                for(auto &[a,b]:roman){
                    while(num >= a){
                        ans += b;
                        num -= a;
                    }
                }
            } 
            return ans;
        }
    };