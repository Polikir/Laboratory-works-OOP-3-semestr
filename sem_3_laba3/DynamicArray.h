#pragma once


using namespace std;
#include <stdexcept>
const string NEGATIVE_SIZE = "size is negative";
const string INDEX_OUT_OF_RANGE = "index out of range";
const string ELEMENT_DOESNT_EXIST = "this element doesnt exist";

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

    T operator[](const int index);
    bool operator==(const DynamicArray<T>& arr) const;

    ~DynamicArray() {
        delete[] data;
    };
};


template<typename T> DynamicArray<T>::DynamicArray(): size(0) {
    this->size = 0;
}

template<typename T> DynamicArray<T>::DynamicArray(int size) : size(size){
    if (size<0) {
        throw length_error(NEGATIVE_SIZE);
    }
    this->size = size;
    this->data = new T[this->size];
}

template<typename T> DynamicArray<T>::DynamicArray(T* items, int size) : DynamicArray(size) {
    if (size<0) {
        throw length_error(NEGATIVE_SIZE);
    }
    this->size =size;
    for (int i = 0; i < size; i++) {
        this->data[i] = items[i];
    }
}

template<typename T> DynamicArray<T>::DynamicArray(const DynamicArray<T> &array) : DynamicArray(array.size) {
    if (size > array.size || size<0) {
        throw out_of_range(INDEX_OUT_OF_RANGE);
    }
    this->size = size;
    for (int i = 0; i < array.size; i++)
        this->data[i] = array.data[i];
}

template<typename T> T DynamicArray<T>::Get(int index) const {
    if (index < 0 || index >= this->size) {
        throw out_of_range(INDEX_OUT_OF_RANGE);
    }
    return this->data[index];
}

template<typename T> int DynamicArray<T>::GetSize() const {
    return this->size;
}

template<typename T> void DynamicArray<T>::Set(int index, T value) {
    if (index<0 || index >=this->size) {
        throw out_of_range(INDEX_OUT_OF_RANGE);
    }
    this->data[index] = value;
}

template<typename T> void DynamicArray<T>::Resize(int size) {
    if (size < 0) {
        throw length_error(NEGATIVE_SIZE);
    }
    T* newData = new T[size];
    for (int i = 0; i < (this->size > size ? size : this->size); i++) {
        newData[i] = data[i];
    }
    delete[] data;
    this->data = newData;
    this->size = size;
}

template<typename T> T DynamicArray<T>::operator[](const int index) {
    if (index<0 || index >=this->size) {
        throw out_of_range(INDEX_OUT_OF_RANGE);
    }
    return this->Get(index);
}

template<typename T> bool DynamicArray<T>::operator==(const DynamicArray<T> &arr) const {
    if (this->size != arr.size) {
        return false;
    }
    for (int i = 0; i < this->size; i++) {
        if (this->Get(i) != arr.Get(i)) {
            return false;
        }
    }
    return true;
}