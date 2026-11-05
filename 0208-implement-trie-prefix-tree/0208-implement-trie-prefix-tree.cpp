class TrieNode {
public:
    char data;
    unordered_map<char, TrieNode*> children;
    bool isTerminal;

    TrieNode(char val) {
        data = val;
        isTerminal = false;
    }

    void insertWord(TrieNode* root, string word) {
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        char ch = word[0];
        TrieNode* child;

        if (root->children.find(ch) != root->children.end()) {
            child = root->children[ch];
        } else {
            child = new TrieNode(ch);
            root->children[ch] = child;
        }

        insertWord(child, word.substr(1));
    }

    bool searchWord(TrieNode* root, string word) {
        if (word.length() == 0) {
            return root->isTerminal;
        }

        char ch = word[0];

        if (root->children.find(ch) != root->children.end()) {
            return searchWord(root->children[ch], word.substr(1));
        }

        return false;
    }

    bool searchPrefix(TrieNode* root, string word) {
        if (word.length() == 0) {
            return true;
        }

        char ch = word[0];

        if (root->children.find(ch) != root->children.end()) {
            return searchPrefix(root->children[ch], word.substr(1));
        }

        return false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('-');
    }

    void insert(string word) {
        root->insertWord(root, word);
    }

    bool search(string word) {
        return root->searchWord(root, word);
    }

    bool startsWith(string prefix) {
        return root->searchPrefix(root, prefix);
    }
};