class Trie {
public:
    struct TreeNode
    {
        char val;
        bool isWord = false;
        TreeNode* child[26];
        TreeNode(char v)
        {
            v = val;
            memset(child, NULL, sizeof(TreeNode*)*26);
        }
    };
    
    bool checkPrefix = true;
    TreeNode*  root;
    
    /** Initialize your data structure here. */
    Trie() {
        root = new TreeNode('-1');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
                TreeNode* p = root;
        for(auto ch: word)
        {
            if(p->child[ch-'a'] == NULL)
            {
                p->child[ch-'a'] = new TreeNode(ch);
            }
            p = p->child[ch-'a'];
        }
        p->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        checkPrefix = false;
        return search(word, 0, root);
    }
    
    // check if r has one child matches word[index]
    bool search(string word, int index, TreeNode* r)
    {
        // Should be end of word
        if(index==word.size()) return checkPrefix || r->isWord;
        bool result = false;
        if(word[index]=='.')
        {
            for(int i=0;i<26;i++)
            {
                if(r->child[i] != NULL) result = result || search(word, index+1, r->child[i]);
            }
        }
        else
        {
            if(r->child[word[index]-'a']) result =  result || search(word, index+1, r->child[word[index]-'a']);
        }
        return result;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        checkPrefix = true;
        return search(prefix, 0, root);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */