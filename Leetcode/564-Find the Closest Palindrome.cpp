class Solution {
public:
	// reDouble: 0; reSingle: 1
	string reAll(string n, int t)
	{
		int length = n.size();
		for (int i = length - 1-t; i >= 0; i--)
		{
			n.append(1, n[i]);
		}
		return n;
	}
	long long int nearestPalindromic2(string n)
	{
		int length = n.size();
		long long int ori = stoll(n);
		int t = length % 2;
		string tmpN = n.substr(0, length / 2 + t);
		long long int base = stoll(tmpN);
		long long int res1 = stoll(reAll(tmpN, t));

		long long int result;
		if (res1 != ori) result = res1;
		else
		{
			result = -1;
		}
		string res2Str = to_string(base + 1);
		long long int res2;

		if (res2Str.size() != tmpN.size())
		{
			res2 = stoll(reAll(res2Str, 1 - t));
		}
		else
		{
			res2 = stoll(reAll(res2Str, t));
		}

		if (result == -1 || abs(result - ori)>abs(res2 - ori) || (abs(result - ori) == abs(res2 - ori) && res2<result)) result = res2;

		if (base>1)
		{
			string res3Str = to_string(base - 1);
			long long int res3;
			if (res3Str.size() != tmpN.size())
			{
				res3 = stoll(reAll(res3Str, 1 - t));
			}
			else
			{
				res3 = stoll(reAll(res3Str, t));
			}
			if (result == -1 || abs(result - ori)>abs(res3 - ori) || (abs(result - ori) == abs(res3 - ori) && res3<result)) result = res3;
		}
		return result;
	}

	bool checkPalindromic(const string& n)
	{
		int i = 0;
		int length = n.size();
		while (i < length-1 - i)
		{
			if (n[i] != n[length - 1 - i]) return false;
			i++;
		}
		return true;
	}

	string nearestPalindromic(string n) {
		int length = n.size();
		if (length == 0) return "-1";
		else if (length == 1)
		{
			if (n == "0") return "-1";
			else if (n == "1")
			{
				return "0";
			}
			else
			{
				return to_string(stoi(n) - 1);
			}
		}


		if (length == 2)
		{
			if (n == "11" || n == "10") return "9";
		}
		long long int ori = stoll(n);
		string nm1 = to_string(stoll(n) - 1);
		string np1 = to_string(stoll(n) + 1);
		long long int res1 =nearestPalindromic2(np1);
		long long int res2 = nearestPalindromic2(nm1);
		long long int res = nearestPalindromic2(to_string(stoll(n)));

		long long int result = -1;
		long long int ress[5];
		ress[0] = res; ress[1] = res1; ress[2] = res2;
		int ressIndex = 3;
		if (checkPalindromic(nm1)) ress[ressIndex++] = stoll(nm1);
		if (checkPalindromic(np1)) ress[ressIndex++] = stoll(np1);
		for (int i = 0; i < ressIndex; i++)
		{
			if ((result == -1 || abs(result-ori)>abs(ress[i]-ori) || (abs(result - ori)== abs(ori-ress[i]) && result>ress[i])) && ress[i]!=ori   ) result = ress[i];
		}
		return to_string(result);
	}
};