//Problem: https://leetcode.com/problems/majority-element-ii/description/

// agar hume check krna hai ki kon konse elements n/3 se jda baar aaye hai to simple hai ki ans me sirf 2 hi elements ho skte hai 
// isliye hum 2 elements ko track krenge aur unki count ko bhi track krenge jese pehle kiya tha but ab hume pta to chal gya konse element liye hai humne count me 
// but what's the surety for the fact that they are actually the majority elements? to ek loop aur lgake un elements ko count krenge
// if greater than n/3 then push them in ans

class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            vector<int> ans;
            int count1 = 0 , count2 = 0 , element1 , element2;
            for(int i=0;i<nums.size();i++){
                if(count1==0 && nums[i] != element2){
                    element1 = nums[i];
                    count1++;
                }
                else if(count2==0 && nums[i] != element1){
                    element2 = nums[i];
                    count2++;
                }
                else if(nums[i] == element1)
                    count1++;
                else if(nums[i] == element2)
                    count2++;
                else
                    count1-- , count2--;
            }
            count1 = 0 , count2 = 0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]==element1)
                    count1++;
                if(nums[i]==element2)
                    count2++;
            }
            if(count1>nums.size()/3)
                ans.push_back(element1);
            if(count2>nums.size()/3)
                ans.push_back(element2);
            return ans;
        }
    };