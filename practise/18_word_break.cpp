// Problem : https://leetcode.com/problems/word-break/

// normally iterate kro string me 0 se n-1 tak inside it har word ke liye bhi iterate kro jo dictionary me hai 
// agar i ki value word ki length se choti hai to continue krdo kyuki koi use ka ni h but if i == word ki length - 1 or 
// dp[i - word ki length] is true then check if s.substr(i - word ki length + 1 , word ki length) == word if yes then 
// dp me uski value true store kro kyuki yes word break ho raha hai at last return what dp[n-1] has 

class Solution {
    public:
        bool wordBreak(string s, vector<string>& wordDict) {
            int n = s.length();
            vector<bool> dp(n , false);
            for(int i=0;i<n;i++){
                for(auto word : wordDict){
                    int d = word.length();
                    if(i<d-1)
                        continue;
                    if(i == d-1 || dp[i-d])
                        if(s.substr(i - d + 1 , d) == word){
                            dp[i] = true;
                            break;
                        }
                }
            }
            return dp[n-1];
        }
    };