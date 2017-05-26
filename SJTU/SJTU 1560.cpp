#include <cstdio>

using namespace std;

struct Node
{
	int value;
	Node *left, *right;
};

char answer[50];
int ansTop = -1;

void insert(Node*& t, int val)
{
	if (t == NULL)
	{
		t = new Node;
		t->left = NULL;
		t->right = NULL;
		t->value = val;
	}
	else if (t->value == val) return;
	else if (t->value > val) insert(t->left, val);
	else insert(t->right, val);
}

bool find(Node* t, int v)
{
	if (t == NULL) return false;
	else if (t->value == v) return true;
	else if (t->value > v)
	{
		answer[++ansTop] = 'l';
		return find(t->left, v);
	}
	else
	{
		answer[++ansTop] = 'r';
		return find(t->right, v);
	}
}

void remove(Node*& t, int val)
{
	if (t == NULL) return;
	else if (t->value == val)
	{
		Node *tmp;
		if (t->right == NULL)
		{
			tmp = t;
			t = t->left;
			delete tmp;
		}
		else if (t->right->left == NULL)
		{
			tmp = t->right;
			t->value = t->right->value;
			t->right = t->right->right;
			delete tmp;
		}
		else
		{
			for (tmp = t->right; tmp->left->left != NULL; tmp = tmp->left);
			t->value = tmp->left->value;
			Node *tt = tmp->left;
			tmp->left = tmp->left->right;
			delete tt;
		}
	}
	else if (t->value > val) remove(t->left, val);
	else remove(t->right, val);
}

int main()
{
	int n, i, t;
	char f;
	scanf("%d", &n);
	Node *head = NULL;
	for (i = 0; i < n; ++i)
	{
		getchar();
		scanf("%c %d", &f, &t);
		if (f == '+') insert(head, t);
		else if (f == '-') remove(head, t);
		else
		{
			if (find(head, t))
			{
				printf("*");
				for (int j = 0; j <= ansTop; j++)
					printf("%c", answer[j]);
				printf("\n");
				ansTop = -1;
			}
			else printf("Nothing.\n");
		}
	}
}