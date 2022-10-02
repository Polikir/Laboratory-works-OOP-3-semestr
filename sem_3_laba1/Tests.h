
#ifndef SEM_3_LABA1_TESTS_H
#define SEM_3_LABA1_TESTS_H

#include "DynamicArray.h"
#include "LinkedList.h"
#include "ArraySequence.h"
#include "LinkedListSequence.h"
#include "Complex.h"
#include "SortFuncctions.h"
#include <iostream>
#include <cassert>
#pragma once
using namespace std;

int arr[] = {1, 2, 3, 4};
int *pointer = arr;
float arri[] = {1.0,2.1,3.2,4.3,5.4,6.5,7.6,8.7,9.8};
float arrd[] = {9.8,8.7,7.6,6.5,5.4,4.3,3.2,2.1,1.0};
float *pointerfi = arri;
float *pointerfd = arrd;
float arrr[] = {2.1,1.0,3.2,4.3,6.5,5.4,7.6,8.7,9.8};
float *pointerfr = arrr;


void Test()
{
    DynamicArray<int> darray = DynamicArray<int>();
    assert(darray.GetSize() == 0);

    DynamicArray<int> darray1 = DynamicArray<int>(6);
    assert(darray1.GetSize() == 6);

    DynamicArray<int> darray2 = DynamicArray<int>(pointer, 4);
    assert(darray2.Get(0) == 1);

    DynamicArray<int> darrayc = DynamicArray<int>(darray2);
    assert(darrayc.GetSize() ==  darray2.GetSize());
    assert(darrayc.Get(0) ==  darray2.Get(0));

    assert(darray2.Get(1) ==  2);

    darray2.Set(0, 12);
    assert(darray2.Get(0)==12);

    darray2.Resize(2);
    assert(darray2.GetSize() ==  2);

    LinkedList<int> listn = LinkedList<int>();
    assert(listn.GetLength() == 0);

    LinkedList<int> list = LinkedList<int>(pointer, 4);
    assert(list.GetLength() == 4);
    assert(list.Get(0) == 1);

    LinkedList<int> list1 = LinkedList<int>(list);
    assert(list.GetLength() == list1.GetLength());
    assert(list.Get(0) == list1.Get(0));

    assert(list.GetFirst() ==  1);
    assert(list.GetLast() ==  4);


    auto* lists = list.GetSublist(1,3);
    assert(lists->GetLength() == 3);
    assert(lists->GetFirst() ==  2);
    assert(lists->GetLast() == 4);


    list1.Append(12);
    assert(list1.Get(4) == 12);

    list1.Prepend(12);
    assert(list1.Get(0)== 12);

    list1.InsertAt(12, 2);
    assert(list1.Get(2) ==  12);


    LinkedList<int>* listc = new LinkedList<int>();
    listc = list.Concat(&list);
    assert(listc->GetLength() == 8);

    DynamicArray<int> array = DynamicArray<int>(pointer, 4);
    ArraySequence<int> seq = ArraySequence<int>(&array);

    assert(seq.GetFirst() == 1);
    assert(seq.GetLast() == 4);

    ArraySequence<int> *seq1 = new ArraySequence<int>();
    seq1 = seq.GetSubSequence(1, 2);
    assert(seq1->GetFirst() ==  2);
    assert(seq1->GetLast() == 3);

    seq1->Append(12);
    assert(seq1->GetLast() ==  12);

    seq1->Prepend(12);
    assert(seq1->Get(0) ==  12);

    seq1->InsertAt(25, 1);
    assert(seq1->Get(1) ==  25);

    ArraySequence<int> *conseq = new ArraySequence<int>();
    conseq = seq.Concat(&seq);
    assert(conseq->GetSize() == 8);

    LinkedList<int> ll = LinkedList<int>(pointer, 4);
    ListSequence<int> lseq = ListSequence<int>(&ll);
    assert(lseq.GetSize() == 4);
    assert(lseq.GetFirst() ==  1);
    assert(lseq.GetLast() == 4);

    ListSequence<int> *lseq1 = new ListSequence<int>();
    lseq1 = lseq.GetSubSequence(1, 2);
    assert(lseq1->GetFirst() == 2);
    assert(lseq1->GetLast() == 3);


    lseq1->Append(25);
    lseq1->Prepend(24);
    assert(lseq1->GetFirst()==24);
    assert(lseq1->GetLast() == 25);

    lseq1->InsertAt(20,1);
    assert(lseq1->Get(1)==20);

    delete lseq1;
    lseq1 = new ListSequence<int>();
    lseq1 = lseq.Concat(&lseq);
    assert(lseq1->GetSize() == 8);

    complex c0 = complex(1,2);
    complex c1 = complex(2,1);
    complex c2 = complex(3,3);
    complex c3 = complex(-4,-2);

    complex arr_comi[] = {c3,c0,c1,c2};
    complex *com_pointeri = arr_comi;

    complex arr_comd[] = {c2,c1,c0,c3};
    complex *com_pointerd = arr_comd;

    complex arr_comr[] = {c1,c2,c0,c3};
    complex *com_pointerr = arr_comr;

    ArraySequence<float>*  sarri = new ArraySequence<float>(pointerfi,9);
    ArraySequence<float>*  sarrd = new ArraySequence<float>(pointerfd,9);
    ArraySequence<float>*  sarrr = new ArraySequence<float>(pointerfr,9);
    ArraySequence<float>*  sarric = new ArraySequence<float>(pointerfi,9);

    sortMerge(sarri,0,8);
    sortMerge(sarrd,0,8);
    sortMerge(sarrr,0,8);
    for (int i=0;i<9;i++)
    {
        assert(sarri->Get(i) == sarric->Get(i));
        assert(sarrd->Get(i) == sarric->Get(i));
        assert(sarrr->Get(i) == sarric->Get(i));
    }

    sarri = new ArraySequence<float>(pointerfi,9);
    sarrd = new ArraySequence<float>(pointerfd,9);
    sarrr = new ArraySequence<float>(pointerfr,9);
    sarric = new ArraySequence<float>(pointerfi,9);

    sortShell(sarri,9);
    sortShell(sarrd,9);
    sortShell(sarrr,9);
    for (int i=0;i<9;i++)
    {
        assert(sarri->Get(i) == sarric->Get(i));
        assert(sarrd->Get(i) == sarric->Get(i));
        assert(sarrr->Get(i) == sarric->Get(i));
    }

    ArraySequence<complex>*  sarriq = new ArraySequence<complex>(com_pointeri,4);
    ArraySequence<complex>*  sarrdq = new ArraySequence<complex>(com_pointeri,4);
    ArraySequence<complex>*  sarrrq = new ArraySequence<complex>(com_pointeri,4);
    ArraySequence<complex>*  sarricq = new ArraySequence<complex>(com_pointeri,4);

    sortMerge(sarriq,0,3);
    sortMerge(sarrdq,0,3);
    sortMerge(sarrrq,0,3);
    for (int i=0;i<4;i++)
    {
        assert(sarriq->Get(i) == sarricq->Get(i));
        assert(sarrdq->Get(i) == sarricq->Get(i));
        assert(sarrrq->Get(i) == sarricq->Get(i));
    }

    sarriq = new ArraySequence<complex>(com_pointeri,4);
    sarrdq = new ArraySequence<complex>(com_pointerd,4);
    sarrrq = new ArraySequence<complex>(com_pointerr,4);
    sarricq = new ArraySequence<complex>(com_pointeri,4);

    sortShell(sarriq,4);
    sortShell(sarrdq,4);
    sortShell(sarrrq,4);
    for (int i=0;i<4;i++)
    {
        assert(sarriq->Get(i) == sarricq->Get(i));
        assert(sarrdq->Get(i) == sarricq->Get(i));
        assert(sarrrq->Get(i) == sarricq->Get(i));
    }
}


#endif //SEM_3_LABA1_TESTS_H
