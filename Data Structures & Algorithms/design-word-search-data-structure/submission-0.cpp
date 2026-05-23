struct TrieNode{
    unordered_map<char, TrieNode*> children;
    bool wordEnd = false;
};
class WordDictionary {
public:
TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char c: word){
            if(!curr->children.count(c)) curr->children[c] = new TrieNode();
            curr = curr->children[c];
        }
        curr->wordEnd = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
        
    }

    bool dfs(string& word, int index, TrieNode* curr) {
    for (int i = index; i < word.length(); ++i) {
        char c = word[i];
        if (c == '.') {
            for (auto& pair : curr->children) {
                if (dfs(word, i + 1, pair.second)) return true;
            }
            return false;
        }
        if (!curr->children.count(c)) return false;
        curr = curr->children[c];
    }
    return curr->wordEnd;
}
};
