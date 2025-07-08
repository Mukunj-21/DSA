//Problem: https://leetcode.com/problems/maximize-the-distance-to-closest-person/

// ek last pointer chala ke rkho aur jab koi seat filled hojaye to check for last ko check kro agar filled h to (i-last)/2 otherwise 
// i se ans update kro aur last ko update kro. at last jo trailing zeroes h unhe bhi consider krna h kyuki end me seat ni aayi 
// to vo case reh gya humse

class Solution {
    public:
        int maxDistToClosest(vector<int>& seats) {
            int n = seats.size();
            int ans = 0 , last = -1;
            for(int i = 0 ; i < n ; i++){
                if(seats[i]){
                    if(last==-1)
                        ans = i;
                    else
                        ans = max(ans , (i - last)/2);
                    last = i;
                }
            }
            ans = max(ans , n - 1 - last);
            return ans;
        }
    };