#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

bool isDuckNumber(int n)
{
    if (n <= 0)
        return false;
    while (n > 0)
    {
        if (n % 10 == 0)
            return true;
        else
        {
            n /= 10;
        }
    }
    return false;
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

    cout << isDuckNumber(n);
    return 0;
}