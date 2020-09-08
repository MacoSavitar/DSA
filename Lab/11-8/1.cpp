#include <iostream>
#include <fstream>
#include <math.h>
#include <string.h>
using namespace std;

void printInteger(int element) {
    cout << element << " ";
}

template<class T>
class AList {
private:
    T* data;
    int size;
    int capacity;

public:
    AList() {
        cout << "Default constructor called!" << endl;
        this->size=0;
        this->capacity=0;
        this->data=NULL;
    }

    AList(T* data, int size) {
        cout << "User-define constructor called!" << endl;
        this->size=size;
        this->capacity=size;
        this->data=data;
    }

    void print(void (*printElement)(T element)) {
        for (int i = 0; i < size; i++) {
            printElement(data[i]);
        }
    }

    ~AList() {
        cout << "Destructor AList called!" << endl;
        delete data;
    }
};

int main(int argc, char* argv[]) {
    ifstream ifs;
    ifs.open("input.txt", ifstream::in);

    string line;

    getline(ifs, line);
    int code = stoi(line);


    if (code == 1) {
        AList<int>* intList = new AList<int>();
        intList->print(printInteger);
        delete intList;
    }
    else if (code == 2) {
        getline(ifs, line);
        int size = stoi(line);

        int* data = new int[size];
        for (int count = 0; ifs.good() && count < size; count++) {
            getline(ifs, line);
            data[count] = stoi(line);
        }

        AList<int>* intList = new AList<int>(data, size);
        intList->print(printInteger);
        delete intList;
    }

    ifs.close();

    return 0;
}
