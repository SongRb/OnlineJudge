class Solution {
public:
    vector<int> prime;
    int countPrimes(int n) {
        if(n<=1) return 0;
        else if(n<=2) return 0;
        else if(n<=3) return 1;
        prime.push_back(2);
        for(int i=3;i<n;i+=2)
        {
            bool isPrime = true;
            int bound = sqrt(i)+1;
            for(int j=0;j<prime.size();j++)
            {
                if(i%prime[j]==0) {isPrime = false;break;}
                if(prime[j]>bound) break;
            }
            if(isPrime) prime.push_back(i);
        }
        return prime.size();
    }
};