class TrieNode {
public:
    char data;
    unordered_map<char, TrieNode*> children;
    bool isTerminal;
    int childCount;

    TrieNode(char val) {
        data = val;
        isTerminal = false;
        childCount = 0;
    }
};

class Solution {
public:
    void insertWord(TrieNode* root, string str) {
        if (str.length() == 0) {
            root->isTerminal = true;
            return;
        }

        char ch = str[0];
        TrieNode* child;

        if (root->children.find(ch) != root->children.end()) {
            child = root->children[ch];
        }
        else {
            child = new TrieNode(ch);
            root->children[ch] = child;
            root->childCount++;
        }

        insertWord(child, str.substr(1));
    }

    string findLCP(TrieNode* root) {
        string ans = "";
        TrieNode* temp = root;

        while (temp->childCount == 1 && !temp->isTerminal) {
            for (auto i : temp->children) {
                temp = i.second;
                ans.push_back(temp->data);
            }
        }

        return ans;
    }

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        TrieNode* root = new TrieNode('-');

        for (int i = 0; i < strs.size(); i++) {
            insertWord(root, strs[i]);
        }

        return findLCP(root);
    }
};