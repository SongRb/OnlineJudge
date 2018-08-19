class Solution {
public:
    bool isValid(const char& ch)
    {
        return (ch >='a' && ch <='z') || (ch >='A' && ch <='Z') || (ch >='0' && ch <='9');
    }
    
    bool isPalindrome(string s) {
        int left =0, right = s.size()-1;
        while(left<=right)
        {
            while(left<=right && !isValid(s[left])) left++;
            if(left>right) break;
            while(left<=right && !isValid(s[right])) right--;
            if(left>right) break;
            if(tolower(s[left])!=tolower(s[right])) return false;
            left++;right--;
        }
        return true;
    }
};