class Solution {
public:
    int mySqrt(int x) {
        long res = x;
        while(res*res>x)
        {
            res = 0.5*(res+x/res);
        }
        return res;
    }
};