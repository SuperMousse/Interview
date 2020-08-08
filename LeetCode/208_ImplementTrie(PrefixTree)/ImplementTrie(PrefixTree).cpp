// trie: 前缀树/字典树, 键不是直接保存在节点中，而是由节点在树中的位置决定,
// 一个节点的所有子孙都有相同的前缀，也就是这个节点对应的字符串，而根节点对应空字符串

class TrieNode {
public:
    // Initialize your data structure here.
    bool is_word;
    TrieNode *children[26];
    
    TrieNode() {
        is_word = false;
        
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        int word_len = word.length();
        int k = 0;
        TrieNode *cur = root;
        
        for (int i = 0; i < word_len; i++)
        {
            k = word[i] - 'a';
            
            if (cur->children[k] == NULL)
            {
                cur->children[k] = new TrieNode();
            }
            
            cur = cur->children[k];
        }
        
        cur->is_word = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        int word_len = word.length();
        int k = 0;
        TrieNode *cur = root;
        
        for (int i = 0; i < word_len; i++)
        {
            k = word[i] - 'a';
            cur = cur->children[k];
            
            if (cur == NULL)
                return false;
        }
        
        return cur->is_word;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        int word_len = prefix.length();
        int k = 0;
        TrieNode *cur = root;
        
        for (int i = 0; i < word_len; i++)
        {
            k = prefix[i] - 'a';
            cur = cur->children[k];
            
            if (cur == NULL)
                return false;
        }
        
        return true;
    }

private:
    TrieNode* root;
};
