class Solution {
public:
    vector<int> tmp = vector<int>(100,0);
    int search(int n)
    {
        if(n<=2) return tmp[n];
        else 
        {
            int tmp1, tmp2;
            if(n-1<100)
            {
                if(tmp[n-1]==0) tmp[n-1] = climbStairs(n-1);
                tmp1 = tmp[n-1];
            }
            if(n-2<100)
            {
                if(tmp[n-2]==0) tmp[n-2] = climbStairs(n-2);
                tmp2 = tmp[n-2];
            }
            return tmp1+tmp2;
        }
    }
    
    int climbStairs(int n) {
        tmp[0] = 1;
        tmp[1] = 1;
        tmp[2] = 2;
        return search(n);
    }
};