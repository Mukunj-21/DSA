// Problem: https://leetcode.com/problems/merge-sorted-array/

// dono arrays sorted h 1-1 element ko choose krte jao aur jo bhi bada ho usko last me dalte jao 

class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int i = m-1;
            int j = n-1;
            int k = m+n-1;
            while(i>=0 && j>=0){
                if(nums1[i]>nums2[j])
                    nums1[k--] = nums1[i--];
                else
                    nums1[k--] = nums2[j--];
            }
            while(j>=0)
                nums1[k--] = nums2[j--];
        }
    };