#include<iostream>
using namespace std;
void fun(char **arr){
    char *t;
    t=(arr+=sizeof(int))[2];
    printf("%s\n",t);
}
int main(){
  char *arr[]={"bat","cat","fat","hat","mat","pat"};
  fun(arr);
  return 0;
}