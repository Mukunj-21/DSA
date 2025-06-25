//Problem: https://leetcode.com/problems/single-element-in-a-sorted-array/

// simply socho ki agar mid element odd index par hai aur uska previous element usse barabar hai to iska matlab single element right side par hoga
// similarly agar mid element even index par hai aur uska next element usse barabar hai to iska matlab single element right side par hoga
// to hum low ko mid+1 kar denge otherwise left side me hoga to high ko mid-1 kar denge and at last return low element

class Solution {
    public:
        int singleNonDuplicate(vector<int>& nums) {
            int n = nums.size();
            if(n==1)
                return nums[0];
            if(nums[0]!=nums[1])
                return nums[0];
            if(nums[n-1]!=nums[n-2])
                return nums[n-1];
            int low = 1 , high = n-2;
            while(low<=high){
                int mid = low + (high-low)/2;
                if((nums[mid]!=nums[mid-1]) && (nums[mid]!=nums[mid+1]))
                    return nums[mid];
                else if((mid%2==1 && nums[mid] == nums[mid-1]) || (mid%2==0 && nums[mid] == nums[mid+1]))
                    low = mid+1;
                else
                    high = mid-1;
            }
            return nums[low];
        }
    };