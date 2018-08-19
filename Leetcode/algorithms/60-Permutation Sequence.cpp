class Solution {
public:
    int perm[10];
    int isVisited[10];
    char ato[10] = {'0','1','2','3','4','5','6','7','8','9'};
    void printArray(int arr[],int n)
    {
        for(int i=1;i<=n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
    void track(int n, int k)
    {
        // cout<<"n: "<<n<<endl;
        if(n==0) return;
        int order = k/perm[n-1];
        // order means which bin to distribute
        // cout<<"k: "<<k<<endl;
        // cout<<"Order: "<<order<<endl;
        k = k%perm[n-1];
        for(int i=1;i<10;i++)
        {
            if(isVisited[i]==0 && order==0)
            {
                isVisited[i] = n;
                track(n-1,k);
                break;
            }
            else if(isVisited[i]==0) order--;
        }
        return;
    }
    
    string getPermutation(int n, int k) {
        perm[0] =1;
        for(int i=1;i<=9;i++)
        {
            perm[i] = perm[i-1]*i;
        }
        memset(isVisited,0,sizeof(int)*10);
        track(n,k-1);
        // printArray(isVisited,n);
        string str = string("0",n);
        for(int i=1;i<=n;i++)
        {
            str[n-isVisited[i]] = ato[i];
        }
        return str;
    }
};