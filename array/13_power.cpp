// Problem Statement: https://leetcode.com/problems/powx-n/

// is way me socho ki agar n odd hai to answer me ek baar multiply kardo aur agar even hai to usko square kar do 
// taaki iterations kam hojaye time save hoga bas jab tk nn 0 nahi hojata karte rho aur last me agar n -ve tha to 1 se divide krdena

class Solution {
    public:
        double myPow(double x, int n) {
            double ans = 1.0;
            long nn = abs(long(n));
            while(nn){
                if(nn & 1){
                    ans *= x;
                    nn--;
                }
                else{
                    x *= x;
                    nn /= 2;
                }
            }
            if(n<0)
                ans = 1.0/ans;
            return ans;
        }
    };