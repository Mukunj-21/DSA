//Problem: https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

// sort krlo max profit ke according ab jab schedule karna hai to har iteration me try krna h ki last me hi schedule kre use
// taaki kisi aur ki space na khaye vo 

class Solution {
    public:
      static bool comp(pair<int,int>& a, pair<int,int>& b){
          return a.first > b.first;
      }
  
      vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
          int n = deadline.size();
          int max_deadline = 0;
          vector<pair<int,int>> v;
  
          for(int i = 0; i < n; i++) {
              v.push_back({profit[i], deadline[i]});
              max_deadline = max(max_deadline, deadline[i]);
          }
  
          sort(v.begin(), v.end(), comp);
  
          vector<int> temp(max_deadline + 1, -1);
          int count = 0, total_profit = 0;
          for(int i = 0; i < n; i++) {
              int deadline = v[i].second;
              int prof = v[i].first;
              for(int j = deadline; j > 0; j--) {
                  if(temp[j] == -1) {
                      temp[j] = i;
                      count++;
                      total_profit += prof;
                      break;
                  }
              }
          }
  
          return {count, total_profit};
      }
  };
  