#include <cstdio>
#include <iostream>

#include <algorithm>
#include <vector>

using namespace std;

struct Fraction
{
	int num;
	int den;

	Fraction(){}
	Fraction(int n, int d) :num(n), den(d) {}
};

bool fraCmp(const Fraction& a, const Fraction& b)
{
	return a.num*b.den < a.den*b.num;
}

bool equal(const vector<Fraction>::iterator& a, const vector<Fraction>::iterator& b)
{
	return a->num*b->den == a->den*b->num;
}

void swap(int&a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}


bool isSplited(int a, int b)
{
	int t;
	if (a < b)
	{
		t = a;
		a = b;
		b = t;
	}
	while (t = a%b)
	{
		a = b;
		b = t;
	}

	if (b == 1)
		return false;
	return true;
}

int main()
{
	std::vector<Fraction> test;

	int N;
	scanf("%d", &N);
	for(int i=1;i<=N;i++)
		for (int j = 1; j < i; j++)
		{
			if (!isSplited(i, j))
			{
				test.push_back(Fraction(j, i));
			}
		}

	std::sort(test.begin(), test.end(),fraCmp);

	cout << "0/1" << endl;

	if (N > 1)
	{
		vector<Fraction>::iterator prevIt = test.begin();
		cout << prevIt->num << "/" << prevIt->den << endl;
		for (vector<Fraction>::iterator it = test.begin() + 1; it != test.end(); it++)
		{
			if (!equal(prevIt, it))
			{
				cout << it->num << "/" << it->den << endl;
				prevIt = it;
			}

		}
	}


	cout << 1 << "/" << 1 << endl;
	//system("pause");

}