// Problem: https://leetcode.com/problems/top-k-frequent-elements/

// Pehli approach to hai ki map me frequency nikal lo aur fir kisi vector me vo frequencies daal ke sort krdo aur top k return krdo
// Second good approach is kisi vector ko use krne ki jagah priority queue use krlo which automatically stores it in sorted order
// min heap ka use krenge aur jo sabse kam value hogi frequency ki use pop krte rhenge agar pq.size() > k
// bas last me jitne elements pq me honge sab hamare answer hai to return krwado 

// class Solution {
// public:
//     static bool cmp(pair<int, int>& a, pair<int, int>& b){ 
//         return a.second > b.second; 
//     }
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int,int> freq;
//         for(auto num:nums)
//             freq[num]++;

//         vector<pair<int , int>> v(freq.begin(),freq.end());
//         sort(v.begin(),v.end(),cmp);

//         vector<int> ans;

//         for(int i=0;i<k;i++)
//             ans.push_back(v[i].first);
//         return ans;
//     }
// };

class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int,int> freq;
            for(auto num:nums)
                freq[num]++;
            priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
            for(auto &[a,b]:freq){
                pq.push({b,a});
                if(pq.size()>k)
                    pq.pop();
            }
            vector<int> ans;
            while(!pq.empty()){
                ans.push_back(pq.top().second);
                pq.pop();
            }
            return ans;
        }
    };