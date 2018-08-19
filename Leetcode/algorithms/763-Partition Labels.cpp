struct Node
{
    int left;int right;
    Node(int l, int r):left(l),right(r){}
};

    bool my(Node l, Node r){return l.right>r.right;}

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        int location[27][2] = {{0}};
        int length = S.size();
        for(int i=0;i<length;i++)
        {
            int index = S[i]-'a';
            
            if(location[index][0] == 0) 
            {
                location[index][0]=i+1;
                location[index][1]=i+1;
            }
            else location[index][1]=i+1;
        }
        
        
        vector<Node> vec;
        for(int i=0;i<26;i++)
        {
            if(location[i][0] !=0)
            {
                vec.push_back(Node(location[i][0], location[i][1]));
            }
        }
        sort(vec.begin(),vec.end(),my);
        
        auto it = vec.begin();
        while(true)
        {
            int left = it->left;
            int right = it->right;
            while(it!=vec.end() && it->right>=left)
            {
                left = left > it->left ? it->left : left;
                it++;
            }
            res.push_back(right-left+1);
            if(it==vec.end()) break;
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};