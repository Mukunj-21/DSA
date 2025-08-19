// Problem Statement: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/


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
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto & num : nums)
            trie.insert(num);
        int ans = 0;
        for(auto &num : nums)
            ans = max(ans , trie.getMax(num));
        return ans;
    }
};