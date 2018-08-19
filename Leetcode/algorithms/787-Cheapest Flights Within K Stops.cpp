class Solution {
public:
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> vec(n,1e8);
        vec[src]=0;
        for(int k=0;k<=K;k++)
        {
            vector<int> v(vec);
            for(auto e:flights)
            {
                v[e[1]] = min(v[e[1]],vec[e[0]]+e[2]);
            }
            vec = v;
        }
        return vec[dst]==1e8?-1:vec[dst];
    }
};