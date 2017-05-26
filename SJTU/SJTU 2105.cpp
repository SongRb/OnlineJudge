#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;

// 维护一个单调递增的柱状图
// 
long long n, rectangle[1000005];
stack<int> s;
long long maxSquare = 0;
int main()
{
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &rectangle[i]);
	rectangle[n] = 0;//在最后添加一个0，为了后期闭合这个栈。
	for (int i = 0; i <= n; ++i)
	{
		if (s.empty() || rectangle[s.top()] < rectangle[i])s.push(i);
		// 如果栈顶元素比读入元素小，则弹栈
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