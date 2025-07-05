//Problem : https://leetcode.com/problems/container-with-most-water/

class Solution {
    public:
        int maxArea(vector<int>& height) {
            int left = 0 , right = height.size()-1;
            int ans = 0;
            while(left<right){
                if(height[left]<=height[right]){
                    ans = max(ans , (right-left)*height[left]);
                    left++;
                }
                else{
                    ans = max(ans , (right-left)*height[right]);
                    right--;
                }
            }
            return ans;
        }
    };