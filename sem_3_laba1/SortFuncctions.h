
#ifndef SEM_3_LABA1_SORTFUNCCTIONS_H
#define SEM_3_LABA1_SORTFUNCCTIONS_H
#include <iostream>
using namespace std;




template<typename T>
void sortMerge(Sequence<T> *a, int l, int r)
{
    if (l == r) return;
    int mid = (l + r) / 2;

    sortMerge(a, l, mid);
    sortMerge(a, mid + 1, r);

    int i = l;
    int j = mid + 1;

    auto* tmp = new ArraySequence<T>(r+1);
    for (int step = 0; step < r - l + 1; step++)
    {

        if ((j > r) || ((i <= mid) && (a->Get(i) < a->Get(j))))
        {
            tmp->Set(step,a->Get(i));
            i++;
        }
        else
        {
            tmp->Set(step,a->Get(j));
            j++;
        }
    }

    for (int step = 0; step < r - l + 1; step++)
        a->Set(l + step,tmp->Get(step));
}

template<typename T>
void sortShell(Sequence<T> *a, int size)
{
    int increment = size/2;
    while (increment > 0)
    {
        for (int i = 0; i < size; i++)
        {
            int j = i;
            T temp = a->Get(i);
            while ((j >= increment) && (a->Get(j - increment) > temp))
            {
                a->Set(j,a->Get(j - increment));
                j = j - increment;
            }
            a->Set(j,temp);
        }
        if (increment > 1)
            increment = increment / 2;
        else if (increment == 1)
            break;
    }
}


#endif //SEM_3_LABA1_SORTFUNCCTIONS_H
