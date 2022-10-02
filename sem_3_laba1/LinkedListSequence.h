
#ifndef SEM_3_LABA1_LINKEDLISTSEQUENCE_H
#define SEM_3_LABA1_LINKEDLISTSEQUENCE_H


#include "LinkedList.h"
#pragma once

template <class T>
class ListSequence : public Sequence<T>{

private:
    LinkedList<T>* linked_list;

public:


    ListSequence()  {
        this->linked_list = new LinkedList<T>();
    }
    ListSequence(T* item, int size)  {
        this->linked_list = new LinkedList<T>(item, size);
    }
    ListSequence(LinkedList<T>* list) {
        this->linked_list = list;
    }
    ListSequence(const ListSequence<T>& sequence) {
        this->linked_list = new LinkedList<T>(*sequence.linked_list);
    }

    int GetSize() const override{
        return this->linked_list->GetLength();
    }

    T Get(int index) const override{

        if (index < 0 || index >= this->GetSize()) {
            throw out_of_range("Index out of range!");
        }
        return this->linked_list->Get(index);


    }

    T GetFirst() const override {

        if (this->GetSize()==0) {
            throw out_of_range("List is empty!");
        }
        return this->linked_list->GetFirst();


    }

    T GetLast() const override {

        if (this->GetSize()==0) {
            throw out_of_range("List is empty!");
        }
        return this->linked_list->GetLast();

    }

    ListSequence<T>* GetSubSequence(int start, int end) override {

        if (start<0 || start>=this->GetSize() || end<0 || end >=this->GetSize() || end<start) {
            throw out_of_range("Index out of range!");
        }
        LinkedList<T>* list = new LinkedList<T>();
        list = this->linked_list->GetSublist(start, end);
        ListSequence<T>* listSequence =new ListSequence<T>(list);
        return listSequence;

    }




    void Set(int index, T item) override {

        if ((index<0) || index>this->GetSize()) {
            throw out_of_range("Index out of range!");
        }
        return this->linked_list->Set(index, item);

    }

    void Prepend(T item) override {
        this->linked_list->Prepend(item);
    }

    void Append(T item) override {
        this->linked_list->Append(item);
    }

    void InsertAt(T item, int index) override {

        if ((index<0) || index>this->GetSize()) {
            throw out_of_range("Index out of range!");
        }
        this->linked_list->InsertAt(item, index);

    }

    ListSequence<T>* Concat(Sequence<T>* list) override {
        ListSequence<T>* newlinkedlist = new ListSequence<T>;
        for (int i = 0; i < this->GetSize(); i++) {
            newlinkedlist->Append(this->Get(i));
        }

        for (int i = 0; i < list->GetSize(); i++) {
            newlinkedlist->Append(list->Get(i));

        }
        return newlinkedlist;
    }


    ~ListSequence() = default;
};

#endif //SEM_3_LABA1_LINKEDLISTSEQUENCE_H
