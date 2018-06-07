class Solution {
public:
    
    int result[1000002] = {0};
    
    int find(int k)
    {
        cout<<k<<endl;
        int res = 0;
        if(k==1) res = 0;
        
        else if(k<100000 && result[k]!=0) res = result[k];
        else if(k%4096==0) res = find(k/4096)+12;
        else if(k%2048==0) res = find(k/2048)+11;
        else if(k%1024==0) res = find(k/1024)+10;
        else if(k%512==0) res = find(k/512)+9;
        else if(k%256==0) res = find(k/256)+8;
        else if(k%128==0) res = find(k/128)+7;
        else if(k%64==0) res = find(k/64)+6;
        else if(k%32==0) res = find(k/32)+5;
        else if(k%16==0) res = find(k/16)+4;
        else if(k%8==0) res = find(k/8)+3;
        else if(k%4==0) res = find(k/4)+2;
        else if(k%2==0) res = find(k/2)+1;
        else if(k!=2147483647)res = min(find(k+1),find(k-1))+1;
        else res = find(1073741824)+2;
        
        if(k<100000) result[k] = res;
        return res;
    }
    
    
    int integerReplacement(int n) {
        result[1]=0;
        result[2]=1;
        result[3]=2;
        result[4]=2;
        return find(n);
    }
};