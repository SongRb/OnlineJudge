class Solution {
public:
    vector<char> toc{'0','1'};
    
    void compute(string& l, string& s)
    {
        int length1 = l.size();
        int length2 = s.size();   
        int carry = 0;
        int i=0;
        for(;i<length2; i++)
        {
            int tmp = (l[length1 - 1 - i] - '0') + (s[length2 - 1 - i] - '0') + carry;
            // cout<<tmp<<endl;
            
            l[length1 - 1 - i] = toc[tmp%2];
            carry = tmp/2;
            
            
            // if(tmp==3)
            // {
            //     l[length1 - 1 - i] = '0';
            //     carry = 1;
            // }
            // else if(tmp==2)
            // {
            //     l[length1 - 1 - i] = '0';
            //     carry = 1;
            // }
            // else
            // {
            //     l[length1 - 1 - i] = toc[tmp];
            //     carry = 0;
            // }
        }
        
        // assume l -> 5; s -> 3
        // i should be 
        
        for(;i<length1;i++)
        {
            int tmp = (l[length1 - 1 - i] - '0') + carry;
            if(tmp==2)
            {
                l[length1 - 1 - i] = '0';
                carry = 1;
            }
            else
            {
                l[length1 - 1 - i] = toc[tmp];
                carry = 0;
            }
        }
        if(carry==1) l.insert(0,1,'1');
    }
    
    string addBinary(string a, string b) {
        int length1 = a.size();
        int length2 = b.size();
        if(length1==0) a="0";
        if(length2==0) b="0";
        
        if(length1>length2)
        {
            compute(a,b);
            return a;
        }
        else
        {
            compute(b,a);
            return b;
        }
    }
};