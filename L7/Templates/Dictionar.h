#pragma once
#include<iostream>
using namespace std;
#include <string.h>
template<class T, class U>

class Dictionar
{
public:
    Dictionar();
    ~Dictionar();
    U& operator[](T t);
    int GetCapacity();
    int GetSize();
    void Print();
private:
    int capacity;
    int size;
    T* key;
    U* value;
};
template<class T, class U>
int Dictionar<T,U>::GetCapacity() {

    return capacity;
}

template<class T, class U>
int Dictionar<T, U>::GetSize() {

    return size;
}

template<class T, class U>
void Dictionar<T, U>::Print() {
    for (int i = 0; i < size; ++i)
        cout << '(' << key[i] << ':' << value[i] << ')' << "\n";

    cout << '\n';
}
template<class T, class U>
Dictionar<T, U>::Dictionar()
{
    capacity = 10;
    size = 0;
    key =  new T[capacity];
    value = new U[capacity];
    memset(key, 0, 10 * sizeof T);
    memset(value, 0, 10 * sizeof U);
    
}

template<class T, class U>
Dictionar<T, U>::~Dictionar()
{
    delete[] key;
    delete[] value;
}

template<class T, class U>
U& Dictionar<T, U>::operator[](T t) {
    for (int i = 0; i < size; i++) {
        if (key[i] == t) {
            return value[i];
        }
    }
    if (capacity == size) {
        capacity *= 2;
        T* tempkey = new T[capacity];
        U* tempvalue = new U[capacity];
        memset(tempkey, 0, capacity * sizeof T);
        memset(tempvalue, 0, capacity * sizeof U);
        memcpy(tempkey, key, size * sizeof T);
        memcpy(tempvalue, value,  size * sizeof U);
        delete[] key;
        delete[] value;
        key = tempkey;
        value = tempvalue;
    }
    
    key[size++] = t;
    //value[size-1] = 0;

    return value[size-1];
}

