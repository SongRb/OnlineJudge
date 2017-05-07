#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

struct Node
{
	Node* left;
	Node* right;
	int value;
	Node() {}
	Node(int v, Node* l = NULL, Node* r = NULL) :value(v), left(l), right(r)
	{

	}
};

char answer[50];
int ansTop = -1;

class BST
{
private:
	Node* root;

	void insert(Node*& t, int v)
	{
		if (t == NULL) t = new Node(v);
		else if (t->value > v) insert(t->left, v);
		else if (t->value < v) insert(t->right, v);
		else return;
	}

	void remove(Node*& t, int v)
	{
		if (t == NULL) return;

		if (t->value == v)
		{
			if (t->right != NULL)
			{
				if (t->right->left == NULL)
				{
					Node* tmp = t->right;
					t->value = t->right->value;
					t->right = t->right->right;
					delete tmp;
				}
				else
				{
					Node* tmp = t->right;
					while (tmp->left->left!=NULL)
					{
						tmp = tmp->left;
					}
					t->value = tmp->left->value;
					Node *tt = tmp->left;
					tmp->left = tmp->left->right;
					delete tt;
				}
			}
			else
			{
				Node* oldNode = t;
				t = t->left;
				delete oldNode;
			}

		}
		else if (t->value > v) remove(t->left, v);
		else remove(t->right, v);
	}

public:
	BST()
	{
		root = NULL;
	}

	~BST() {}

	void insert(int v)
	{
		insert(root, v);
	}

	void remove(int x)
	{
		remove(root, x);
	}

	void find(int x)
	{
		char result[100];
		int resTop = -1;

		result[++resTop] = '*';
		Node* p = root;
		while (p != NULL)
		{
			if (p->value == x) break;
			else if (p->value < x)
			{
				p = p->right;
				result[++resTop] = 'r';
			}
			else
			{
				p = p->left;
				result[++resTop] = 'l';
			}
		}

		if (p == NULL) printf("Nothing.\n");
		else
		{
			for (int i = 0; i <= resTop; i++)
				printf("%c", result[i]);
			printf("\n");
		}


	}

};


int main()
{
	int N;
	scanf("%d", &N);
	BST test;
	for (int i = 0; i < N; i++)
	{
		char ch;
		int d;
		getchar();
		scanf("%c %d", &ch, &d);
		switch (ch)
		{
		case '+':
			test.insert(d);
			break;
		case '-':
			test.remove(d);
			break;
		case '*':
			test.find(d);
			break;
		default:
			break;
		}
	}
}