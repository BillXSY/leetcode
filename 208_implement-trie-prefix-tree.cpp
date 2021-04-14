//
// Created by 71401 on 2021/4/14.
//

class Trie {
private:
    bool is_end;
    vector<Trie*> children;

    Trie* searchPrefix(string prefix){
        Trie* t = this;
        for (char c : prefix){
            c -= 'a';
            if (t->children[c] == nullptr){
                return nullptr;
            }
            t = t->children[c];
        }
        return t;
    }

public:
    /** Initialize your data structure here. */
    Trie(): is_end(false), children(26) {}
    //children is a vector, vector(int size) creates a vector with size of 26

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* t = this;
        for (char c : word){
            c -= 'a';
            if (t->children[c] == nullptr){
                t->children[c] = new Trie();
            }
            t = t->children[c];
        }
        t->is_end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* t = this->searchPrefix(word);
        return t && t->is_end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return this->searchPrefix(prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */