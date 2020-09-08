#include <iostream>
#include <fstream>
#include <math.h>
#include <string.h>
using namespace std;

void printInteger(int element) {
    cout << element << " ";
}

bool isIntegerIdentical(int a, int b) {
    //TODO
    if (a==b)
        return true;
    return false;
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

public:
    AList() {
        //TODO
        this->size=0;
        this->capacity=0;
        this->storage=NULL;
    }

    AList(T* storage, int size) {
        //TODO
        this->size=size;
        this->capacity=size;
        this->storage=storage;
    }

    ~AList() {
        //TODO
        delete storage;
    }

    void clear();
    void set(int index, T value);
    T& get(int index);
    int getSize();
    void removeAt(int index);
    void insertAt(int index, T value);
    void print(void (*printElement)(T element));

    // TODO Methods
    int getIndexOf(T value, bool (*compare)(T a, T b));
};

int main(int argc, char* argv[]) {
    ifstream ifs;
    ifs.open("input.txt", ifstream::in);

    string line;

    getline(ifs, line);
    int size = stoi(line);

    int* data = new int[size];
    for (int i = 0; i < size && ifs.good(); i++) {
        getline(ifs, line);
        data[i] = stoi(line);
    }

    getline(ifs, line);
    int value = stoi(line);

    AList<int>* intList = new AList<int>(data, size);
    cout << intList->getIndexOf(value, isIntegerIdentical);

    ifs.close();

    return 0;
}

template <class T>
int AList<T>::getIndexOf(T value, bool (*compare)(T a, T b)) {
    //TODO
    for (int i=0;i<size;i++) {
        if (isIntegerIdentical(storage[i], value))
            return i;
    }
    return -1;
}

template<class T>
void AList<T>::setCapacity(int capacity) {
    T *newStorage = new T[capacity];
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
    storage = new T[capacity];
}

template<class T>
void AList<T>::set(int index, T value) {
    rangeCheck(index);
    storage[index] = value;
}

template<class T>
T& AList<T>::get(int index) {
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