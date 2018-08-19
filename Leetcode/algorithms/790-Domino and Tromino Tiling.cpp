class Solution {
public:
    int numTilings(int N) {
        if(N==0) return 1;
        long int** result;
        result = new long int*[3];
        result[0] = new long int[N];
        result[1] = new long int[N];
        result[2] = new long int[N];
        // 0 - empty on upper
        // 1 - empty on lower
        // 2 - not empty
        
        result[2][0] = 1;
        
        result[0][1] = 1;
        result[1][1] = 1;
        result[2][1] = 2;
        
        for(int i=2;i<N;i++)
        {    //i=2                1                1               2              1
            result[2][i] = (result[0][i-1]%1000000007 + result[1][i-1]%1000000007 + result[2][i-1]%1000000007+ result[2][i-2]%1000000007)%1000000007;
            result[1][i] = (result[0][i-1]%1000000007 + result[2][i-2]%1000000007)%1000000007;
            result[0][i] = (result[1][i-1]%1000000007 + result[2][i-2]%1000000007)%1000000007;          
        }
        return (int)result[2][N-1];
    }
};
