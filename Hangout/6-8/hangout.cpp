#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include <iostream>
using namespace std;
template<typename E>
struct Node {
    E data;
    Node *next;
};
template<typename E>
class List {
public:
    Node<E> *head;
    List() {
        this->head=NULL;
    };
    void add(E value) {
        Node<E> *pNew;
        pNew->data=value;
        pNew->next=NULL;
        if (this->head==NULL)
            this->head=pNew;
        else {
            Node<E> *pCur=head;
            while (!pCur) {
                pCur=pCur->next;
            }
            pCur=pNew;
        }
    }


};
template<typename E>
int count(List<E> &L, E K) {
    Node<E> *pCur=L.head;
    int dem;
    while (!pCur) {
        if (pCur->data==K)
            dem+=1;
    }
    return dem;
}
int main() {
    List<int> L;
    L.add(1);
    L.add(3);
    L.add(2);
    L.add(4);
    L.add(3);
    cout<<count(L, 3);
}