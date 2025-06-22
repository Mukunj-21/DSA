// Problem: https://leetcode.com/problems/happy-number/


class Solution {
    public:
        int next(int n){
            int total = 0;
            while(n>0){
                int digit = n%10;
                total += digit * digit;
                n /= 10;
            }
            return total;
        }
        bool isHappy(int n) {
            // unordered_set<int> s;
            // while(n != 1 && !s.count(n)){
            //     s.insert(n);
            //     n = next(n);
            // }
            // return n==1;
    
            int slow = n , fast = next(n);
            while(fast != 1 && slow != fast){
                slow = next(slow);
                fast = next(next(fast));
            }
            return fast==1;
        }
    };