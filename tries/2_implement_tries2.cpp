// Problem : Implement Trie II (Prefix Tree)
// Link : https://www.naukri.com/code360/problems/implement-trie_1387095?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 
struct Node{
    Node* links[26];
    int countEnd = 0;
    int countPrefix = 0;

    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }

    Node * get(char ch){
        return links[ch - 'a'];
    }

    void put(char ch , Node* node){
        links[ch - 'a'] = node;
    }

    void increaseEnd(){
        countEnd++;
    }

    void increasePrefix(){
        countPrefix++;
    }

    void removeEnd(){
        countEnd--;
    }

    void removePrefix(){
        countPrefix--;
    }
};
class Trie{
    private:
        Node* root;
    public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* node = root;
        for(int i=0 ; i < word.size() ; i++){
            if(!node->containsKey(word[i]))
                node->put(word[i] , new Node());
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for(int i=0 ; i < word.size() ; i++){
            if(!node->containsKey(word[i]))
                return 0;
            node = node->get(word[i]);
        }
        return node->countEnd;
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for(int i=0 ; i < word.size() ; i++){
            if(!node->containsKey(word[i]))
                return 0;
            node = node->get(word[i]);
        }
        return node->countPrefix;
    }

    void erase(string &word){
        Node* node = root;
        for(int i=0 ; i < word.size() ; i++){
            if(!node->containsKey(word[i]))
                return;
            node = node->get(word[i]);
            node->removePrefix();
        }
        node->removeEnd();
    }
};
