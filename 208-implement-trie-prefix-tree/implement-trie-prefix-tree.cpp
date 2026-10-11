class Trie {
    struct TrieNode {
        bool isEndOfWord;
        TrieNode* child[26];

        TrieNode() {
            this->isEndOfWord = false;
            for (int i = 0; i < 26; i++) {
                this->child[i] = nullptr;
            }
        }
    };
    TrieNode* root;

public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* crawl = root;

        for (const char& ch : word) {
            if (crawl->child[ch - 'a'] == nullptr) {
                crawl->child[ch - 'a'] = new TrieNode();
            }
            crawl = crawl->child[ch - 'a'];
        }
        crawl->isEndOfWord = true;
    }

    bool search(string word) {
        TrieNode* crawl = root;

        for (const char& ch : word) {
            if (crawl->child[ch - 'a'] == nullptr)
                return false;
            crawl = crawl->child[ch - 'a'];
        }
        return crawl->isEndOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode* crawl = root;

        for (const char& ch : prefix) {
            if (crawl->child[ch - 'a'] == nullptr)
                return false;
            crawl = crawl->child[ch - 'a'];
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