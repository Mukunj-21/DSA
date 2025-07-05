// Problem : https://leetcode.com/problems/zigzag-conversion/


// class Solution {
// public:
//     string convert(string s, int numRows) {
//         int n = s.size();
//         if(numRows==1 || numRows >= n)
//             return s;
//         int ind = 0 , next = 1;
//         vector<vector<char>> v(numRows);
//         for(char c : s){
//             v[ind].push_back(c);
//             if(ind == 0)
//                 next = 1;
//             else if(ind == numRows-1)
//                 next = -1;
//             ind += next;
//         }
//         string ans;
//         for(auto row:v)
//             for(char c :row)
//                 ans.push_back(c);
//         return ans;
//     }
// };


class Solution {
    public:
        string convert(string s, int numRows) {
            int n = s.size();
            if(numRows == 1 || numRows >= n)
                return s;
            string ans = "";
            int cycle = 2*numRows - 2;
            for(int i=0 ; i<numRows ; i++){
                for(int j=0 ; j+i < n ; j += cycle){
                    ans += s[i+j];
                    int next = j + cycle - i;
                    if(i!=0 && i!=numRows-1 && next < n)
                        ans += s[next];
                }
            }
            return ans;
        }
    };