class Solution {
public:   
    set<string> dict;
    bool search(string word,bool first)
    {
        if(!first && dict.find(word)!=dict.end()) return true;
        // cout<<"Dealing with "<<word<<endl;
        int length = word.size();
        for(int i=1;i<length;i++)
        {
            bool result;
            // cout<<"Looking for "<<word.substr(0,i)<<endl;
            if(dict.find(word.substr(0,i)) != dict.end()) 
            {
                result = search(word.substr(i),false);
            }
            if(result) return result;
        }
        return false;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        dict.insert(words.begin(),words.end());
        vector<string> result;
        for(auto word: words)
        {
            if(search(word,true)) result.push_back(word);
        }
        return result;
    }
};