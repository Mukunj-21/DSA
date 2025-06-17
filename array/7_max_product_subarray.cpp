class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int ans = INT_MIN;
            int n = nums.size();
            int pre = 1 , suf = 1;
            for(int i =0;i<n;i++){
                pre *= nums[i];
                suf *= nums[n-i-1];
                ans = max(ans , max(pre , suf));
                if(!pre)
                    pre = 1;
                if(!suf)
                    suf = 1;
            }
            return ans;
        }
    };