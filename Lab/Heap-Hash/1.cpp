#include <iostream>
#include <fstream>
#include <math.h>
#include <queue>
using namespace std;

enum BalanceValue
{
	LH = -1,
	EH = 0,
	RH = 1
};

void printNSpace(int n)
{
	for (int i = 0; i < n - 1; i++)
		cout << " ";
}

void printInteger(int &n)
{
	cout << n << " ";
}

template <class T>
class Node
{
public:
	T data;
	Node<T> *left;
	Node<T> *right;
	BalanceValue balance;

	Node(const T &val)
	{
		data = val;
		left = right = NULL;
		balance = EH;
	}
};

template <class T>
class AVL
{
private:
	Node<T> *root;

protected:
	void clearRec(Node<T> *&);
	int getHeightRec(Node<T> *);

	//TODO Methods
	Node<T> *rotateRight(Node<T> *&node);
	Node<T> *rotateLeft(Node<T> *&node);
	Node<T> *leftBalance(Node<T> *&node);
	Node<T> *rightBalance(Node<T> *&node);

	Node<T> *insertRec(Node<T> *&node, const T &value, bool &taller);

public:
	AVL()
	{
		this->root = NULL;
	}

	~AVL()
	{
		this->clear();
	}

	void clear();
	int getHeight();
	void printTreeStructure();

	// TODO Methods
	void insert(const T &value);
};

int main(int argc, char *argv[])
{
	ifstream ifs;
	ifs.open("input.txt", ifstream::in);

	string line;
	getline(ifs, line);
	int size = stoi(line);

	AVL<int> *tree = new AVL<int>();
	for (int i = 0; i < size; i++)
	{
		getline(ifs, line);
		tree->insert(stoi(line));
	}

	tree->printTreeStructure();

	delete tree;

	ifs.close();

	return 0;
}

template <class T>
Node<T> *AVL<T>::rotateRight(Node<T> *&node)
{
	//TODO
	Node<T> *temp = node->left;
	node->left = temp->right;
	temp->right = node;
	return temp;
}

template <class T>
Node<T> *AVL<T>::rotateLeft(Node<T> *&node)
{
	//TODO
	Node<T> *temp = node->right;
	node->right = temp->left;
	temp - < left = node;
	return temp;
}

template <class T>
Node<T> *AVL<T>::insertRec(Node<T> *&node, const T &value, bool &taller)
{
	//TODO
	if (root == NULL)
	{
		Node<T> *pNew = new Node<T>(value);
		node = pNew;
		return node;
	}
	if (value < node->data)
	{
		node->left=insertRec(node->left,value,taller);
		if(taller){
			if(node->balance=='LH')
			node=leftbalance(root,taller)
		}
	}
}

template <class T>
void AVL<T>::insert(const T &value)
{
	//TODO
}

template <class T>
Node<T> *AVL<T>::rightBalance(Node<T> *&node)
{
	//TODO
}

template <class T>
Node<T> *AVL<T>::leftBalance(Node<T> *&node)
{
	//TODO
}

template <class T>
int AVL<T>::getHeightRec(Node<T> *node)
{
	if (node == NULL)
		return 0;
	int lh = this->getHeightRec(node->left);
	int rh = this->getHeightRec(node->right);
	return (lh > rh ? lh : rh) + 1;
}

template <class T>
int AVL<T>::getHeight()
{
	return this->getHeightRec(this->root);
}

template <class T>
void AVL<T>::clearRec(Node<T> *&node)
{
	if (node != NULL)
	{
		this->clearRec(node->left);
		this->clearRec(node->right);
		delete node;
		node = NULL;
	}
}

template <class T>
void AVL<T>::clear()
{
	this->clearRec(this->root);
}

template <class T>
void AVL<T>::printTreeStructure()
{
	int height = this->getHeight();

	if (this->root == NULL)
	{
		cout << "NULL\n";
		return;
	}
	queue<Node<T> *> q;
	q.push(root);
	Node<T> *temp;
	int count = 0;
	int maxNode = 1;
	int level = 0;
	int space = pow(2, height);
	printNSpace(space / 2);
	while (!q.empty())
	{
		temp = q.front();
		q.pop();

		if (temp == NULL)
		{
			cout << " ";
			q.push(NULL);
			q.push(NULL);
		}
		else
		{

			cout << temp->data;
			q.push(temp->left);
			q.push(temp->right);
		}
		printNSpace(space);
		count++;
		if (count == maxNode)
		{
			cout << endl;
			count = 0;
			maxNode *= 2;
			level++;
			space /= 2;
			printNSpace(space / 2);
		}
		if (level == height)
			return;
	}
}