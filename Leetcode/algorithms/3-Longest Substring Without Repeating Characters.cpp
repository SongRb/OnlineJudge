class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = s.size();
        int best = 0;
        for(int i=0;i<length;)
        {
            unordered_map<char, int> letter;
            int left=i;
            while(left>=0 && letter[s[left]]==0) {letter[s[left]]=1;left--;}
            left+=1;
            int right=i+1;
            while(right<length && letter[s[right]]==0) {letter[s[right]]=1;right++;}
            right-=1;
            best = max(best, right-left+1);
            i = right+1;
        }
        return best;
    }
};