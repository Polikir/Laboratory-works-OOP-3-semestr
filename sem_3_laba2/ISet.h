

#ifndef SEM_3_LABA2_ISET_H
#define SEM_3_LABA2_ISET_H



#include "BinaryTree.h"
template<typename T>
class ISet{
public:
    virtual ISet<T>* Union(ISet<T>& set) = 0;
    virtual ISet<T>* Intersection(ISet<T>& set) = 0;
    virtual bool Contains(T* value) = 0;
    virtual ISet<T>* Subtraction(ISet<T>& set) = 0;
    virtual int GetCount() = 0;

    virtual bool IsEqual(const ISet<T>& set) = 0;
    virtual void Add(T* value) = 0;
    virtual void Delete(T* value) = 0;
};


#endif //SEM_3_LABA2_ISET_H
