//Problem Statement: https://www.geeksforgeeks.org/build-min-heap-from-given-array/
//Problem Statement: https://www.geeksforgeeks.org/build-max-heap-from-given-array/

// Heap is basically a complete binary tree which satisfies that the given element should ne lesser/greater than its children.
// to hum array ke saath implement karte hai heap ko 
// 0 based Index - parent = i/2 , left child = 2*i + 1 , right child = 2*i + 2
// 1 based Index - parent = i/2 , left child = 2*i , right child = 2*i + 1

#include <bits/stdc++.h> 
void minHeapify(vector<int> &arr , int n , int i){
    
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[smallest] > arr[left])
        smallest = left;

    if(right < n && arr[smallest] > arr[right])
        smallest = right;

    if(smallest != i){
        swap(arr[smallest] , arr[i]);
        minHeapify(arr , n , smallest);
    }
}

void maxHeapify(vector<int> &arr , int n , int i){
    
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[largest] < arr[left])
        largest = left;

    if(right < n && arr[largest] < arr[right])
        largest = right;

    if(largest != i){
        swap(arr[largest] , arr[i]);
        minHeapify(arr , n , largest);
    }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    int n = arr.size();
    for(int i=n/2-1;i>=0;i--)
        minHeapify(arr , n , i);
    return arr;
}