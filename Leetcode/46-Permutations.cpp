class Solution {
public:
    int length;
    vector<int> visited;
    vector<int> numVector;
    vector<vector<int>> result;
    void rec(vector<int> idx, int depth)
    {
        // cout<<depth<<endl;
        if(depth==0)
        {
            vector<int> res(0);
            for(const auto& i:idx)
            {
                res.push_back(numVector[i]);
            }
            result.push_back(res);
        }
        for(int i=0;i<length;i++)
        {
            if(!visited[i])
            {
                idx.push_back(i);
                visited[i] = 1;
                rec(idx, depth-1);
                visited[i] = 0;
                idx.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        numVector.insert(numVector.end(), nums.begin(), nums.end());
        length = nums.size();
        if(length==0) {
            result.push_back(vector<int>());
            return result;}
        visited.insert(visited.end(), length, 0);
        vector<int> idx;
        rec(idx, length);
        return result;
    }
};