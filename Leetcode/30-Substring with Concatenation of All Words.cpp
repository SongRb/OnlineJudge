
static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int word_length = words[0].length();
        int sentence_length = s.length();
                vector<int> res;
        if(sentence_length<word_length*words.size()) return res;
        
        unordered_map<string,int> mp;
        unordered_map<string,int> tmp;
        
        
        
        for(auto i: words)
        {
            if(mp.find(i)==mp.end())
                mp[i]=1;
            else
                mp[i]++;
        }
        
        

  
        int index=0;
        for(int i=0;i<sentence_length;i++)
        {
            index = i;
            bool found = false;
            string tmpString = s.substr(i,word_length);
            while(i<sentence_length && mp.find(tmpString) != mp.end() && (tmp.find(tmpString)==tmp.end()|| tmp[tmpString]<mp[tmpString] ) && tmp!=mp)
            {
                
            if(tmp.find(tmpString)==tmp.end())
                tmp[tmpString]=1;
            else
                tmp[tmpString]++;
                
                            
                i+=word_length;
                tmpString = s.substr(i,word_length);
                found = true;

                bool r = tmp.size()<mp.size();
            }
            i=index;
            if(found && tmp==mp)
          {
               res.push_back(index);
          }
            tmp.clear();
        }
                  return res;
    }

};