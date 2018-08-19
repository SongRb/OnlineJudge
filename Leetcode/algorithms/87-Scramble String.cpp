
class Solution {
public:
	bool check2(const string& s1, int left1, int right1, const string& s2, int left2, int right2)
	{
		unordered_map<char, int> mp;
		for (int i = left1; i<right1; i++)
		{
			mp[s1[i]]++;
		}
		int cnt = mp.size();
		for (int i = left2; i<right2; i++)
		{
			if (mp.find(s2[i]) == mp.end()) return false;
			else
			{
				mp[s2[i]]--;
				if (mp[s2[i]] == 0) cnt--;
				if (mp[s2[i]]<0) return false;
			}
		}
		return cnt == 0;
	}

	bool check(const string& s1, int left1, int right1, const string& s2, int left2, int right2)
	{
		// cout << endl;
		// cout << s1.substr(left1, right1 - left1) << " " << s2.substr(left2, right2 - left2) << endl;
		// cout << (s1[left1] == s2[left2]) << endl;
		if (left1 + 1 == right1) return s1[left1] == s2[left2];
		for (int k = 1; k<right1 - left1; k++)
		{
			if (check2(s1, left1, left1 + k, s2, left2, left2 + k))
			{
				// cout << k << " " << s1.substr(left1, k) << " " << s2.substr(left2, k) << endl;
				if (check(s1, left1, left1 + k, s2, left2, left2 + k) && check(s1, left1 + k, right1, s2, left2 + k, right2)) return true;
			}

			if (check2(s1, left1, left1 + k, s2, right2 - k, right2))
			{
				// cout << k << " " << s1.substr(left1, k) << " " << s2.substr(right2 - k, k) << endl;
				if (check(s1, left1, left1 + k, s2, right2 - k, right2) && check(s1, left1 + k, right1, s2, left2, right2-k)) return true;
			}
		}
		return false;
	}

	bool isScramble(string s1, string s2) {
		int length1 = s1.size();
		int length2 = s2.size();
		if (length1 != length2) return false;
		else if (check2(s1, 0, length1, s2, 0, length2))
		{
			return check(s1, 0, length1, s2, 0, length2);
		}
		else return false;
	}
};