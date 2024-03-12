// https://leetcode.com/problems/implement-trie-prefix-tree

class TrieNode{
    public:
        char c;
        unordered_map<char, TrieNode*> m;
    TrieNode(){}
    TrieNode(char ch){c = ch;}
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        word += 'X';
        TrieNode* tmp = root;
        for(auto ch: word){
            if((tmp->m)[ch] == NULL) (tmp->m)[ch] = new TrieNode(ch);
            tmp = (tmp->m)[ch];
        }
    }
    
    bool search(string word) {
        TrieNode* tmp = root;
        for(auto ch: word){
            if((tmp->m)[ch] == NULL) return false;
            tmp = (tmp->m)[ch];
        }
        if((tmp->m)['X'] == NULL && (tmp->m).size()) return false;
        return true;
    }
    
    bool startsWith(string prefix) {
        TrieNode* tmp = root;
        for(auto ch: prefix){
            if((tmp->m)[ch] == NULL) return false;
            tmp = (tmp->m)[ch];
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