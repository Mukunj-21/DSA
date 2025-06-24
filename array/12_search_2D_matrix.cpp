// Problem Link: https://leetcode.com/problems/search-a-2d-matrix/

// pehli approach to yahi hai ki har row mein binary search kar lo lekin isse time complexity O(m*log(n)) ho jayegi
// dusri approach hai ki matrix ko 1D array mein convert kar do aur binary search kar lo isse time complexity O(log(m*n)) ho jayegi
// aur ye flatten hoga kese low = 0 but high will be last element which is m*n-1 and then mid to nikal jaega 
// lekin mid ko row aur column mein convert karna padega to row jo hogi mid/n hogi aur column mid%n hogi

// class Solution {
// public:
//     bool binarySearch(vector<int> &v , int target){
//         int low = 0 , high = v.size()-1;
//         while(low<=high){
//             int mid = low + (high-low)/2;
//             if(v[mid]==target)
//                 return true;
//             else if(v[mid]<target)
//                 low = mid+1;
//             else
//                 high = mid-1;
//         }
//         return false;
//     }
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size();
//         int n = matrix[0].size()-1;
//         for(int i=0;i<m;i++){
//             if(matrix[i][0]<=target && matrix[i][n]>=target)
//                 return binarySearch(matrix[i] , target);
//         }
//         return false;
//     }
// };

class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int m = matrix.size();
            int n = matrix[0].size();
            int low = 0 , high = m*n-1;
            while(low<=high){
                int mid = low + (high-low)/2;
                int row = mid/n , col = mid%n;
                if(matrix[row][col] == target)
                    return true;
                else if(matrix[row][col] > target)
                    high = mid-1;
                else
                    low = mid+1;
            }
            return false;
        }
    };