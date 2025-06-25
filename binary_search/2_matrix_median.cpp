// Problem : https://www.naukri.com/code360/problems/median-in-matrix_981178?leftPanelTabValue=PROBLEM

// efficiently soche to minimum and maximum number nikal lo ab jo exact answer h vo iske bich me hi kahi pe hoga to hum yaha pe
// binary search karenge and count karenge mid se niche kitne elements hai agar count m*n/2 se kam hai to iska matlab hume 
// mid se bada number chahiye to low ko mid+1 kar do warna high ko mid-1 kar do ab ye jo count kr rhe hai hum vo karenge 
// upperBound function se jo ki hume batayega ki mid se niche kitne elements hai ab jab low high se cross ho jayega to low ko return krdo 

#include <bits/stdc++.h> 

int upperBound(vector<int> &arr , int val , int m){
	int low = 0 , high = m-1;
	int ans = m;
	while(low<=high){
		int mid = low + (high-low)/2;
		if(arr[mid] > val){
			ans = mid;
			high = mid-1;
		}
		else{
			low = mid+1;
		}
	}
	return ans;
}

int helper(vector<vector<int> > &arr , int mid , int n, int m){
	int count = 0;
	for(int i=0;i<n;i++){
		count += upperBound(arr[i] , mid , m);
	}
	return count;
}

int findMedian(vector<vector<int> > &arr, int n, int m){
	int mini=INT_MAX , maxi=INT_MIN;
	for(int i=0;i<n;i++){
		mini = min(mini , arr[i][0]);
		maxi = max(maxi , arr[i][m-1]);
	}
	int low = mini , high = maxi;
	while(low<=high){
		int mid = low + (high-low)/2;
		int ans = helper(arr , mid , n , m);
		if(ans <= m*n/2){
			low = mid+1;
		}
		else{
			high = mid-1;
		}
	}
	return low;
}
