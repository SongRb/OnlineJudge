class Solution {
public:
   bool isPalindrome(int x) {
        
        if(x<0)
            return false;
        
        int base =10;
        int n =x;
        int nd=0;
        
        do {
     ++nd; 
     n /= base;
} while (n);
        
        if(nd==1)
            return true;
        
        int i=1;
        // cout<<nd<<endl;
        while(nd-i>=i)
        {
            // cout<<i<<" "<<x/(int)pow(10,nd-i)<<" "<<x%(int)pow(10,i)<<endl;
            if(x/(int)pow(10,nd-i) != x%(int)pow(10,i))
            {
                return false;
            }
            x = x%(int)pow(10,nd-i);
            x = x/(int)pow(10,i);
            // cout<<x<<endl;
            nd-=2;
        }
        return true;    
    }
};