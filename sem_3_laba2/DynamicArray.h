
#ifndef SEM_3_LABA2_DYNAMICARRAY_H
#define SEM_3_LABA2_DYNAMICARRAY_H

#include <iostream>

using namespace std;

#include <stdexcept>
#pragma once

template <typename T>  class DynamicArray {

private:
    T* data;
    int size;

public:

    DynamicArray();
    DynamicArray(int size);
    DynamicArray(T* items, int size);
    DynamicArray(const DynamicArray<T>& array);


    T Get(int index) const;
    int GetSize() const;


    void Set(int index, T value);
    void Resize(int size);

    ~DynamicArray() = default;
};


template<typename T> DynamicArray<T>::DynamicArray(): size(0) {
    this->size = 0;
}

template<typename T> DynamicArray<T>::DynamicArray(int size) : size(size){
    if (size<0) {
        throw length_error("Negative size!");
    }
    this->size = size;
    this->data = new T[this->size];


}

template<typename T> DynamicArray<T>::DynamicArray(T* items, int size) : DynamicArray(size) {
    if (size<0) {
        throw length_error("Negative size!");
    }
    this->size =size;
    for (int i = 0; i < size; i++) {
        this->data[i] = items[i];
    }


}

template<typename T> DynamicArray<T>::DynamicArray(const DynamicArray<T> &array) : DynamicArray(array.size) {

    this->size = size;
    for (int i = 0; i < array.size; i++)
        this->data[i] = array.data[i];


}



template<typename T> T DynamicArray<T>::Get(int index) const {

    if (index < 0 || index >= this->size) {
        throw out_of_range("Index out of range!");
    }
    return this->data[index];
}

template<typename T> int DynamicArray<T>::GetSize() const {
    return this->size;
}



template<typename T> void DynamicArray<T>::Set(int index, T value) {
    if (index<0 || index >=this->size) {
        throw out_of_range("Index out of range!");
    }
    this->data[index] = value;


}

template<typename T> void DynamicArray<T>::Resize(int size) {
    if (size < 0) {
        throw length_error("Negative size!");
    }
    T* newData = new T[size];
    for (int i = 0; i < (this->size > size ? size : this->size); i++) {
        newData[i] = data[i];
    }
    delete[] data;
    this->data = newData;
    this->size = size;

}



#endif //SEM_3_LABA2_DYNAMICARRAY_H
