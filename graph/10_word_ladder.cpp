//Problem : https://leetcode.com/problems/word-ladder/

// ek set bana lo jisme saare wordList ke words ho taaki search O(1) me ho sake ab ek queue me word push kardo with its 
// level 1. ab jab tak queue khali na ho tab tak loop chalao. queue se front nikaalo aur check karo ki kya wo endWord hai agar haan
// to return level. ab word ke har character ko a se z tak change karke check karo ki kya wo set me hai agar haan to usko set se
// erase kardo aur queue me push kardo with level+1. phir word ke character ko original character pe wapas set kardo. agar queue khali ho gayi
// aur endWord nahi mila to return 0.

class Solution {
    public:
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            queue<pair<string , int>> q;
            q.push({beginWord , 1});
    
            unordered_set<string> st(wordList.begin() , wordList.end());
            st.erase(beginWord);
    
            while(!q.empty()){
                string word = q.front().first;
                int ans = q.front().second;
                q.pop();
    
                if(word == endWord)
                    return ans;
    
                for(int i=0;i<word.size();i++){
                    char ch = word[i];
                    for(char c = 'a';c<='z';c++){
                        word[i] = c;
                        if(st.find(word)!=st.end()){
                            st.erase(word);
                            q.push({word , ans+1});
                        }
                    }
                        word[i] = ch;
                }
            }
            return 0;
        }
    };