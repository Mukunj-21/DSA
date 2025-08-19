// Problem : Implement Trie (Prefix Tree)
// Link : https://leetcode.com/problems/implement-trie-prefix-tree/



struct Node{
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch){
        return (links[ch-'a'] != NULL) ;
    }

    void put(char ch , Node* node){
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};
class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        // INITIALIZE WITH ROOT
        Node* node = root;
        for(int i = 0;i < word.size() ; i++){
            // CHECK WHETHER THE ALPHABET IS PRESENT OR NOT IF NOT THEN PUT THE ALPHABET AND THEN US ALPHABET KE NAYE REFERENCE PE CHALE JAO
            if(!node->containsKey(word[i])){
                node->put(word[i] , new Node());
            }
            node = node->get(word[i]);
        }
        // AFTER REACHING THE END JO NAYA REFERENCE TRIE HAI USKE BOOL KO TRUE KRDO
        node->setEnd();
    }
    
    bool search(string word) {
        // SAME PEHLE INITIALIZE KRO
        Node* node = root;
        for(int i = 0; i < word.size() ; i++){
            // CHECK KARO KI LETTER HAI YA NHI IF NOT THEN RETURN FALSE ELSE NEXT REFERENCE PR JAO
            if(!node->containsKey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        // ATLAST JO REFERENCE TRIE HAI USME FLAG KI VALUE CHECK KRLO TAAKI PTA CHAL JAYE END HUA HAI YA NHI 
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0 ; i < prefix.size() ; i++){
            if(!node->containsKey(prefix[i]))
                return false;
            node = node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */