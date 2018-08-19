class Solution {
public:

    
    int numDecodings(string s) {

        int length = s.length();
        
        if(length==0) return 0;
        else if(s[0]=='0' || (s[0]>'2'&&s[1]=='0')) return 0;
        else if(length == 1) return 1;
        else 
        {
            int solution[10000];
            solution[0] = 1;
            
            if(isDouble(s[0],s[1]))
                {
                if(s[1]!='0')solution[1]=2;
                else solution[1]=1; 
            }
            else solution[1] =1;
            
            for(int i=2;i<length;i++)
            {
                if(s[i]=='0' )
                {
                    if(s[i-1]>'2'|| s[i-1]=='0') return 0;
                    else solution[i] = solution[i-2];
                }
                if(isDouble(s[i-1],s[i]))
                {
                    if(s[i]=='0')
                        solution[i] = solution[i-2];
                        else
                    solution[i] = solution[i-2]+solution[i-1];
                }
                else if(s[i-1]=='0')
                {
                    if(i-3>=0)
                    solution[i] = solution[i-3];
                    else solution[i]=1;
                }
                else
                {
                    solution[i] = solution[i-1];
                }
            }
            return solution[length-1];
        }
    }
    
        bool isDouble(char ch1, char ch2)
    {
        return (ch2<='6' && ch1=='2') || ch1=='1';
    }

};