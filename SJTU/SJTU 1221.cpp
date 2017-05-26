#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

template<class Type>
class BinarySearchTree
{
private:
	struct BinaryNode
	{
		Type data;
		BinaryNode *left;
		BinaryNode *right;
		int multi;

		BinaryNode(const Type &thedata,
			BinaryNode *lt, BinaryNode *rt)
			: data(thedata), left(lt), right(rt), multi(1)
		{
		}
	};


	struct STNode
	{
		BinaryNode *node;
		int timesPop;

		STNode(BinaryNode *n = NULL) : node(n), timesPop(0) {}
	};

	BinaryNode *root;;

	int getSubTreeSize(BinaryNode *t)
	{
		if (t == NULL) return 0;
		else
		{
			return getSubTreeSize(t->right) + getSubTreeSize(t->left) + t->multi;
		}
	}


public:
	BinarySearchTree(BinaryNode *t = NULL)
	{
		root = t;
	}

	~BinarySearchTree() { makeEmpty(root); }

	bool find(const Type &x) const;

	void insert(const Type &x);

	void remove(const Type &x);


	void removeLessThan(Type x)
	{
		removeLessThan(x, root);
	}

	void removeGreaterThan(Type x)
	{
		removeGreaterThan(x, root);
	}

	void removeInterval(Type a, Type b)
	{
		removeInterval(a, b, root);
	}

	int findByRank(int i)
	{
		STNode nodeStack[1000];
		int stackTop = -1;

		STNode current(root);
		nodeStack[++stackTop] = current;
		while (stackTop != -1)
		{
			current = nodeStack[stackTop--];

			if (++current.timesPop % 2 == 0)
			{
				i -= current.node->multi;
				if (i <= 0)
				{
					return current.node->data;
				}
				if (current.node->right != NULL)
					nodeStack[++stackTop] = current.node->right;
			}
			else
			{
				nodeStack[++stackTop] = current;
				if (current.node->left != NULL)
				{
					nodeStack[++stackTop] = current.node->left;
				}
			}
		}
		if (i > 0)
			return -1;
	}

private:
	void insert(const Type &x, BinaryNode *&t) const;

	void remove(const Type &x, BinaryNode *&t) const;

	bool find(const Type &x, BinaryNode *t) const;

	void makeEmpty(BinaryNode *&t);

	void removeLessThan(Type x, BinaryNode *&r)
	{
		if (r == NULL) return;

		if (x < r->data) removeLessThan(x, r->left);
		else if (x == r->data)
		{
			makeEmpty(r->left);
			r->left = NULL;
			return;
		}
		else
		{
			BinaryNode *tmp = r;
			r = r->right;
			delete tmp;

			removeLessThan(x, r);
		}
	}

	void removeGreaterThan(Type x, BinaryNode *&r)
	{
		if (r == NULL) return;

		if (x > r->data) removeGreaterThan(x, r->right);
		else if (x == r->data)
		{
			makeEmpty(r->right);
			r->right = NULL;
			return;
		}
		else
		{
			BinaryNode *tmp = r;
			r = r->left;
			delete tmp;
			// 为了删除右侧所有树进行的一个递归
			removeGreaterThan(x, r);
		}
	}

	void removeInterval(Type a, Type b, BinaryNode *&r)
	{
		if (r == NULL) return;
		if (a >= r->data) removeInterval(a, b, r->right);
		else if (b <= r->data) removeInterval(a, b, r->left);
		else
		{
			removeGreaterThan(a, r->left);
			removeLessThan(b, r->right);
			remove(r->data, r);
		}
	}


};

template<class Type>
bool BinarySearchTree<Type>::find(const Type &x) const { return find(x, root); }

template<class Type>
bool BinarySearchTree<Type>::find(const Type &x,
	BinaryNode *t) const
{
	if (t == NULL) return false;
	else if (x < t->data) return find(x, t->left);
	else if (t->data < x) return find(x, t->right);
	else return true;
}

template<class Type>
void BinarySearchTree<Type>::insert(const Type &x) { insert(x, root); }

template<class Type>
void BinarySearchTree<Type>::insert(const Type &x, BinaryNode *&t) const
{
	if (t == NULL)
		t = new BinaryNode(x, NULL, NULL);
	else if (x < t->data) insert(x, t->left);
	else if (t->data < x) insert(x, t->right);
	else if (t->data == x) t->multi++;
}

template<class Type>
void BinarySearchTree<Type>::remove(const Type &x)
{
	remove(x, root);
}

template<class Type>
void BinarySearchTree<Type>::remove(const Type &x,
	BinaryNode *&t) const
{
	if (t == NULL) return;
	if (x < t->data) remove(x, t->left);
	else if (t->data < x) remove(x, t->right);
	else if (t->left != NULL && t->right != NULL)
	{
		if (t->multi == 1)
		{
			// 右子树最小值移到t上，再从右子树删除这个值
			BinaryNode *tmp = t->right;
			while (tmp->left != NULL)
				tmp = tmp->left;
			t->data = tmp->data;
			remove(t->data, t->right);
		}
		else t->multi--;

	}
	else
	{
		if (t->multi == 1)
		{
			BinaryNode *oldNode = t;
			t = (t->left != NULL) ? t->left : t->right;
			delete oldNode;
		}
		else t->multi--;
	}
}


template<class Type>
void BinarySearchTree<Type>::makeEmpty(BinaryNode *&t)
{
	if (t != NULL)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
}



int main()
{
	int N;
	scanf("%d", &N);

	BinarySearchTree<int> tree;

	for (int i = 0; i < N; i++)
	{
		char command[20];
		scanf("%s", command);
		if (command[0] == 'i')
		{
			int x;
			scanf("%d", &x);
			tree.insert(x);
		}
		else if (command[0] == 'd')
		{
			int x;
			scanf("%d", &x);

			if (strlen(command) == 6)
				tree.remove(x);
			else if (strlen(command) == 16)
				tree.removeLessThan(x);
			else if (strlen(command) == 19)
				tree.removeGreaterThan(x);
			else if (strlen(command) == 15)
			{
				int y;
				scanf("%d", &y);
				tree.removeInterval(x, y);
			}
		}
		else if (command[0] == 'f')
		{
			if (strlen(command) == 4)
			{
				int x;
				scanf("%d", &x);
				if (tree.find(x)) printf("Y\n");
				else printf("N\n");
			}
			else if (strlen(command) == 8)
			{
				int x;
				scanf("%d", &x);
				int result = tree.findByRank(x);
				if (result != -1) printf("%d\n", result);
				else printf("N\n");
			}
		}
	}
	return 0;
}