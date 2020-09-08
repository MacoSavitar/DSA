#include <iostream>
using namespace std;

int fun(int x, int y)
{
    if (x == 0)
        return y;
    return fun(x - 1, x + y);
}
void f(int x)
{
    x++;
    return;
}
void g(int &x)
{
    x++;
    return;
}
// void h(const int &x)
// {
//     x++;
//     return;
// }
// int main()
// {

//     // char str[5]="ABC";
//     // cout<<str[3]<<str[4];
//     // cout<<str;

//     // int a = 1, b = 2, c = 3;
//     // int *arr[3] = { &a, &b, &c };
//     // cout << *arr[(*arr[2])-- - 3];
//     // cout << c;

//     // cout<<fun(3,2);
//     // int count=1;
//     // for (; count <= 5; count++)
//     // {
//     //     int count = 1;
//     //     cout << count << "\n";
//     // }
//     int x = 0;
//     g(x);
//     cout << x;
//     return 0;
// }

