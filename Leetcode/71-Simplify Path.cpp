class Solution {
public:
    string simplifyPath(string path) {
        deque<string> dq;
        int length = path.size();
        int prevIndex = 0;
        for(int i=1;i<length;i++)
        {
            while(path[i]!='/') i++;
            if(i!=prevIndex+1)
            {
                auto item = path.substr(prevIndex+1, i-prevIndex-1);
                if(item!=".")
                {
                    if(item==".." && !dq.empty()) dq.pop_back();
                    else if(item!="..") dq.push_back(item);
                }     
            }
            prevIndex = i;
        }
        string result;
        if(dq.empty())
        {
            result = "/";
        }
        else
        {
            for(const auto& item: dq)
            {
                result.append(1,'/');
                result.append(item);
            }   
        }
        return result;
    }
};