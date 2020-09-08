#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

template <class T>
class Node
{
public:
	T data;
	Node *link;

	Node(const T &val)
	{
		data = val;
		link = NULL;
	}
};

template <class T>
class Queue
{
private:
	Node<T> *frontPtr;
	Node<T> *rearPtr;
	int count;

public:
	Queue()
	{
		frontPtr = rearPtr = NULL;
		count = 0;
	}
	~Queue()
	{
		clear();
	}
	void print2Console();

	// TODO Methods

	/*
		Clear all elements of queue
		- Input: none
		- Output: none
	*/
	void clear();

	/*
		Determine if the queue is empty
		- Input: none
		- Output: return true if empty otherwise return false
	*/
	bool isEmpty();

	/*
		Get the size of the queue
		- Input: none
		- Output: return the queue size
	*/
	int size();

	/*
		Get the reference to the front data
		- Input: none
		- Output: return the reference to the front data
		- Exception: throw "Empty queue!" if the queue is empty
	*/
	T &front();

	/*
		Get the reference to the rear data
		- Input: none
		- Output: return the reference to the rear data
		- Exception: throw "Empty queue!" if the queue is empty
	*/
	T &rear();

	/*
		Push new element into the queue
		- Input: the value to be pushed
		- Output: none
	*/
	void enQueue(const T &val);

	/*
		Remove an element from the queue
		- Input: the value to be removed
		- Output: return 1 if successful otherwise return 0 (the queue is empty)
	*/
	int deQueue(T &valOUt);
};

int main(int argc, char *argv[])
{
	ifstream ifs;
	ifs.open("input.txt", ifstream::in);

	Queue<int> *queue = new Queue<int>();

	int code, data;
	while (ifs.good())
	{
		ifs >> code;
		switch (code)
		{
		case 0:
			cout << "0 enQueue: ";
			ifs >> data;
			queue->enQueue(data);
			break;
		case 1:
			cout << "1 deQueue: ";
			if (queue->deQueue(data))
				cout << data << endl;
			break;
		case 2:
			cout << "2 front: ";
			try
			{
				data = queue->front();
				cout << data << endl;
			}
			catch (const char *msg)
			{
				cout << msg << endl;
			}
			break;
		case 3:
			cout << "3 rear: ";
			try
			{
				data = queue->rear();
				cout << data << endl;
			}
			catch (const char *msg)
			{
				cout << msg << endl;
			}
			break;
		case 4:
			cout << "4 clear: ";
			queue->clear();
			break;
		case 5:
			cout << "5 isEmpty: ";
			cout << queue->isEmpty() << endl;
			break;
		}
		cout << "Queue size " << queue->size() << ": ";
		queue->print2Console();
		cout << endl;
	}
	delete queue;

	ifs.close();

	return 0;
}

template <class T>
void Queue<T>::clear()
{
	//TODO
		Node<T> *pDlt;
		while (frontPtr)
		{
			pDlt = frontPtr;
			frontPtr = frontPtr->link;
			delete pDlt;
		}
		rearPtr = NULL;
		count = 0;
}

template <class T>
bool Queue<T>::isEmpty()
{
	//TODO
	if (frontPtr)
		return false;
	else
		return true;
}

template <class T>
int Queue<T>::size()
{
	//TODO
	return count;
}

template <class T>
T &Queue<T>::front()
{
	//TODO
	if (frontPtr)
	{
		return frontPtr->data;
	}
	else
		throw "Empty queue!";
}

template <class T>
T &Queue<T>::rear()
{
	//TODO
	if (rearPtr)
	{
		return rearPtr->data;
	}
	else
		throw "Empty queue!";
}

template <class T>
void Queue<T>::enQueue(const T &val)
{
	//TODO
	Node<T> *pNew = new Node<T>(val);
	if (rearPtr)
	{
		rearPtr->link=pNew;
		rearPtr = pNew;
	}
	else
	{
		frontPtr = rearPtr = pNew;
	}
	count += 1;
}

template <class T>
int Queue<T>::deQueue(T &valOut)
{
	//TODO
	if (rearPtr)
	{
		if (rearPtr == frontPtr)
		{
			valOut = rearPtr->data;
			rearPtr=frontPtr=NULL;
		}
		else
		{
			Node<T> *pDlt=frontPtr;
			valOut = frontPtr->data;
			frontPtr=frontPtr->link;
		}
		count -= 1;
		return 1;
	}
	else
		return 0;
}

template <class T>
void Queue<T>::print2Console()
{
	Node<T> *p = frontPtr;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->link;
	}
}