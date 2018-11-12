
//week08.cpp


#include "public.h"
#include <stack>
//P267N04 树中序遍历的迭代器 查看class inorderIterator
//P267N06 无递归的前序遍历器 查看class Tree函数	void preorder_noneRecursive()
//P273N01 计算树中的叶节点并给出时间复杂度	查看class Tree函数 countLeaf() 时间复杂度O(n)
//P273N04 删除二叉树中所有节点并给出时间复杂度 查看class Tree函数 	void delTree(Node<T> *node) 时间复杂度O(n)
//P273N10 [实验题]构造拷贝构造四种遍历器；
//week08_exp.cpp
#include"public.h"
#include<stack>
#include<queue>
template <typename T>
struct Node
{
	Node<T> *left = nullptr;
	Node<T> *right = nullptr;
	T data;
};
template <typename T>
class Tree
{
public:
	Tree() { root = new Node<T>; }
	Tree(Tree * const target) {
		root = new Node<T>();
		root.data = target->root;
		copySubTree(this.root, target.root);
	}
	void copySubTree(Node<T>* to, const Node<T>* from)
	{
		if (from->left)
		{
			to->left = new Node<T>();
			to->left->data = from->left->data;
			copySubTree(to->left, from->left);
		}
		if (from->right)
		{
			to->right = new Node<T>();
			to->right->data = from->right->data;
			copySubTree(to->right, from->right);
		}
	}
	~Tree() {/*TODO删除树*/ };
	void delTree(Node<T> *node)
	{
		if (node->left)
		{
			delTree(node->left);
		}
		if (node->right)
		{
			elTree(node->right);
		}
		delete[] node;
	};
	void inorder() { inorder(root); };
	void inorder(Node<T> *node)
	{
		if (node)
		{
			inorder(node->left);
			std::cout << node->data;
			inorder(node->right);
		}
	}
	void preorder() { inorder(root); };
	void preorder(Node<T> *node)
	{
		if (node)
		{
			std::cout << node->data;
			preorder(node->left);
			preorder(node->right);
		}
	}
	void preorder_noneRecursive()
	{
		Node<T> * currentNode = root;
		std::stack<Node<T> *> s;
		do
		{
			std::cout << currentNode.data;
			if (currentNode == nullptr)
			{
				currentNode = s.top()->right;
				s.pop();
			}
			else if (currentNode->left);
			{
				s.push(currentNode);
				currentNode = currentNode->left;
			}
		} while (!s.empty());
	}
	void postorder() { inorder(root); };
	void postorder(Node<T> *node)
	{
		if (node)
		{
			std::cout << node->data;
			postorder(node->left);
			postorder(node->right);
		}
	}
	long countLeaf()
	{
		return countLeaf(root);
	}
	long countLeaf(Node<T> * node)
	{
		if (node == nullptr) return 1;
		return countLeaf(node->left) + countLeaf(node->right);
	}
private:
	Node<T> root;
};
template <typename T>
class inorderIterator
{
public:
	inorderIterator(Tree<T> * tree)
	{
		currentNode = tree->root;
	};
	T *next()
	{
		while (currentNode)
		{
			s.push(currentNode);
			currentNode = currentNode->left;
		}
		if (s.empty())
			return nullptr;
		currentNode = s.top();
		s.pop();
		T &temp = currentNode->data;
		currentNode = currentNode->right;
		return &temp;
	}

private:
	std::stack<Node<T> *> s;
	Node<T> *currentNode;
};
template <typename T>
class forwardIterator
{
public:
	forwardIterator(Tree<T>* tree) { currentNode = tree.root; };
	T *next()
	{
		T *temp = currentNode.data;
		if (currentNode == nullptr)
		{
			currentNode = s.top()->right;
			s.pop();
		}
		else if (currentNode->left)
		{
			s.push(currentNode);
			currentNode = currentNode->left;
		}
		if (s.empty())
		{
			return nullptr;
		}
		return &T;
	}

private:
	std::stack<Node<T> *> s;
	Node<T> *currentNode;
};
template <typename T>
class backwardIterator
{
public:
	backwardIterator(Tree<T>* tree)
	{
		s = new std::stack<Node<T>*>;
		currentNode = tree->root;
		while (currentNode->left || currentNode->right)
		{
			s.push(currentNode);
			if (currentNode->left)
			{
				currentNode = currentNode->left;
			}
			else
			{
				currentNode = currentNode->right;
			}
		}
	}
	T* next()
	{
		if (s.empty)return nullptr;
		T* temp = currentNode->data;
		if (currentNode == s.top()->left)
		{
			currentNode = s.top()->right;
			while (currentNode->left || currentNode->right)
			{
				s.push(currentNode);
				if (currentNode->left)
				{
					currentNode = currentNode->left;
				}
				else
				{
					currentNode = currentNode->right;
				}
			}
		}
		else
		{
			currentNode = s.top();
			s.pop();
		}
		return temp;
	}
private:
	std::stack<Node<T>*> s;
	Node<T> *currentNode;
};
template <typename T>
class leavelIterator
{
	leavelIterator(Tree<T> *tree)
	{
		q.push(tree->root);
	}
	T* next()
	{
		T* temp = q.front()->data;
		if (q.front()->left)
		{
			q.push(q.front()->left);
		}
		if (q.front()->right)
		{
			q.push(q.front()->right);
		}
		q.pop();
	}
private:
	std::queue<Node<T>*> q;
};

Tree<int>;
void P267N04()
{
	//TODO..
	//添加演示代码
}
//P277N01 给线索二叉树的指定节点的左孩子插入一个指定节点并将其左孩子作为待插入节点的左孩子插入
template<typename T>
struct ThreadNode
{
	bool leftNode;
	bool rightNode;
	ThreadNode<T> * leftChild;
	ThreadNode<T> * rightChild;
	T data;
};
template<typename T>
class ThreadNodeTree
{
public:
	friend class ThreadNodeTreeIterator;
	ThreadNodeTree() { root = nullptr; }
	~ThreadNodeTree() { remove(root); }
	void remove(ThreadNode<T>* node)
	{
		if (node->leftChild != nullptr)remove(node->leftChild);
		if (node->rightChild != nullptr)remove(node->rightChild);
		if (node != nullptr)delete[] node;
	}
private:
	ThreadNode<T> * root;
};
template <typename T>
class ThreadNodeTreeIterator {
public:

private:

};

