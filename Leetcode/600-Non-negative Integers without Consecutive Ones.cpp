class Solution {
public:
    int* arr1;
    int* pow2;
    int* result;    
    Solution()
    {
        arr1 = new int[33]{0,2,3,5};
        pow2 = new int[33]{1,2,4,8,16,32,64,128,256,512,1024,2048,4096};
        result = new int[1000]{1,2,3,3,4,5,5,5,6,7,8};
    }
    
    // get possible value less than or equal to k 1s
    int getK(int k)
    {
        if(arr1[k]==0)
        {
            arr1[k] = getK(k-1)+getK(k-2);
        }
        return arr1[k];
    }
    
    // get 2^k
    int getPow2(int k)
    {
        if(pow2[k]==0)
        {
            pow2[k] = 2*getPow2(k-1);
        }
        return pow2[k];
    }
    
    int getBitLength(int k)
    {
        for(int i=1;i<33;i++)
        {
            if(k>=getPow2(i-1) && k < getPow2(i)) return i;
        }
    }
    int find(int num)
    {
        if(num<=999 && result[num]!=0) return result[num];
        else
        {
            int res;
            // length may be greater than 3
            int length = getBitLength(num);
            if(num>=getPow2(length-1)+getPow2(length-2))
            {
                res = getK(length-1)+getK(length-2);
            }
            else
            {
                res = getK(length-1)+find(num-getPow2(length-1));
            }
            if(num<=999) result[num] = res;
            return res;
        }
    }
    int findIntegers(int num) {
        return find(num);
    }
};