#pragma once
#include "ListSequence.h"

int compare(int a, int b) {
    return a>b ? 1 : 0;
}

template<class T>
class ISorter {
public:
    virtual Sequence<T>* Sort(Sequence<T>* data, int (*cmp)(T,T)) = 0;
    virtual ~ISorter() = default;
};

template<class T>
class BubbleSorter : public ISorter<T> {
public:
    Sequence<T>* Sort(Sequence<T>* data, int (*cmp)(T,T)) override;
};

template<class T>
Sequence<T>* BubbleSorter<T>::Sort(Sequence<T> * data, int (*cmp)(T,T) ) {
    Sequence<T>* new_data = data->Clone();
    for (int i = 0; i < new_data->GetSize(); i++) {
        for (int j = new_data->GetSize() - 1; j >= i + 1; j--) {
            if (cmp(new_data->Get(j-1) , new_data->Get(j))) {
                new_data->Swap(j, j - 1);
            }
        }
    }
    return new_data;
}

template<class T>
class QuickSorter : public ISorter<T> {
public:
    Sequence<T>* Sort(Sequence<T>* data, int (*cmp)(T,T)) override;
    void qSort(Sequence<T>* data, int first, int last, int (*cmp)(T,T));
};

template<class T>
Sequence<T>* QuickSorter<T>::Sort(Sequence<T> * data, int (*cmp)(T,T) ) {
    Sequence<T>* new_data = data->Clone();
    qSort(new_data, 0, new_data->GetSize()-1, cmp);
    return new_data;
}

template<class T>
void QuickSorter<T>::qSort(Sequence<T> *data, int first, int last, int (*cmp)(T, T)) {
    int f = first;
    int l = last;
    T pivot = data->Get((f+l)/2);
    while (f <= l) {
        while(cmp(pivot, data->Get(f))) {
            f++;
        }
        while(cmp(data->Get(l), pivot)) {
            l--;
        }
        if (f <= l) {
            data->Swap(f, l);
            f++;
            l--;
        }
    }
    if (first < l) {
        qSort(data, first, l, cmp);
    }
    if (last > f) {
        qSort(data, f, last, cmp);
    }
}


