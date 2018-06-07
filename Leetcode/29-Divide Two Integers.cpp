class Solution {
public:
    int divide(long int dividend, long int divisor)
    {
        const int MAX_INT = 2147483647;
        if(dividend== -2147483648 && divisor==-1) return MAX_INT;
        if(divisor==0) return MAX_INT;
        else if(dividend ==0 || abs(dividend)<abs(divisor)) return 0;
        

        
        if(divisor==1) return dividend;
        else if(divisor==-1) return -dividend;
        else if(abs(divisor)==2) return dividend>>1;
        else if(abs(divisor)==4) return dividend>>2;
        else if(abs(divisor)==8) return dividend>>3;
        else if(abs(divisor)==16) return dividend>>4;
        else if(abs(divisor)==32) return dividend>>5;
        
        if(dividend<0)
        {
            divisor = -divisor;
            dividend = -dividend;
        }
        cout<<dividend<<endl;
        
        if(divisor>0)
        {
            int i=-1;
            for(;dividend>=0;i++)
            {
                dividend-=divisor;
            }
            return i;
        }
        else
        {
            int i=-1;
            for(;dividend>=0;i++)
            {
                dividend+=divisor;
            }
            return -i;
        }
    }
    
    
    int divide(int dividend, int divisor) {
        long int dd = (long int) dividend;
        long int div = (long int) divisor;
        return divide(dd,div);
    }
};