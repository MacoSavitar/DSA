#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include <iostream>
using namespace std;
template <typename E> class Link {
public:
    E element;      // Value for this node
    Link *next;        // Pointer to next node in list
    // Constructors
    Link(const E& elemval, Link* nextval =NULL)
    {
        element = elemval;  next = nextval;
    }
    Link(Link* nextval =NULL) {
        next = nextval;
    }
};
template <typename E> class LList {
private:
    Link<E>* head;       // Pointer to list header
    Link<E>* tail;       // Pointer to last element
    Link<E>* curr;       // Access to current element
    int cnt;    	       // Size of list
    void print() {};
    void insertBefore(int v, int k){};
};
template<typename E>
void LList<E>::print() {
    Link<E> *p=head;
    cout<<" ";
    while (p!=NULL) {
        if (p==curr) {
            if(p->next!=NULL)
            cout<<"| "<<p->element<<" ";
            else cout<<"| "<<p->element;
        }
        else {
            if(p->next!=NULL)
            cout<<p->element<<" ";
            else cout<<p->element;
        }
        p=p->next;
    }
}
void IntList::insertBefore(int v, int k) {
    if (size==MAX)
        throw "out_of_range";
    for (int i=0;i<MAX;i++) {
            if (data[i]==k) {
                for (int j=MAX-2;j>=i;j--)
                    data[j+1]=data[j];
                data[i]=v;
                cursor=i;
                size+=1;
                i=MAX;
                return;
            }
        }
    }
}
