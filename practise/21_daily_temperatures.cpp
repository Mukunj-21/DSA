// Problem : https://leetcode.com/problems/daily-temperatures/description/

// Stack ki next greater element waali approach yaad rkho bas agar koi bada element aaye to stack se pop krte jao 
// else stack me add krke agar stack khali ni h to top ke element ke hisab se no of days push krdo else 0

class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            int n = temperatures.size();
            vector<int> ans(n, 0);
            stack<int> st;
            for (int i = n - 1; i >= 0; i--) {
                while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                    st.pop();
                }
                if (!st.empty())
                    ans[i] = st.top() - i;
                st.push(i);
            }
            return ans;
        }
    };
