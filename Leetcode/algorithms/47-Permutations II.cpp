class Solution {
public:
    int length;
    vector<int> visited;
    vector<int> numVector;
    vector<vector<int>> result;
    unordered_map<int, vector<int>> dup;
    vector<int> wh;
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
                bool isMass = false;
                
                if(dup[numVector[i]].size()!=1)
                {
                    for(const auto&k: dup[numVector[i]])
                    {
                        if(k<i && !visited[k])
                        {
                            isMass = true;
                            break;
                        }
                        else if(k>=i)
                        {
                            break;
                        }
                    }
                }
                if(isMass) continue;
                idx.push_back(i);
                visited[i] = 1;
                rec(idx, depth-1);
                visited[i] = 0;
                idx.pop_back();
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        numVector.insert(numVector.end(), nums.begin(), nums.end());
        length = nums.size();
        if(length==0) {
            result.push_back(vector<int>());
            return result;}
        
        for(int i=0;i<length;i++)
        {
            dup[nums[i]].push_back(i);
        }
        // if(dup.size()==1 && dup.begin().second.size()==1) return numVector;
        visited.insert(visited.end(), length, 0);
        vector<int> idx;
        rec(idx, length);
        return result;
    }
};