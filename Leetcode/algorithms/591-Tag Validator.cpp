
class Solution {
public:
	bool isValid(string code) {
		stack<string> stk;
		int length = code.size();
		if (length == 0) return false;
		else if (code[0] != '<') return false;

		int i = 0;
		while (i<length)
		{
			if (code[i] == '<')
			{
				// Process content of CDATA
				if (code[i + 1] == '!')
				{
					if (i<length - 8 && code.substr(i + 2, 7).compare("[CDATA[") == 0)
					{
						i = i + 9;
						while (i <= length - 3 && code.substr(i, 3).compare("]]>") != 0)
						{
							i++;
						}
						if (i == length - 2) return false;
						i = i + 3;
					}
                    else return false;
				}
				else
				{
					bool startTag = true;
					if (code[i + 1] == '/')
					{
						startTag = false;
						i = i + 2;
					}
					else i++;
					int start = i;
					while (true)
					{
						if (code[i] == '>')
							break;
						else if (code[i]<'A' || code[i]>'Z')
							return false;
						i++;
					}
					if (i == start) return false;
					else if (i - start>9) return false;
					if (startTag)
						stk.push(code.substr(start, i - start));
					else
					{
						string tag = code.substr(start, i - start);
						if (stk.empty()) return false;
						if (tag.compare(stk.top()) != 0) return false;
						stk.pop();
					}
					i++;
				}

			}
			else
			{
				i++;
			}
			if (stk.empty()) break;
		}
		return stk.empty() && i == length;
	}
};
