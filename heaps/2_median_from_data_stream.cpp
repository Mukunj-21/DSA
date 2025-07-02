// Problem: https://leetcode.com/problems/find-median-from-data-stream/

// priority queue se implement karenge aur max heap aur min heap ko initialize karenge.
// max me lower half rkhenge aur min me upper half. median ke liye sorted bhi hona hi chahiye isliye aise kra
// lower me max heap isliye taaki median puche to sabse bada element hi mile aur upper me min heap isliye
// taaki median puche to sabse chota element hi mile.

class MedianFinder {
    public:
        priority_queue<int> maxHeap;
        priority_queue<int , vector<int> , greater<int>> minHeap;
        MedianFinder() {
        
        }
    
        void addNum(int num) {
            if(maxHeap.empty() || num <= maxHeap.top())
                maxHeap.push(num);
            else
                minHeap.push(num);
            if(maxHeap.size()>minHeap.size()+1){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            else if(maxHeap.size() < minHeap.size()){
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
        
        double findMedian() {
            if(minHeap.size() == maxHeap.size())
                return (minHeap.top()+maxHeap.top())/2.0;
            return double(maxHeap.top());
        }
    };
    
    /**
     * Your MedianFinder object will be instantiated and called as such:
     * MedianFinder* obj = new MedianFinder();
     * obj->addNum(num);
     * double param_2 = obj->findMedian();
     */