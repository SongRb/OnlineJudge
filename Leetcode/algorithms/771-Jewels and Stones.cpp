class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<char> jewel(J.begin(), J.end());
        int cnt = 0;
        for(const auto& ch: S)
        {
            if(jewel.find(ch)!=jewel.end()) cnt++;
        }
        return cnt;
    }
};