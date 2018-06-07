
class Solution {
public:
	int index = 0;
	int modifyNum = 0;
	int currentLength;
	vector<int> tooLong;
	int tooLongSize;

	void decreaseSize()
	{
		vector<int> vec[3];
		for (int i = index; i < tooLongSize; i++)
		{
			vec[tooLong[i] % 3].push_back(tooLong[i]);
		}

		int sindex[3];
		memset(sindex, 0, 3 * sizeof(int));
		bool lengthSatisfied = false;
		for (int i = 0; i < 2; i++)
		{
			int j = 0;
			for (; j < vec[i].size(); j++)
			{
				//if (currentLength >= i + 1 + 20)
				//{
					
					if (vec[i][j] - (i + 1) >= 3)
					{
						vec[2].push_back(vec[i][j] - (i + 1));
					}
					modifyNum += (i + 1);
					currentLength -= (i + 1);
					if (currentLength <= 20) { lengthSatisfied = true; j++; break; }
				//}
				//else
				//{
				//	break;
				//}
			}
			sindex[i] = j;
			if (lengthSatisfied) break;
		}
		sindex[2] = 0;

		if (currentLength > 20)
		{
			int vindex = 0;
			int vec2size = vec[2].size();
			while (vindex<vec2size)
			{
				int cur = vec[2][vindex]-2;
				if (currentLength - cur > 20)
				{
					vindex++;
					currentLength -= cur;
					modifyNum += cur;
				}
				else
				{
					// Length already satisfied
					vec[2][vindex] -= (currentLength - 20);
					if (vec[2][vindex] < 3) vindex++;
					modifyNum += currentLength - 20;
					currentLength = 20;
					tooLong.clear();
					while (vindex < vec2size)
					{
						tooLong.push_back(vec[2][vindex++]);
					}
					tooLongSize = tooLong.size();
					index = 0;
					return;
				}
			}
			// length not satisfied, all continued seq processed
			index = tooLongSize;
			modifyNum += currentLength - 20;
			currentLength = 20;
		}
		// current length is satisfied, but some continued seq are left..
		else
		{
			tooLong.clear();
			for (int i = 0; i < 3; i++)
			{
				int length = vec[i].size();
				for (int j = sindex[i]; j < length; j++)
				{
					tooLong.push_back(vec[i][j]);
				}
			}
			index = 0;
			tooLongSize = tooLong.size();
		}







	}

	void increaseSize()
	{
		while (index < tooLongSize && currentLength < 6)
		{
			int toInsert = tooLong[index] / 3;

			if (currentLength + toInsert <= 6)
			{
				currentLength += toInsert;
				modifyNum += toInsert;
				index++;
			}
			else
			{
				tooLong[index] -= (6 - currentLength) * 3;
				modifyNum += (6 - currentLength);
				currentLength = 6;
				if (tooLong[index] < 3) index++;
			}
		}
		if (index == tooLongSize)
		{
			modifyNum += (6 - currentLength);
			currentLength = 6;
		}
	}

	void keepSize()
	{
		while (index < tooLongSize)
		{
			modifyNum += tooLong[index++] / 3;
		}
	}

	int strongPasswordChecker(string s) {
		index = 0, modifyNum = 0, currentLength = 0;
		tooLong.clear();
		tooLongSize = 0;
		bool hasLower = false, hasUpper = false, hasDigit = false;
		int char2Insert = 3;
		int length = s.size();

		int tmpLength = 1;
		for (int i = 0; i < length; i++)
		{
			if (s[i] >= 'a' && s[i] <= 'z') { hasLower = true; }
			if (s[i] >= 'A' && s[i] <= 'Z') { hasUpper = true; }
			if (s[i] >= '0' && s[i] <= '9') { hasDigit = true; }

			if (i < length - 1 && s[i] == s[i + 1])
				tmpLength++;
			else
			{
				if (tmpLength >= 3) tooLong.push_back(tmpLength);
				tmpLength = 1;
			}
		}
		char2Insert = char2Insert - hasDigit - hasLower - hasUpper;

		if (length >= 6 && length <= 20 && char2Insert == 0 && tooLong.empty()) return 0;
		currentLength = length;

		tooLongSize = tooLong.size();

		if (currentLength < 6)
		{
			while (char2Insert > 0 && index < tooLongSize)
			{
				tooLong[index] -= 2;
				modifyNum++;
				char2Insert--;
				currentLength++;
				if (tooLong[index] < 3) index++;
			}
			modifyNum += char2Insert;
			currentLength += char2Insert;
		}
		else if (currentLength > 20)
		{
			// try to replace
			while (char2Insert > 0 && index < tooLongSize)
			{
				tooLong[index] -= 3;
				modifyNum++;
				char2Insert--;
				if (tooLong[index] < 3) index++;
			}
			modifyNum += char2Insert;
		}
		else
		{
			while (char2Insert > 0 && index < tooLongSize)
			{
				tooLong[index] -= 3;
				modifyNum++;
				char2Insert--;
				if (tooLong[index] < 3) index++;
			}
			modifyNum += char2Insert;
		}

		if (currentLength < 6) { increaseSize(); }
		else if (currentLength > 20) { decreaseSize(); }
		keepSize();
		return modifyNum;
	}
};
