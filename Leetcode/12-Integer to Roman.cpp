class Solution {
public:
    void addString(string& res, int num ,char id1, char id2, char id3)
    {
        if(num<4 && num>0)
        {
            res.append(num, id1);
        }
        else if(num==4)
        {
            res+=id1;
            res+=id2;
        }
        else if(num>4 && num<9)
        {
            res+=id2;
            res.append(num-5, id1);
        }
        else if(num==9)
        {
            res.append(1, id1);
            res+=id3;
        }
    }
    
    string intToRoman(int num) {
        int ones = num%10;
        int tens = (num/10)%10;
        int huns = (num/100)%10;
        int thus = num/1000;
        string result(thus,'M');
        addString(result, huns, 'C', 'D','M');
        addString(result, tens, 'X', 'L','C');
        addString(result, ones, 'I', 'V','X');
        return result;
    }
};