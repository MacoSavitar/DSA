#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

void printByPattern(int n)
{
    int count = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j != i)
                cout << count << " ";
            else
                cout << count;
                count+=1;
        }
        cout << "\n";
    }
}

int main(int narg, char **argv)
{
    ifstream ifs;
    ifs.open("input.txt", ifstream::in);

    int n;
    string line;

    for (int count = 0; ifs.good() && count < 1; count++)
    {
        getline(ifs, line);
        n = stoi(line);
    }
    ifs.close();

    printByPattern(n);

    return 0;
}