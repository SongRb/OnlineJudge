

class Solution {
public:

	string inS;

	bool checkValid(const string& str)
	{
		if (str.length() == 1) return true;
		return str[0] != '0';
	}

	bool checkSize(int i, int length)
	{
		if (length >= 4) return false;
		string str = inS.substr(i, length);

		if (checkValid(str))
		{
			int myint = stoi(str);
			return myint <= 255;
		}
		return false;
	}
	vector<string> restoreIpAddresses(string s) {
		//int dot[20];
		//memset(dot, 0, 20 * sizeof(int));
		inS = s;
		//trace(3, dot, 0);
		vector<string> result;
		int length = s.size();
		for (int i = 0; i <= 2; i++)
		{
			for (int j = i+1; j <= min(i + 3,length-2); j++)
			{
				for (int k = j + 1; k <= min(j + 3, length - 2); k++)
				{
					if (checkSize(0, i + 1) && checkSize(i + 1, j - i) && checkSize(j + 1, k - j) && checkSize(k+1,length-1-k)  )
					{
						char res[20];
						int l = 0, m=0;
						while(l<length)
						{
							res[m] = s[l];
							if (i == l || j == l || k==l)
							{
								res[++m] = '.';
							}
							l++;
							m++;
						}
						res[length + 3] = '\0';
						result.push_back(string(res));
					}
				}
			}
		}
		return result;
	}
};


