class Solution {
public:
    int myAtoi(string str) {
        int length = str.length();
        
        if(length==0)
            return 0;
        
        long int result=0;
        bool isPos = true;
        bool isBegin = false;
        bool isNumber = false;
        for(int i=0;i<length;i++)
        {
            if(!isBegin && str[i]==' ')
                continue;
            else if(!isBegin && str[i]=='+')
            {
                isBegin = true;
                continue;
            }

            else if(!isBegin && str[i]=='-')
            {  
                isPos = false;
                isBegin = true;
                continue;
            }
            else if(str[i] >='0' && str[i] <='9')
            {
                isBegin = true;
                isNumber = true;
                result = result*10 + str[i]-'0';
                long int real_result;
            if(!isPos) 
            {
                real_result = -result;    
            }
                else
                {real_result = result;    
}
                
                if(real_result>INT_MAX) {return INT_MAX;}
                if(real_result<INT_MIN) {return INT_MIN;}
                
                

            }
            else
            {
                // Encounting non-int symbol
                break;
            }
        }
        if(isBegin)
        {
            if(!isPos) 
            {
                result = -result;    
            }
            if(result>INT_MAX) result = INT_MAX;
            if(result<INT_MIN) result = INT_MIN;
        }
        else
        {
            result = 0;
        }

        return (int)result;
    }
};