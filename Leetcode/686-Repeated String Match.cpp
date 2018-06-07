class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int lengthA = A.size();
        int lengthB = B.size();
        vector<int> start(lengthA);
        if(lengthA==0 || lengthB==0) return -1;
        bool conti = false;
        int cnt = 1;
        int missedCnt =0;
        for(int i=0;i<lengthA;i++)
        {
            int indexB = 0;
            int indexA = i;
            cnt = 1;
            while(A[indexA]==B[indexB])
            {
                indexA++;
                indexB++;
                if(indexB==lengthB) return cnt;
                if(indexA>=lengthA)
                {
                    cnt++;
                    indexA-=lengthA;
                }
            }
        }
        return -1;
    }
};