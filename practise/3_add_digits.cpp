//Problem: https://leetcode.com/problems/add-digits/



class Solution {
    public:
        int addDigits(int num) {
            if(!num)
                return 0;
            else if(!(num%9))
                return 9;
            else
                return num%9;
        }
    };