//week08.cpp
#include "public.h"
#include <stack>
template <typename T>
struct Node
{
	Node<T> *left;
	Node<T> *right;
	T data;
};
template <typename T>
class Tree
{
  public:
	Tree() { root = new Node<T>; }
	~Tree(){/*TODO删除树*/};
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

  private:
	Node<T> root;
};
template <typename T>
class inorderIterator
{
  public:
	inorderIterator(Node<T> *node) { currentNode = node; };
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
	forwardIterator(Node<T> *node) { currentNode = node; };
	T *next()
	{
		T *temp = currentNode.data;
		if(currentNode==nullptr)
		{
			currentNode=s.top()->right;
			s.pop();
		}
		else (currentNode->left)
		{
			s.push(currentNode);
			currentNode = currentNode->left;
		}
		if(s.empty())
		{
			return nullptr;
		}
		return &T;
	}

  private:
	std::stack<Node<T> *> s;
	Node<T> *currentNode;
};

Tree<int>;
