// Problem : https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399?leftPanelTabValue=PROBLEM

// 2 pointers use karo left to 0 and initially right also at 0 sum add krte jao agar sum jda hojaye required se to left se utna 
// hatate jao nahi to right se aage badhte jao aur sum ko add krte jao agar sum required ban jaye to max length update krdo 

#include<bits/stdc++.h>
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int n = a.size();
    int left = 0 , right = 0;
    long long sum = a[0];
    int ans = 0;
    while(right<n){
        while(left <= right && sum > k ){
            sum -= a[left];
            left++;
        }
        if(sum==k)
            ans = max(ans , right-left+1);
        right++;
        if(right<n)
            sum += a[right];
    }
    return ans;
}