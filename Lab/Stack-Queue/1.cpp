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
    Node()
    {
        this->link = NULL;
    }

    Node(T data)
    {
        this->data = data;
        this->link = NULL;
    }
};

template <class T>
class Stack
{
private:
    Node<T> *head;
    int count;

public:
    Stack()
    {
        head = NULL;
        count = 0;
    }

    ~Stack()
    {
        clear();
    }
    void print2Console();

    // TODO Methods

    /*
		Push an element into the stack
		- Input: the value to push
		- Output: none
	*/
    void push(const T &val);

    /*
		Pop an element from the stack
		- Input: the value to store the top element
		- Output: return 1 if success, otherwise return 0 (the stack is empty)
	*/
    int pop(T &val);

    /*
		Get the top element of the stack
		- Input: none
		- Output: return the reference to top element
		- Exception: throw message "Empty stack!" if stack is empty
	*/
    T &top();

    /*
		Clear all elements of the stack
		- Input: none
		- Output: none
	*/
    void clear();

    /*
		Determine if the stack is empty
		- Input: none
		- Output: return true if empty, otherwise return false.
	*/
    bool isEmpty();
};

int main(int argc, char *argv[])
{
    ifstream ifs;
    ifs.open("input.txt", ifstream::in);

    Stack<int> *stack = new Stack<int>();

    int code, data;
    while (ifs.good())
    {
        ifs >> code;
        switch (code)
        {
        case 0:
            ifs >> data;
            cout << "0 push: ";
            stack->push(data);
            break;
        case 1:
            cout << "1 pop: ";
            if (stack->pop(data))
                cout << data << endl;
            break;
        case 2:
            cout << "2 top: ";
            try
            {
                data = stack->top();
                cout << data << endl;
            }
            catch (const char *msg)
            {
                cout << msg << endl;
            }
            break;
        case 3:
            cout << "3 clear: ";
            stack->clear();
            break;
        case 4:
            cout << "4 isEmpty: ";
            cout << stack->isEmpty() << endl;
            break;
        }

        stack->print2Console();
        cout << endl;
    }
    delete stack;

    ifs.close();

    return 0;
}

template <class T>
void Stack<T>::clear()
{
    //TODO
    Node<T> *pDlt;
    while (head)
    {
        Node<T> *pDlt = head;
        head = head->link;
        delete pDlt;
    }
    count = 0;
}

template <class T>
bool Stack<T>::isEmpty()
{
    //TODO
    if (!head)
    {
        return true;
    }
    else
        return false;
}

template <class T>
void Stack<T>::push(const T &val)
{
    //TODO
    Node<T> *pNew = new Node<T>(val);
    pNew->link = head;
    head = pNew;
    count += 1;
}

template <class T>
int Stack<T>::pop(T &val)
{
    //TODO
    if (head)
    {
        val = head->data;
        Node<T> *p = head;
        head = head->link;
        delete p;
        count -= 1;
        return 1;
    }
    else
        return 0;
}

template <class T>
T &Stack<T>::top()
{
    //TODO
    if (head)
    {
        return head->data;
    }
    else
        throw "Empty stack!";
}

template <class T>
void Stack<T>::print2Console()
{
    Node<T> *p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->link;
    }
}