//Problem Statement: https://leetcode.com/problems/maximum-xor-with-an-element-from-array/


struct Node{
    Node* links[2];

    bool containKeys(int bit){
        return (links[bit] != NULL);
    }

    Node* get(int bit){
        return links[bit];
    }

    void put(int bit , Node* node){
        links[bit] = node;
    }
};

class Trie{
    private:
        Node* root;
    public:
        Trie(){
            root = new Node();
        }

        void insert(int num){
            Node* node = root;
            for(int i = 31 ; i >= 0 ; i--){
                int bit = (num >> i) & 1;
                if(!node->containKeys(bit))
                    node->put(bit , new Node());
                node = node->get(bit);
            }
        }

        int getMax(int num){
            Node* node = root;
            int maxi = 0;
            for(int i = 31 ; i >= 0 ; i--){
                int bit = (num >> i) & 1;
                if(node->containKeys(!bit)){
                    // I WANT XOR OPERATION TO BE PERFORMED SO WHENEVER WE ARE CHECKING THIS OPPOSITE BIT WE WILL ALWAYS OR IT WITH 1 BECAUSE XOR OF 2 DIFFERENT NUMBERS IS ALWAYS 1
                    maxi = maxi | (1 << i);
                    node = node->get(!bit);
                }
                else
                    node = node->get(bit);
            }
            return maxi;
        }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans(queries.size() , 0);
        vector<pair<int , pair<int , int>>> offlineQueries;

        sort(nums.begin() , nums.end());

        int ind = 0;

        for(auto & it : queries)
            offlineQueries.push_back({it[1] , {it[0] , ind++}});

        sort(offlineQueries.begin() , offlineQueries.end());

        Trie trie;

        int i = 0 , n = nums.size();

        for(auto & it : offlineQueries){
            while(i < n && nums[i] <= it.first){
                trie.insert(nums[i]);
                i++;
            }

            if(i != 0)
                ans[it.second.second] = trie.getMax(it.second.first);

            else
                ans[it.second.second] = -1;
        }
        
        return ans;
    }
};