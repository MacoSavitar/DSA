#include <iostream>
#include <fstream>
#include <math.h>
#include <stack>
using namespace std;

int evaluate(char x, int op1, int op2)
{
	//TODO
	double result;
	switch (x)
	{
	case '+':
		result = op1 + op2;
		break;
	case '-':
		result = op1 - op2;
		break;
	case '*':
		result = op1 * op2;
		break;
	case '/':
		if (op2 == 0)
			throw "Divide by zero";
		else
			result = op1 / op2;
		break;
	case '%':
		if (op2 == 0)
			throw "Divide by zero";
		else
			result = op1 % op2;
		break;
	}
	return result + 48;
}

int evaluatePostfixExpression(string exp)
{
	//TODO
	int out = 0;
	stack<int> S;

	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] >= '0' && exp[i] <= '9')
		{
			S.push((exp[i]));
		}
		else
		{
			int op1 = S.top() - 48;
			S.pop();
			int op2 = S.top() - 48;
			S.pop();
			S.push(evaluate(exp[i], op2, op1));
		}
	}
	return S.top() - 48;
	// while (!S.empty())
	// {
	// 	cout << S.top()-48 << " ";
	// 	S.pop();
	// }
	// return 1;
}

int main(int argc, char *argv[])
{
	ifstream ifs;
	ifs.open("input.txt", ifstream::in);

	string arr;
	getline(ifs, arr);

	try
	{
		cout << evaluatePostfixExpression(arr);
	}
	catch (const char *msg)
	{
		cout << msg;
	}

	ifs.close();

	return 0;
}
