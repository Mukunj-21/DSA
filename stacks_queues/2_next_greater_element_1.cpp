//Problem: https://leetcode.com/problems/next-greater-element-i/

// nums2 ko ulta traverse karte hain aur jab bhi koi element aata hai jo stack ke top se bada hota hai to stack ke top ko pop krdo
// aur usko map me store krdo. Agar stack khali hai to -1 store krdo.
// finally ans me nums1 ke elements ke liye map se value le lo 

class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            int n1 = nums1.size() , n2 = nums2.size();
            stack<int> st;
            vector<int> ans;
            unordered_map<int,int> m;
            for(int i=n2-1;i>=0;i--){
                while(!st.empty() && nums2[i]>st.top())
                    st.pop();
                if(st.empty())
                    m[nums2[i]] = -1;
                else
                    m[nums2[i]] = st.top();
                st.push(nums2[i]);
            }
            for(int i=0;i<n1;i++)
                ans.push_back(m[nums1[i]]);
            return ans;
        }
    };