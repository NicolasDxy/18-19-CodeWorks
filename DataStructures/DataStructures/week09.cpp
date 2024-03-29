//P287N02 用C++抽象类定义一个最小堆并给出实现
//P287N03 插入
#include <utility>
#include <math.h>
#include <ctime>
template <typename T>
class MinPQ
{
public:
	virtual ~MinPQ();
	virtual bool isEmpty() const = 0;
	virtual const T &top() const = 0;
	virtual void push(const T &) = 0;
	virtual void pop() = 0;
};
template <typename T>
class MinHeap :public MinPQ<T>
{
public:
	MinHeap(int capacity = 10)
	{
		if (capacity < 1) { throw "capacity can't be negative or zero."; }
		this->capacity = capacity;
		heapsize = 0;
		heap = new T[capacity + 1];
	}
	bool isEmpty() const
	{
		return heapsize == 0;
	}
	const T& top() const
	{
		return heap[1];
	}
	void push(const T& e)
	{
		if (heapsize == capacity)
		{
			T temp = new T[capacity * 2 + 1];
			for (int i = 1; i < capacity + 1; i++)
			{
				temp[i] = heap[i];
			}
			delete[] heap;
			heap = temp;
			capacity *= 2;
		}
		int currentNode = ++heapsize;
		while (heap[currentNode / 2] > e&&currentNode != 1)
		{
			heap[currentNode] = heap[currentNode / 2];
			currentNode /= 2;
		}
		currentNode[currentNode] = e;
	}
	void pop()
	{
		if (capacity < 1) { throw "capacity can't be negative or zero."; }
		heap[1].~T();
		T lastE = heap[heapsize--];

		int currentNode = 1;
		int child = 2;
		while (child <= heapsize)
		{
			if (child<heapsize && heap[child]>heap[child + 1])
			{
				child++;
			}
			if (lastE >= heap[child])
			{
				break;
			}
			heap[currentNode] = heap[child];
			currentNode = child; child *= 2;
		}
		heap[currentNode] = lastE;
	}
private:
	T * heap;
	int heapsize;
	int capacity;

};
//P296N01 二叉搜索树删除节点
template <typename K, typename E>
class Dictionary
{
public:
	virtual bool isEmpty()const = 0;
	virtual std::pair<K, E> * get(const K&)const = 0;
	virtual void insert(const std::pair<K, E>&) = 0;
	virtual void del(const K&) = 0;
private:
};
template <typename K,typename E>
class TreeNode
{
public:
	TreeNode(std::pair<K, E> data)
	{
		this->data = data;
	}
	std::pair<K, E> data;
	TreeNode * left;
	TreeNode * right;
};
template <typename K, typename E>
class BST
{
public:
	std::pair<K, E>* get(const K& k)
	{
		return get(root, k);
	}
	std::pair<K, E>* get(TreeNode<K,E> *p, const K&k)
	{
		if (!p)
		{
			return 0;
		}
		if (k<p->data.first)
		{
			return get(p->left, k);
		}
		if (k<p->data.first)
		{
			return get(p->right, k);
		}
		return &p->data;
	}
	void insert(const std::pair<K, E>& pair)
	{
		TreeNode<K, E> *p = root;
		TreeNode<K, E> *pp = 0;
		while (p)
		{
			pp = p;
			if (pair.first < p->data.first)
			{
				p = p->left;
			}
			else if(pair.first>p->data.first)
			{
				p = p->right;
			}
			else
			{
				p->data.second = pair.second;
				return;
			}
		}
		p = new TreeNode<K, E>(pair);
		if (root)
		{
			if (pair.first<pp->data.first)
			{
				pp->left = p;
			}
			else
			{
				pp->right = p;
			}
		}
		else
		{
			root = p;
		}
	}
private:
	TreeNode<K, E> * root;
};
//P296N02 随机插入测试
void ins(BST<int,int> *  t,long n)
{
	for (int i = 0; i < n; i++)
	{

		t->insert({ rand(),rand() });
	}
}
void P296N02()
{
	BST<int, int> * exp = new BST<int, int>();
	srand(time(0));
	ins(exp, 200);
}
//P304N01 用C++模板定义森林
template<typename T>
class Forest
{
public:
	Forest * borther;
	Forest * son;
	T data;
};
template<typename T>
class Tree
{
public:
	T data;
	Tree * left;
	Tree * right;
};
//P304N04
template<typename T>
void add(Forest<T> *fo,Tree<T> *t0)
{
	if (t0->left)
	{
		fo->son = t0->left;
		add(fo->son, t0->left);
	}
	if (t0->right)
	{
		fo->son->borther = t0->right;
		add(fo->son->borther, t0->right);
	}
}
template<typename T>
Forest<T> * tran(Tree<T> *t0, Tree<T> *t1)
{
	Forest<T> *  fo;
	Tree<T> * tt0 = t0;
	Tree<T> * tt1 = t1;
	if (t0)
	{
		add(fo, t0);
		if (t1)
		{
			fo->borther = t1;
			add(fo->borther, t1);

		}
	}
	else
	{
		if (t1)
		{
			add(fo, t1);
		}
		else
		{
			return nullptr;
		}
	}
}