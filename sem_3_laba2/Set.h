
#ifndef SEM_3_LABA2_SET_H
#define SEM_3_LABA2_SET_H


#include "BinaryTree.h"
#include "ArraySequence.h"
#include "ISet.h"
#include <iostream>
#include <vector>

using namespace std;

template<class T>
class Set: public ISet<T>{
private:
    BinaryTree<T>* tree;
public:
    BinaryTree<T>* GetTree(){
        return tree;
    }
    Set() {
        tree = new BinaryTree<T>();
    };
    Set(BinaryTree<T>* newTree){
        tree = newTree;
    }
    Set(Set<T>* set){
        tree = BinaryTree<T>(set->tree);
    }
    bool Contains(T* value) override{
        return tree->SearchItem(tree->GetRoot(),value);
    }

    void Add(T* value) override {
        if (this->Contains(value) == false)
        {
            this->tree->Add(value);
        }
    }
    void Delete(T* value) override {
        tree->DeleteFromTree(tree,value);
    }

    ISet<T>* Intersection(ISet<T>& set) override{
        auto result = new Set<T>();

        T* qt;
        ArraySequence<T>* tmp;
        tmp = new ArraySequence<T>();
        BinaryTree<T>::ToArray(((Set<T> *)(&set))->GetTree()->GetRoot(),tmp);

        for (int i = 0;i<tmp->GetSize();i++)
        {
            *qt = tmp->Get(i);
            if(this->Contains(qt))
            {
                result->Add(qt);
            }
            qt = new int();
        }
        return result;
    }
    Set<T>* operator&(Set<T> set){
        return (Set<T>*)Intersection(set);
    }

    bool IsEqual(const ISet<T> &set) override{
        T* qt;
        ArraySequence<T>* array;
        ArraySequence<T>* myArray;
        array = new ArraySequence<T>();
        myArray = new ArraySequence<T>();
        BinaryTree<T>::ToArray(((Set<T> *)(&set))->GetTree()->GetRoot(),array);
        BinaryTree<T>::ToArray(this->GetTree()->GetRoot(),myArray);

        if (array->GetSize()!=myArray->GetSize())
        {
            return false;
        }
        for (int i=0;i<array->GetSize();i++)
        {
            *qt = array->Get(i);
            if (this->Contains(qt)==false)
            {
                return false;
            }

        }
        return true;
    }
    bool operator==(Set<T> set){
        return IsEqual(set);
    }

    ISet<T>* Union(ISet<T>& set) override{
        auto result = new Set<T>();

        T* qt;
        ArraySequence<T>* tmp1;
        ArraySequence<T>* tmp2;
        tmp1 = new ArraySequence<T>();
        tmp2 = new ArraySequence<T>();
        BinaryTree<T>::ToArray(this->GetTree()->GetRoot(),tmp1);
        BinaryTree<T>::ToArray(((Set<T> *)(&set))->GetTree()->GetRoot(),tmp2);
        for (int i=0;i<tmp1->GetSize();i++)
        {   *qt = tmp1->Get(i);
            result->Add(qt);
            qt = new int();
        }
        for (int i=0;i<tmp2->GetSize();i++)
        {   *qt = tmp2->Get(i);
            result->Add(qt);
            qt = new int();
        }
        return result;
    }
    Set<T>* operator|(Set<T> set){
        return (Set<T>*)Union(set);
    }

    ISet<T>* Subtraction(ISet<T>& set) override{
        auto result = new Set<T>();

        T* qt;
        ArraySequence<T>* tmp;
        tmp = new ArraySequence<T>();
        BinaryTree<T>::ToArray(((Set<T> *)(&set))->GetTree()->GetRoot(),tmp);

        for (int i = 0;i<tmp->GetSize();i++)
        {
            *qt = tmp->Get(i);
            if(this->Contains(qt)==false)
            {
                result->Add(qt);
            }
            qt = new int();
        }
        return result;
    }
    Set<T>* operator-(Set<T> set){
        return (Set<T>*)Subtraction(set);
    }

    int GetCount() override
    {
        return this->GetTree()->GetSize();
    }

};





#endif //SEM_3_LABA2_SET_H
