// Problem: https://leetcode.com/problems/valid-parentheses/

// simple agar open brack hai to stack me daal do aur agar closed aaya and stack ke top pe usi ka open hai to pop kar do 
// bas empty stack me top waali condition nahi aani chahiye isliye agar stack empty hai aur closed aaya to false return kar do

class Solution {
    public:
        bool isValid(string s) {
            int n = s.size();
            stack<char> st;
            for(auto &ch : s){
                if(ch == '(' || ch == '[' || ch == '{')
                    st.push(ch);
                else{
                    if(st.empty())
                        return false;
                    if((ch==')' && st.top()=='(') || (ch==']' && st.top()=='[') || (ch=='}' && st.top()=='{'))
                        st.pop();
                    else
                        return false;
                }
            }
            return st.empty();
        }
    };