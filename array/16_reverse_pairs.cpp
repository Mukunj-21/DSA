// Problem : https://leetcode.com/problems/reverse-pairs/

// Difficult question 
// think like while doing the merge sort we can make ourself easy to calculate how many of the values which we can take 
// for any 2 sorted arrays we will check 1 element with rest of them vo jitno ka count satisfy krega uska next element utne to krega hi
// hume uske aage se us next element ke liye check krna hai aur bas count me add krdena hai 
// pehle jab merge sort karenge tabhi hume pata chalega ki humne kitne pairs count kiye hai
// fir merge karte waqt hum un pairs ko count kar lenge

class Solution {
    public:
        void merge(vector<int> &nums , int low , int mid , int high){
            vector<int> temp;
            int left = low , right = mid+1;
            while(left<=mid && right <= high){
                if(nums[left]<=nums[right]){
                    temp.push_back(nums[left]);
                    left++;
                }
                else{
                    temp.push_back(nums[right]);
                    right++;
                }
            }
            while(left<=mid){
                temp.push_back(nums[left]);
                left++;
            }
            while(right<=high){
                temp.push_back(nums[right]);
                right++;
            }
            for(int i=low ; i<=high;i++)
                nums[i] = temp[i-low];
        }
        int mergeSort(vector<int>&nums , int low , int high){
            int count = 0;
            if(low>=high)
                return count;
            int mid = low + (high-low)/2;
            count += mergeSort(nums , low , mid);
            count += mergeSort(nums , mid+1 , high);
            count += countPairs(nums , low , mid , high);
            merge(nums , low , mid , high);
            return count;
        }
    
        int countPairs(vector<int> &nums , int low , int mid , int high){
            int right = mid+1;
            int count = 0;
            for(int i=low ; i<=mid;i++){
                while(right<=high && long(nums[i])>2*long(nums[right]))
                    right++;
                count += right-(mid+1);
            }
            return count;
        }
        int reversePairs(vector<int>& nums) {
            int n = nums.size();
            return mergeSort(nums , 0 , n-1);
        }
    };