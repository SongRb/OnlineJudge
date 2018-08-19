class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        
        string result[numRows];
        for(int i=0;i<numRows;i++){
            result[i]="";
        }
        
        
        int length = s.size();
        int t = 2*numRows-2;
        for(int i=0;i<length;i++){
            int offset = i%t;
            if(offset<numRows){
                result[offset].append(string(1,s[i]));
            }
            else{
                result[2*numRows-2-offset].append(string(1,s[i]));
            }
        }
        
        string res="";
        for(int i=0;i<numRows;i++){
            res.append(result[i]);
        }
        
        return res;
        
    }
};