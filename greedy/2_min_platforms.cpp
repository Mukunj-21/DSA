//Problem: https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

// sabse pehle to dono arrays ko sort krlo , jab koi train aaegi to usko pichle dep se compare kro 
// agar vo train uske nikalne se pehle aagyi to platform add krna pdega aur agar vo train nikalne ke baad aayi 
// to platform ko reduce krdo kyuki usko platform ki zarurat nahi hai , pure time iterate krlo 
// and then return max platforms at any instant

class Solution {
    public:
      // Function to find the minimum number of platforms required at the
      // railway station such that no train waits.
      int findPlatform(vector<int>& arr, vector<int>& dep) {
          // Your code here
          int n = dep.size();
          sort(arr.begin() , arr.end());
          sort(dep.begin() , dep.end());
          int i = 1 , j = 0;
          int platforms = 1 , ans = 1;
          while(i<n && j<n){
              if(arr[i]<=dep[j]){
                  platforms++;
                  i++;
              }
              else{
                  platforms--;
                  j++;
              }
              ans = max(ans , platforms);
          }
          return ans;
      }
  };
  