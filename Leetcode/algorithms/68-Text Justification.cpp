class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int length = words.size();
        int i=0;
        vector<string> result;
        while(i<length)
        {
            int tmpSize = 0;
            vector<string> candiVec;
            int cnt = 0;
            // Check if next word can be appended.
            while(i<length && tmpSize+words[i].size()+cnt<=maxWidth) 
            {
                tmpSize+=words[i].size();
                candiVec.push_back(words[i]);
                i++;
                cnt++;
            }
            int wordLen = accumulate(candiVec.begin(), candiVec.end(), 0, [](const int& val, const string& str){return val+str.size();});
            string line = "";
            if(i==length)
            {
                for(const auto& str: candiVec)
                {
                    line.append(str);
                    if(line.size()<maxWidth) line.append(1,' ');
                }
                line.append(maxWidth-line.size(),' ');
            }
            else
            {
                if(candiVec.size()>1)
                {
                    int space = (maxWidth-wordLen)/(candiVec.size()-1);
                    int leftSpace = (maxWidth-wordLen)%(candiVec.size()-1);
                    int wordNum = candiVec.size();
                    for(int i=0;i<wordNum;i++)
                    {
                        line.append(candiVec[i]);
                        if(i!=wordNum-1) line.append(space+(leftSpace>0), ' ');
                        leftSpace--;
                    }   
                }
                else
                {
                    line = candiVec[0];
                    line.append(maxWidth-wordLen,' ');
                }
            }
            cout<<line<<endl;
            result.push_back(line);
        }
        return result;
    }
};