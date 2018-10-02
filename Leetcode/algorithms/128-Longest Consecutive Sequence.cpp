class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int best = 0;
        for(const auto& x: numSet){
            if(numSet.find(x-1)==numSet.end()){
                int y = x+1;
                while(numSet.find(y) != numSet.end()) y++;
                best = max(best, y-x);
            }
        }
        return best;
    }
};