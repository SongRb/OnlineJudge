#include <cstdio>

template<class Type>
struct Node
{
	Type data;
	int npl;
	Node<Type> *left;
	Node<Type> *right;

	Node(Type v) :data(v), left(NULL), right(NULL), npl(0) {}

	~Node()
	{
	}
};


template <class Type>
class LeftistHeap
{
private:
	Node<Type> *root;


	void deleteSubTree(Node<Type> *node)
	{
		if (NULL != node)
		{
			deleteSubTree(node->left);
			deleteSubTree(node->right);
			delete node;
		}
	}

	static int npl(Node<Type>* node)
	{
		if (NULL == node) return -1;
		return node->npl;
	}


	static void swap(Node<Type>*& left, Node<Type>*& right)
	{
		Node<Type> *tmp = left;
		left = right;
		right = tmp;
	}

	static Node<Type>*& merge(Node<Type>*& h1, Node<Type>*& h2)
	{

		if (NULL == h1)
			return h2;
		else if (NULL == h2)
			return h1;

		// h1的节点值比h2要大
		// 递归合并堆
		if (h2->data<h1->data)
			swap(h1, h2);
		h1->right = merge(h1->right, h2);

		//左节点的npl值比右节点小
		if (npl(h1->right) > npl(h1->left))
			swap(h1->left, h1->right);

		// 通过这种方式来递归计算npl值
		if (h1->right ==  NULL)
			h1->npl = 0;
		else h1->npl = npl(h1->right) + 1;

		return h1;
	}

public:

	LeftistHeap() : root(NULL)
	{
	}

	~LeftistHeap()
	{
		deleteSubTree(root);
	}

	void push(Type val)
	{
		Node<Type> *newNode;
		newNode = new Node<Type>(val);
		root = merge(root, newNode);
	}
	void pop()
	{
		if (NULL != root)
		{
			Node<Type> *p = root;
			root = merge(p->left, p->right);
			delete p;
		}

	}

	void merge(LeftistHeap<Type>& rhs)
	{
		if (this == &rhs)
			return;
		root = merge(root, rhs.root);
		rhs.root = NULL;
	}

	Type getMin()
	{
		if (NULL == root)
		{
			return -1;
		}
		return root->data;
	}

};

LeftistHeap<int> forest[300000];

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		int a;
		scanf("%d", &a);
		forest[i].push(a);
	}
	for (int i = 0; i < M; i++)
	{
		int command, a, b;
		scanf("%d", &command);
		switch (command)
		{
		case 0:
			scanf("%d%d", &a, &b);
			forest[a].merge(forest[b]);
			break;
		case 1:
			scanf("%d", &a);
			printf("%d\n", forest[a].getMin());
			forest[a].pop();
			break;
		case 2:
			scanf("%d%d", &a, &b);
			forest[a].push(b);
		}
	}
	return 0;
}
