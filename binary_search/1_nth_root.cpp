//Problem: https://practice.geeksforgeeks.org/problems/nth-root-of-a-number3351/1

// basic approach is 1 se m/n tk loop chala lo agar agar i^n == m to return i agar value badi hojaye to break krdo answer ni aaega
// second approach is binary search se eliminate krte jao agar mid^n == m to return mid agar mid^n < m to low = mid+1 else high = mid-1
// Time complexity is O(nlogm) and space complexity is O(1)


// int NthRoot(int n, int m) {
//     // int ans = -1;
//   for(int i=0;i<m/n;i++){
//     if(pow(i,n)==m)
//       return i;
//     else if(pow(i,n)>m){
//       break;
//     }
//   }
//   return -1;
// }

int helper(int n , int m , int mid){
    long long ans = 1;
    for(int i=1;i<=n;i++){
      ans *= mid;
      if(ans>m)
        return 2;
    }
    if(ans == m){
      return 1;
    }
    return 0;
  }
  int NthRoot(int n, int m) {
    int low = 1 , high = m;
    while(low<=high){
      int mid = low + (high-low)/2;
      int ans = helper(n , m , mid);
      if(ans == 1){
        return mid;
      }else if(ans == 0){
        low = mid+1;
      }else{
        high = mid-1;
      }
    }
    return -1;
  }