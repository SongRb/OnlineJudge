class WordDictionary {
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
    
    TreeNode*  root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TreeNode('-1');
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
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
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, 0, root);
    }
    // check if r has one child matches word[index]
    bool search(string word, int index, TreeNode* r)
    {
        // Should be end of word
        if(index==word.size()) return r->isWord;
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
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */