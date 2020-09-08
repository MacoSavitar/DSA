#include <iostream>
using namespace std;
// class Test
// {
//     public:
//          int x;
//     Test() { x = 5; }
// };
// int main()
// {
//     Test *t = new Test();
//     cout << t->x;
// }
int fun(int n, int *f_p)
{
    int t, f;
    if (n <= 1)
    {
        *f_p = 1;
        return 1;
    }
    t = fun(n - 1, f_p);
    f = t + *f_p;
    *f_p = t;
    cout<<f<<" "<<*f_p<<"\n";
    return f;
}
int main(){
    int x=15;
    cout<<fun(5,&x);
}