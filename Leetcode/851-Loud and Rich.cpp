class Solution {
public:
    vector<vector<int>> graph;
    vector<int> result;
    int search(const vector<int>& quiet, int prev)
    {
        if(result[prev]>=0) return result[prev];
        result[prev] = prev;
        for(const auto& i:graph[prev])
        {
            if(quiet[result[prev]]>quiet[search(quiet, i)]) result[prev] = result[i];
        }
        return result[prev];
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        graph = vector<vector<int>>(quiet.size());
        result = vector<int>(quiet.size(),-1);
        for(const auto& p:richer)
        {
            graph[p[1]].push_back(p[0]);
        }
        for(int i=0;i<quiet.size();i++)
        {
            search(quiet,i);
        }
        return result;
    }
};