class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> inDegree(numCourses,0);
        vector<int> result;
        queue<int> que;
        int count = prerequisites.size();
        int length = count;
        vector<int> exist(count,1);
        for(auto& p:prerequisites)
        {
            inDegree[p.first]++;
        }
        for(int i=0;i<numCourses;i++)
        {
            if(inDegree[i]==0) que.push(i);
        }
        while(!que.empty())
        {
            int e = que.front();
            que.pop();
            result.push_back(e);
            for(int i=0;i<length;i++)
            {
                auto& pp = prerequisites[i];
                if(pp.second==e && exist[i]==1)
                {
                    exist[i] = 0;
                    inDegree[pp.first]--;
                    count--;
                    if(inDegree[pp.first]==0) que.push(pp.first);
                }
            }
        }
        return count==0?result:vector<int>();
    }
};