#include <iostream>
#include <fstream>
#include <math.h>
#include <string.h>
using namespace std;

void printInteger(int element) {
    cout << element << " ";
}

int compareInteger(int a, int b) {
    //TODO
    if (a==b)
        return 1;
    return 0;
}

template<class T>
class AList {
private:
    T* storage;
    int size;
    int capacity;

protected:
    void setCapacity(int capacity);
    void ensureCapacity(int minCapacity);
    void pack();
    void trim();
    void rangeCheck(int index);

    // HELPER Methods: You can implement additionally if necessary
    //TODO
public:
    AList() {
        this->storage = NULL;
        this->size = 0;
        this->capacity = 0;
    }

    AList(T* storage, int size) {
        this->size = this->capacity = size;
        this->storage = new T[size];

        for (int i = 0; i < size; i++) {
            this->storage[i] = storage[i];
        }
    }

    ~AList() {
        if (storage != NULL)
            delete[] storage;
    }

    void clear();
    void set(int index, T value);
    int get(int index);
    int getSize();
    void removeAt(int index);
    void insertAt(int index, T value);
    void print(void (*printElement)(T element));

    // TODO Methods
    void insertSorted(T value, int (*compare)(T a, T b));
};

int main(int argc, char* argv[]) {
    ifstream ifs;
    ifs.open("input.txt", ifstream::in);

    string line;

    getline(ifs, line);
    int size = stoi(line);

    AList<int>* intList = new AList<int>();

    for (int i = 0; i < size && ifs.good(); i++) {
        getline(ifs, line);
        intList->insertSorted(stoi(line), compareInteger);
        intList->print(printInteger); cout << endl;
    }

    ifs.close();

    return 0;
}

// HELPER methods implementation
//TODO
// TODO Methods implementation
template <class T>
void AList<T>::insertSorted(T value, int (*compare)(T a, T b)) {
    //TODO
    /*
    if (size==0) {
        insertAt(0, value);
    }
    else {
        bool check=true;
        for (int i=0;i<size;i++) {
            if (compareInteger(value, storage[i])==1)
                check=false;
        }
        if (check)
            if (size==1) {
                if (value<storage[0])
                    insertAt(0, value);
                else insertAt(1, value);
            }
            else {
                if (value<storage[0]) {
                    insertAt(0, value);
                }
                if (value>storage[size-1])
                    insertAt(size, value);
                for (int i=1;i<size;i++)
                    if (value>storage[i-1]&&value<storage[i])
                        insertAt(i, value);
            }


    }
    */
    if (size ==0) {
        insertAt(0, value);
    }
    else {
        bool check=true;
        for (int i=0;i<size;i++) {
            if (value==storage[i]) {
                check=false;
                break;
            }
        }
        if (check) {
            if (size==1) {
                if (value<storage[0])
                    insertAt(0, value);
                else
                    insertAt(1, value);
            }
            else {
                if (value>storage[size-1])
                    insertAt(size, value);
                else
                    for (int i=0;i<size;i++) {
                        if (value>storage[i] && value<storage[i+1]) {
                            insertAt(i+1, value);
                        }
                    }
            }
        }

    }

}


template<class T>
void AList<T>::setCapacity(int capacity) {
    int *newStorage = new int[capacity];
    memcpy(newStorage, storage, sizeof(T) * size);
    this->capacity = capacity;
    delete[] storage;
    storage = newStorage;
}

template<class T>
void AList<T>::ensureCapacity(int minCapacity) {
    if (minCapacity > capacity) {
        int newCapacity = (capacity * 3) / 2 + 1;
        if (newCapacity < minCapacity)
            newCapacity = minCapacity;
        setCapacity(newCapacity);
    }
}

template<class T>
void AList<T>::pack() {
    if (size <= capacity / 2) {
        int newCapacity = (size * 3) / 2 + 1;
        setCapacity(newCapacity);
    }
}

template<class T>
void AList<T>::trim() {
    int newCapacity = size;
    setCapacity(newCapacity);
}

template<class T>
void AList<T>::rangeCheck(int index) {
    if (index < 0 || index >= size)
        throw "Index out of bounds!";
}

template<class T>
void AList<T>::clear() {
    if (storage != NULL)
        delete[] storage;
    size = 0;
    capacity = 10;
    storage = new int[capacity];
}

template<class T>
void AList<T>::set(int index, T value) {
    rangeCheck(index);
    storage[index] = value;
}

template<class T>
int AList<T>::get(int index) {
    rangeCheck(index);
    return storage[index];
}

template<class T>
int AList<T>::getSize() {
    return this->size;
}

template<class T>
void AList<T>::insertAt(int index, T value) {
    if (index < 0 || index > size) {
        throw "Index out of bounds!";
    }
    ensureCapacity(size+1);
    memmove(storage + index + 1, storage + index, sizeof(T) * (size-index));
    storage[index] = value;
    size++;
}

template<class T>
void AList<T>::removeAt(int index) {
    rangeCheck(index);
    memmove(storage + index, storage + index + 1, sizeof(T) * (size - index - 1));
    size--;
    pack();
}

template<class T>
void AList<T>::print(void (*printElement)(T element)) {
    for (int i = 0; i < size; i++) {
        printElement(storage[i]);
    }
}