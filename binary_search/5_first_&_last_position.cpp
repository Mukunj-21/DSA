// Problem :https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

// 2 functions bana lo first and last search last function me agar value mil jaye use to store krlo lekin low ko mid+1 firse krdo
// taaki dubara search kre ek aur occurence aati h ya nhi agar aagyi to aise kr krke hume last position mil jayegi
// similarly for the first position firse search krte waqt agar value mil jaye to high ko mid-1 krdo

class Solution {
    public:
        int lastSearch(vector<int>& nums, int target){
            int low = 0 , high = nums.size()-1;
            int val = -1;
            while(low<=high){
                int mid = low + (high - low)/2;
                if(nums[mid]==target){
                    val = mid;
                    low = mid+1;
                }
                else if(nums[mid]>target)
                    high = mid-1;
                else
                    low = mid+1;
            }
            return val;
        }
        int firstSearch(vector<int>& nums, int target){
            int low = 0 , high = nums.size()-1;
            int val = -1;
            while(low<=high){
                int mid = low + (high - low)/2;
                if(nums[mid]==target){
                    val = mid;
                    high = mid-1;
                }
                else if(nums[mid]>target)
                    high = mid-1;
                else
                    low = mid+1;
            }
            return val;
        }
        vector<int> searchRange(vector<int>& nums, int target) {
            return {firstSearch(nums,target) , lastSearch(nums,target)};
        }
    };