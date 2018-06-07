class Solution {
public:
    int totalNum;
    vector<vector<int>> result;
    void search(vector<int>& visited, vector<int>& res, int n)
    {
        int length = res.size();
        if(length==totalNum)
        {
            result.push_back(res);
            return;
        }
        for(int i=1;i<=n;i++)
        {
            if((res.empty() || i>res[length-1]) && !visited[i])
            {
                // cout<<i<<endl;
                visited[i] = 1;
                res.push_back(i);
                search(visited, res, n);
                res.pop_back();
                visited[i] = 0;
            }
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> visited(n+1,0);
        vector<int> res;
        totalNum = k;
        search(visited, res, n);
        return result;
    }
};