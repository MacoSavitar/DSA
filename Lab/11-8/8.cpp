#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <math.h>
using namespace std;

class Node
{
public:
	double coeff;
	int exp;
	Node *link;

	Node(double coeff, int exp)
	{
		this->coeff = coeff;
		this->exp = exp;
		this->link = NULL;
	}
};

class Polynomial
{
	Node *head;

protected:
	int insertNode(Node *pPre, double coeff, int exp);
	void deleteNode(Node *pPre, Node *pLoc);

public:
	Polynomial();
	Polynomial(const Polynomial &);
	~Polynomial();
	void clear();
	const Polynomial &operator=(const Polynomial &);
	void check();

	// TODO methods
	void fillter()
	{
		Node *pCur = head, *pPre = head;
		while (pCur)
		{
			if (pCur->coeff == 0)
			{
				pPre->link = pCur->link;
				pCur = pPre->link;
			}
			else
			{
				pPre = pCur;
				pCur = pCur->link;
			}
		}
	}
	void insertTerm(double coeff, int exp);
	void print();
	Polynomial operator+(const Polynomial &b);
};

int main(int argc, char *argv[])
{
	ifstream ifs;
	ifs.open("input.txt", ifstream::in);

	Polynomial *p1 = new Polynomial();
	Polynomial *p2 = new Polynomial();
	Polynomial *result = new Polynomial();

	double coeff;
	int exp;
	int numTerms;
	ifs >> numTerms;
	for (int i = 0; i < numTerms && ifs.good(); i++)
	{
		ifs >> coeff >> exp;
		p1->insertTerm(coeff, exp);
	}
	p1->print();
	cout << endl;

	ifs >> numTerms;
	for (int i = 0; i < numTerms && ifs.good(); i++)
	{
		ifs >> coeff >> exp;
		p2->insertTerm(coeff, exp);
	}
	p2->print();
	cout << endl;

	*result = *p1 + *p2;
	result->print();
	cout << endl;

	delete p1;
	delete p2;
	delete result;
	ifs.close();

	return 0;
}

void Polynomial::insertTerm(double coeff, int exp)
{
	//TODO
	Node *pNew = new Node(coeff, exp);
	bool isExist = false;
	if (head == NULL)
	{
		head = pNew;
	}
	else
	{
		Node *p = head;
		while (p)
		{
			if (exp == p->exp)
			{
				p->coeff += coeff;
				isExist = true;
			}
			p = p->link;
		}
		if (isExist == false)
		{
			p = head;
			if (p && p->link == NULL)
				if (exp > p->exp)
				{
					pNew->link = p;
					head = pNew;
				}
				else
				{
					head->link = pNew;
				}
			while (p && p->link)
			{
				if (exp > head->exp)
				{
					pNew->link = head;
					head = pNew;
					break;
				}
				if (exp < p->exp && exp > p->link->exp)
				{
					pNew->link = p->link;
					p->link = pNew;
					break;
				}
				p = p->link;
			}
			if (exp < p->exp)
			{
				p->link = pNew;
			}
		}
	}
	//fillter();
	Node *pCur = head, *pPre = head;
	while (pCur)
	{
		if (pCur->coeff == 0)
			if (pCur == head)
			{
				head = head->link;
				pCur = pCur->link;
				pPre = pCur;
			}
			else
			{
				pPre->link = pCur->link;
				pCur = pPre->link;
			}
		else
		{
			pPre = pCur;
			pCur = pCur->link;
		}
	}
}
void Polynomial::print()
{
	Node *p = head;
	while (p)
	{
		if (p == head)
		{
			switch (p->exp)
			{
			case 0:
				printf("%g", p->coeff);
				break;
			case 1:
				if (p->coeff == 1)
					printf("x");
				else if (p->coeff == -1)
					printf("-x");
				else
					printf("%gx", p->coeff);
				break;
			default:
				if (p->coeff == 1)
					printf("x^%d", p->exp);
				else if (p->coeff == -1)
					printf("-x^%d",p->exp);
				else
					printf("%gx^%d", p->coeff, p->exp);
				break;
			}
		}
		else
		{
			switch (p->exp)
			{
			case 0:
				if (p->coeff < 0)
					printf(" - %g", -(p->coeff));
				else
					printf(" + %g", p->coeff);
				break;
			case 1:
				if (p->coeff == 1)
					printf(" + x");
				else if (p->coeff < 0)
					if (p->coeff == -1)
						printf(" - x");
					else
						printf(" - %gx", -(p->coeff));
				else
					printf(" + %gx", p->coeff);
				break;
			default:
				if (p->coeff < 0)
					if (p->coeff == -1)
						printf(" - x^%d", p->exp);
					else
						printf(" - %gx^%d", -(p->coeff), p->exp);
				else if (p->coeff == 1)
					printf(" + x^%d", p->exp);
				else
					printf(" + %gx^%d", p->coeff, p->exp);
				break;
			}
		}

		p = p->link;
	}
}
Polynomial Polynomial::operator+(const Polynomial &b)
{
	Polynomial *result = new Polynomial();
	result = this;
	Node *pResult = result->head, *p = b.head;
	while (p)
	{
		result->insertTerm(p->coeff, p->exp);
		p=p->link;
	}
	return *result;
}
Polynomial::Polynomial()
{
	this->head = NULL;
}

Polynomial::Polynomial(const Polynomial &a)
{
	Node *p = a.head;
	head = NULL;
	while (p != NULL)
	{
		insertTerm(p->coeff, p->exp);
		p = p->link;
	}
}

const Polynomial &Polynomial::operator=(const Polynomial &a)
{
	if (this != &a)
	{
		clear();
		Node *p = a.head;
		while (p != NULL)
		{
			insertTerm(p->coeff, p->exp);
			p = p->link;
		}
		return (*this);
	}
}

int Polynomial::insertNode(Node *pPre, double coeff, int exp)
{
	Node *pNew = new Node(coeff, exp);
	if (pNew == NULL)
		return 0;
	if (pPre == NULL)
	{
		pNew->link = this->head;
		this->head = pNew;
	}
	else
	{
		pNew->link = pPre->link;
		pPre->link = pNew;
	}
	return 1;
}

void Polynomial::deleteNode(Node *pPre, Node *pLoc)
{
	if (pPre == NULL)
	{
		this->head = pLoc->link;
	}
	else
	{
		pPre->link = pLoc->link;
	}

	delete pLoc;
}

void Polynomial::clear()
{
	Node *temp;
	while (this->head != NULL)
	{
		temp = this->head;
		this->head = this->head->link;
		delete temp;
	}
}

Polynomial::~Polynomial()
{
	this->clear();
}

void Polynomial::check()
{
	Node *temp = this->head;
	while (temp != NULL)
	{
		cout << temp->coeff << " " << temp->exp << endl;
		temp = temp->link;
	}
}