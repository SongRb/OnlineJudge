class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalStation = gas.size();
        for(int startIdx=0; startIdx<totalStation; startIdx++)
        {
            int initCost = 0;
            int pass = true;
            
            int i = startIdx;
            do{
                // cout<<startIdx<<" "<<i<<endl;
                int nextIdx = (i + 1) % totalStation;
                if(initCost+gas[i] < cost[i])
                {
                    pass = false;
                    break;
                }
                initCost = initCost + gas[i] - cost[i];
                i = (i+1) % totalStation;
            }while(i!=startIdx);
            
            if(pass) return startIdx;
        }
        return -1;
    }
};