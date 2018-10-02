class Solution {
public:
	int compareString(string value1, string value2)
	{
		eliminateZero(value1);
		eliminateZero(value2);

		if (value1.size() < value2.size()) return -1;
		else if (value1.size() > value2.size()) return 1;
		else
		{
			for (int i = 0; i < value1.size(); i++)
			{
				if (value1[i] < value2[i]) return -1;
				else if (value1[i] > value2[i]) return 1;
			}
			return 0;
		}
	}

	void eliminateZero(string& value)
	{
		int idx = 0;
		while (value[idx] == '0') idx++;
		value = value.substr(idx, value.size() - idx);
	}

	int getLastDotIdx(const string& value)
	{
		int lastIdx = value.size();
		for (int i = value.size() - 1; i >= 0; i--)
		{
			if (value[i] == '.') lastIdx = i;
			else if (value[i] != '0') return lastIdx;
		}
		return lastIdx;
	}

	void getIdxVec(const string& value, vector<int>& dotIdx)
	{
		for (int i = 0; i < value.size(); i++)
		{
			if (value[i] == '.') dotIdx.push_back(i);
		}
	}

	string process(string value, vector<int>& dotIdx)
	{
		int lastDotIdx = getLastDotIdx(value);
		value = value.substr(0, lastDotIdx);
		value += ".0";
		getIdxVec(value, dotIdx);
		return value;
	}

	int compareVersion(string version1, string version2) {
		vector<int> dotIdx1;
		vector<int> dotIdx2;
		
		version1 = process(version1, dotIdx1);
		version2 = process(version2, dotIdx2);

		int maxLength = max(dotIdx1.size(), dotIdx2.size());
		int prevIdx1 = 0, prevIdx2 = 0;
		for (int i = 0; i < maxLength; i++)
		{
			string subVer1 = version1.substr(prevIdx1, dotIdx1[i] - prevIdx1);
			if (i < dotIdx1.size()) subVer1 = version1.substr(prevIdx1, dotIdx1[i] - prevIdx1);
			else subVer1 = "0";

			string subVer2;
			if (i < dotIdx2.size()) subVer2 = version2.substr(prevIdx2, dotIdx2[i] - prevIdx2);
			else subVer2 = "0";

			int cmpRes = compareString(subVer1, subVer2);
			if (cmpRes != 0) return cmpRes;

			prevIdx1 = dotIdx1[i] + 1;
			prevIdx2 = dotIdx2[i] + 1;
		}
		return 0;
	}

};