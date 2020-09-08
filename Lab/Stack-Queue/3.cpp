#include <iostream>
#include <fstream>
#include <math.h>
#include <stack>
using namespace std;

bool checkParentheses(const char *arr)
{
	//TODO
	
	stack<char> S;
	for (int i = 0; arr[i]!=NULL; i++)
	{
		if (S.empty() || arr[i] == '(' || arr[i] == '{' || arr[i] == '['){
			S.push(arr[i]);
		}
		else
		{
			switch (arr[i])
			{
			case ')':
				if (S.top() == '(')
					S.pop();
				break;
			case '}':
				if (S.top() == '{')
					S.pop();
				break;
			case ']':
				if (S.top() == '[')
					S.pop();
				break;
			}
		}
	}
	// cout<<"len: ";
	// cout<<sizeof(arr)<<endl;
	// while(!S.empty()){
	// 	cout<<S.top()<<endl;
	// 	S.pop();
	// }
	if (S.empty())
		return true;
	else
		return false;
}

int main(int argc, char *argv[])
{
	ifstream ifs;
	ifs.open("input.txt", ifstream::in);

	string arr;
	getline(ifs, arr);

	cout << checkParentheses(arr.c_str());

	ifs.close();

	return 0;
}
