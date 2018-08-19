class Solution {
public:
    vector<int> visited;
    unordered_map<char,vector<int>> mp;
    int h,w,s;
    string word2;
    bool search(int index, int prev)
    {
        // cout<<index<<" "<<prev/w<<" "<<prev%w<<endl;
        if(index==s) return true;
        auto ch = word2[index];
        if(mp.find(ch)!=mp.end())
        {
            bool result = false;
            for(const auto& i:mp[ch])
            {
                // cout<<i<<endl;
                if(!visited[i])
                {
                    visited[i] = 1;
                    int px = prev/w;
                    int py = prev%w;
                    int ix = i/w;
                    int iy = i%w;
                    // cout<<"Hello"<<endl;
                    if(prev==-1 || (abs(px-ix)==1 && py==iy) || (px==ix && abs(py-iy)==1))
                    {
                        result = result || search(index+1, i);
                    }
                    visited[i] = 0;
                }
            }
            return result;
        }
        else return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        h = board.size();
        if(h==0) return false;
        w = board[0].size();
        if(w==0) return false;
        s = word.size();
        if(s==0) return false;
        visited.insert(visited.end(), h*w, 0);
        word2 = word;
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                mp[board[i][j]].push_back(i*w+j);
            }
        }
        return search(0,-1);
    }
};