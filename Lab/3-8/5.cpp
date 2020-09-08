#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#include<time.h>
#define FILENAME "01.005_sol.cpp"
using namespace std;

/* Your code MUST NOT contain any words in the following list:
{"include", "while", "for", "goto"} even in the comments */

//----------------------------------------------
// Begin implementation
//----------------------------------------------

/// Student implement the recursive function here
int lengthOfLonggestCommonSubstring(const char *x, const char *y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (x[m - 1] == y[n - 1])
        return 1+lengthOfLonggestCommonSubstring(x, y, m - 1, n - 1);
    else
        if (lengthOfLonggestCommonSubstring(x, y, m - 1, n) > lengthOfLonggestCommonSubstring(x, y, m, n - 1))
            return lengthOfLonggestCommonSubstring(x, y, m - 1, n);
        else lengthOfLonggestCommonSubstring(x, y, m, n - 1);
}

bool codeCheck()
{
    const char *forbiddenKeyword[] ={ "include", "while", "for", "goto" };
    fstream ifs;
    ifs.open("main.cpp", ios::in);
    if (ifs.fail())
        ifs.open(FILENAME, ios::in);
    if (ifs.fail())
        return true;
    ifs.seekg(0, ifs.end);
    int fileSize = ifs.tellg();
    ifs.seekg(0, ifs.beg);
    char *fileContent = new char[fileSize];
    ifs.read(fileContent, fileSize);
    ifs.close();
    *strstr(fileContent, "bool codeCheck() {") = '\0';
    char *todoSegment = strstr(fileContent, "// Begin implementation");
    int numberOfForbiddenKeyword = sizeof(forbiddenKeyword) / sizeof(const char *);
    for (int i = 0; i < numberOfForbiddenKeyword; i++)
    {
        if (strstr(todoSegment, forbiddenKeyword[i]))
            return false;
    }
    delete[] fileContent;
    return true;
}

int main(int argc, char **argv)
{
    clock_t begin, end;
    begin=clock();
    if (codeCheck() == false)
    {
        cout << "Forbidden-keyword rule violation." << endl;
        return -1;
    }

    ifstream ifs;
    ifs.open(argv[1], ifstream::in);

    string x;
    getline(ifs, x);

    string y;
    getline(ifs, y);

    ifs.close();
    x="tiencot";
    y="ncocotiencon";
    cout << lengthOfLonggestCommonSubstring(x.c_str(), y.c_str(), x.length(), y.length());
    end=clock();
    cout<<"\nTime = "<<float(end-begin)/CLOCKS_PER_SEC;
    return 0;
}