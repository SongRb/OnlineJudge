class Solution {
public:

    	void reverseWords(string &s) {
		int length = s.size();
		if (length == 0) return;
		int start = 0, end = length - 1;
		while (start<=length-1 && s[start] == ' ')
			start++;
		while (end>=0 && s[end] == ' ')
			end--;
		if (end < 0) { s = ""; return; }
		s = s.substr(start, end - start + 1);
		end = end - start;
		while (end >= 0 && s[end] != ' ')
			end--;
		int res = end + 1;
		while (end >= 0 && s[end] == ' ')
			end--;
		// end starts from non-empty character
		int j = end;
		while (j>=0)
		{
			int k = 0;
			while (j>=k && s[j - k] != ' ')
				k++;
			s.append(" ");
			if (j == k)
			{
				s.append(s.substr(0, k));
				break;
			}
			else
			{
				s.append(s.substr(j - k + 1, k));
			}
			while (j>=k && s[j - k] == ' ')
				k++;
			j = j - k;
		}
		s = s.substr(res);
	}
};