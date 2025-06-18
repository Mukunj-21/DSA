//Problem: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

// sabse pehle sort krlo end time ke according taaki pta chal jaye konsi meeting pehle khtm hojaegi taaki next start krde
// fir ek ek karke check krlo ki agar current meeting ka start time last meeting ke end time se bada hai to count krlo
// while sorting end time ke according, agar end time same hai to start time ke according sort krlo to isme humne comp use kiya
// comp define karta hai ki agar end time same hai to start time ke according sort ho

class Solution {
    public:
      // Function to find the maximum number of meetings that can
      // be performed in a meeting room.
      static bool comp(pair<int,int>&a , pair<int,int>&b){
          return a.second<b.second;
      }
      int maxMeetings(vector<int>& start, vector<int>& end) {
          // Your code here
          vector<pair<int,int>> time;
          for(int i=0;i<start.size();i++)
              time.push_back({start[i] , end[i]});
          sort(time.begin() , time.end() , comp);
          int count = 0;
          int limit = -1;
          for(int i=0;i<start.size();i++){
              if(time[i].first>limit){
                  count++;
                  limit = time[i].second;
              }
              else
                  continue;
          }
          return count;
      }
  };