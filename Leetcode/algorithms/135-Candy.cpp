class Solution {
public:
    vector<int> rank;
    vector<int> userCandy;
    
    int candy(vector<int>& ratings) {
        if(ratings.empty()) return 0;
        rank = vector<int>(ratings.size());
        userCandy = vector<int>(ratings.size());
        for(int i=0;i<ratings.size();i++){
            rank[i] = i;
        }

        sort(
            rank.begin(), rank.end(), 
             [&](const int& lhs, const int& rhs) {
                 return ratings[lhs] < ratings[rhs] || ((ratings[lhs] == ratings[rhs]) && lhs<rhs);
             }
        );
        
        int minValue = ratings[rank[0]];
        for(int i=0;i<rank.size();i++){
            if(ratings[rank[i]] == minValue){
                userCandy[rank[i]] = 1;
            }
            else{
                int leftRate = INT_MAX, rightRate = INT_MAX, mid = ratings[rank[i]], leftuserCandy = 0, rightuserCandy = 0;
                if(rank[i]-1>=0){
                    leftRate = ratings[rank[i]-1];
                    leftuserCandy = userCandy[rank[i]-1];
                }
                if(rank[i]+1<ratings.size()){
                    rightRate = ratings[rank[i]+1];
                    rightuserCandy = userCandy[rank[i]+1];
                }
                if(leftRate > mid && mid < rightRate) userCandy[rank[i]] = 1;
                else if(leftRate < mid && mid < rightRate) userCandy[rank[i]] = leftuserCandy+1;
                else if(leftRate > mid && mid > rightRate) userCandy[rank[i]] = rightuserCandy+1;
                else if(leftRate < mid && mid > rightRate) userCandy[rank[i]] = max(leftuserCandy, rightuserCandy)+1;
                else if(leftRate == mid && mid < rightRate) userCandy[rank[i]] = 1;
                else if(leftRate == mid && mid > rightRate) userCandy[rank[i]] = rightuserCandy+1;
                else if(leftRate == mid && mid == rightRate) userCandy[rank[i]] = 1;
                else if(leftRate < mid && mid == rightRate) userCandy[rank[i]] = leftuserCandy+1;
                else if(leftRate > mid && mid == rightRate) userCandy[rank[i]] = 1;
            }
        }
        return accumulate(userCandy.begin(), userCandy.end(), 0);
    }
};