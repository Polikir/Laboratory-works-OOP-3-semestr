

#ifndef SEM_3_LABA2_SEQUENCE_H
#define SEM_3_LABA2_SEQUENCE_H

#pragma once
template <typename T> class Sequence {
public:

    virtual int GetSize() const = 0;
    virtual T Get(int index) const = 0;
    virtual T GetLast() const = 0;
    virtual T GetFirst() const = 0;
    virtual Sequence<T>* GetSubSequence(int start, int end) = 0;


    virtual void Set(int index, T item) = 0;
    virtual Sequence<T>* Concat(Sequence<T>* list) = 0;
    virtual void Append(T item) = 0;
    virtual void Prepend(T item) = 0;
    virtual void InsertAt(T item, int index) = 0;

};


#endif //SEM_3_LABA2_SEQUENCE_H
