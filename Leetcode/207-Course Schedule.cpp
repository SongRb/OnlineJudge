class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> next(numCourses);
        vector<unordered_set<int>> prev(numCourses);
        vector<int> visited(numCourses, 0);
        for(const auto& p:prerequisites)
        {
            next[p.second].insert(p.first);
        }
        for(const auto& p:prerequisites)
        {
            prev[p.first].insert(p.second);
        }
        int cnt = numCourses;
        queue<int> que;
        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i] && prev[i].empty())
            {
                que.push(i);
                visited[i] = 1;
                cnt--;
            }
        }
        do
        {
            if(que.empty()) break;
            auto course = que.front();
            que.pop();
            for(const auto& n:next[course])
            {
                if(prev[n].find(course)!=prev[n].end()) 
                {
                    prev[n].erase(course);
                    if(prev[n].empty())
                    {
                        que.push(n);
                        visited[n] = 1;
                        cnt--;   
                    }
                }
            }
        } while(!que.empty());
        return cnt==0;
    }
};