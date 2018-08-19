class Solution {
public:
    
    bool isHappy(int n) {
        int square[10] = {0,1,4,9,16,25,36,49,64,81};
        set<int> vis;
        while(true)
        {
            if(vis.find(n)==vis.end()) vis.insert(n);
            else return false;
            int result=0;
            while(n>0)
            {
                result+=square[n%10];
                n = n/10;
            }
            n = result;
            if(n==1) return true;
        }
        return false;
    }
};