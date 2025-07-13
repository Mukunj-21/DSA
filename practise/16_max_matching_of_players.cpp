//Problem : https://leetcode.com/problems/maximum-matching-of-players-with-trainers/

class Solution {
    public:
        int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
            int i = 0 , j = 0;
            int n1 = players.size() , n2 = trainers.size();
            sort(players.begin() , players.end());
            sort(trainers.begin() , trainers.end());
            int count = 0;
            while(i<n1 && j<n2){
                if(players[i] <= trainers[j]){
                    count++;
                    i++;
                    j++;
                }
                else
                    j++;
            }
            return count;
        }
    };