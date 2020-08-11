// trie: 前缀树/字典树, 键不是直接保存在节点中，而是由节点在树中的位置决定,
// 一个节点的所有子孙都有相同的前缀，也就是这个节点对应的字符串，而根节点对应空字符串
// trie是一种高效的检索数据结构(reTRIEval)
// 例子, 其中.代表叶子节点
/*
                       root
                    /   \    \
                    t   a.    b
                    |   |     |
                    h   n     y.
                    |   |  \  |
                    e.  s  y. e.
                 /  |   |
                 i  r   w
                 |  |   |
                 r. e.  e
                        |
                        r.
*/


struct TrieNode {
    bool isEndOfWord;  // isEndOfWord is true if the node represents end of a word
    TrieNode *children[26];
    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        int wordLen = word.size();
        int k = 0;
        TrieNode *current = root;

        for (int i = 0; i < wordLen; ++i)
        {
            k = word[i] - 'a';
            if (current->children[k] == nullptr)
            {
                current->children[k] = new TrieNode();
            }
            current = current->children[k];
        }
        current->isEndOfWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        int wordLen = word.size();
        int k = 0;
        TrieNode *current = root;

        for (int i = 0; i < wordLen; ++i)
        {
            k = word[i] - 'a';
            current = current->children[k];

            if (current == NULL)
                return false;
        }

        return current->isEndOfWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        int wordLen = prefix.size();
        int k = 0;
        TrieNode *current = root;

        for (int i = 0; i < wordLen; ++i)
        {
            k = prefix[i] - 'a';
            current = current->children[k];

            if (current == NULL)
                return false;
        }
        return true;
    }

private:
    TrieNode* root;
};
