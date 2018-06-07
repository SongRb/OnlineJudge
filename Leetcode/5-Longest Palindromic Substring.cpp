class Solution {
public:
	string longestPalindrome(string s) {

		string max_string = "";
		int length = s.size();
		for (int i = 0; i<length; i++) {
			string length1 = expandString(s, i, i + 1);
			string length2 = expandString(s, i, i);

			if (max_string.size()<length1.size())
				max_string = length1;

			if (max_string.size()<length2.size())
				max_string = length2;
		}

		return max_string;


	}


	string expandString(string s, int left, int right) {
		while (left >= 0 && right<s.size() && s[left] == s[right]) {
			left--;
			right++;
		}
		return s.substr(left+1, right - left-1);
	}
    
};