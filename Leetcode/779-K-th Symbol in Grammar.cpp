class Solution {
public:
    void printVector(const vector<int>& selection)
    {
        for(auto& i:selection)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    int iteration(const vector<int>& selection, int index, int start)
    {
        if(index==-1) return start;
        else if(start==0 && selection[index]==0 || start==1 && selection[index]==1)
            return iteration(selection,index-1,1);
        else if(start==0 && selection[index]==1 || start==1 && selection[index]==0)
            return iteration(selection,index-1,0);
    }
    
    int kthGrammar(int N, int K) {
        vector<int> selection;
        int num = N;
        while(num>0)
        {
            selection.push_back(K%2);
            if(K>=2) K=(K+1)/2;
            num--;
        }
        int start = 0;
        for(int index=N-2;index>=0;index--)
        {
        if(start==0 && selection[index]==0 || start==1 && selection[index]==1)
            start=1;
        else if(start==0 && selection[index]==1 || start==1 && selection[index]==0)
            start=0;
        }
        return start;
    }
};