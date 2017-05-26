#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;

// ά��һ��������������״ͼ
// 
long long n, rectangle[1000005];
stack<int> s;
long long maxSquare = 0;
int main()
{
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &rectangle[i]);
	rectangle[n] = 0;//��������һ��0��Ϊ�˺��ڱպ����ջ��
	for (int i = 0; i <= n; ++i)
	{
		if (s.empty() || rectangle[s.top()] < rectangle[i])s.push(i);
		// ���ջ��Ԫ�رȶ���Ԫ��С����ջ
		else
		{
			int tmp = s.top();
			s.pop();
			long long square = rectangle[tmp] * (s.empty() ? i : i - s.top() - 1);
			if (maxSquare < square)maxSquare = square;
			--i;
		}
	}
	printf("%d", maxSquare);
}