class Solution {
public:
    vector<int> power = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};
    
    
    
    int getLength(int num)
    {
        int cnt = 0;
        do
        {
            num/=2;
            cnt++;
        }while(num>0);
        return cnt;
    }
    
    int rangeBitwiseAnd(int m, int n) {
        int length = getLength(m);
        int range = n-m+1;
        int result=0;
        for(int i=length;i>=1;i--)
        {
            int gap = power[i-1]-m%power[i-1];
            int tmp = i<=30?m%power[i] : m;
            if(gap>=range && tmp>=power[i-1])
            {
                result++;
            }
            if(i!=1)result = result<<1;
        }
        return result;
    }
};