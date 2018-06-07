class Solution {
public:
    int removeNum;
    set<string> result;
    string getString(const string& s, vector<int>& vec)
    {
        string res;
        int length = s.size();
        int length2 = vec.size();
        
        // vec empty means??
        
        int k=0;
        for(int i=0;i<length;i++)
        {
            if(k<length2)
            {
                if(i<vec[k] && !(s[i]=='(' || s[i]==')'))
                {
                    res.append(1, s[i]);
                }
                else if(i==vec[k])
                {
                    res.append(1, s[i]);
                    k++;
                }
            }
            else
            {
                if(!(s[i]=='(' || s[i]==')'))
                {
                    res.append(1,s[i]);
                }
            }
            // cout<<i<<" "<<s[k]<<" "<<res<<endl;
        }
        return res;
    }
    
    void printVec(const vector<int>& vec)
    {
        for(auto& v:vec)cout<<v<<" ";
        cout<<endl;
    }
    
    void rec(const string& s, int idx, vector<int>& vec, int stkSize, int num)
    {
        if(num>removeNum) return;
        else if(stkSize==0 && idx>s.size())
        {
            if(num==removeNum)
            {
                result.insert(getString(s,vec));
                // printVec(vec);
                // cout<<num<<" "<<result[result.size()-1]<<endl;
            }
            else if(num<removeNum)
            {
                result.erase(result.begin(), result.end());
                result.insert(getString(s,vec));
                // printVec(vec);
                // cout<<num<<" "<<result[result.size()-1]<<endl;
                removeNum = num;
            }
            return;
        }
        else if(stkSize!=0 && idx>s.size()) return;
        
        int length = s.size();
        int i=idx;
        while(s[i]!='(' && s[i]!=')') i++;
        // Remove it or not?
        if(i<length && s[i]=='(')
        {
            // ? Must append?
            vec.push_back(i);
            rec(s, i+1, vec, stkSize+1,num);
            vec.pop_back();
            rec(s, i+1, vec, stkSize,num+1);
        }
        else if(i<length && s[i]==')')
        {
            if(stkSize==0) 
            {
                rec(s, i+1, vec, stkSize, num+1);
            }
            else
            {
                // ? Must append?
                vec.push_back(i);
                rec(s, i+1, vec, stkSize-1, num);
                vec.pop_back();
                rec(s, i+1, vec, stkSize, num+1);
            }
        }
        else
        {
            rec(s, i+1, vec, stkSize, num);
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        int length = s.size();
        removeNum = length;
        vector<int> vec;
        rec(s, 0, vec, 0, 0);
        return vector<string>(result.begin(), result.end());
    }
};