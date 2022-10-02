

#ifndef SEM_3_LABA2_TESTS_H
#define SEM_3_LABA2_TESTS_H

#include "DynamicArray.h"
#include "ArraySequence.h"
#include "BinaryTree.h"
#include "Tree.h"
#include "Set.h"
#include <iostream>
#include <cassert>
#pragma once
using namespace std;


int arr[] = {0,1,2,3,-3,-2,-1};
int *pointer = arr;

int arr_h[] = {0,1,2,3,-3,-2,-1};
int *pointerh = arr_h;
void Test()
{
    int i;
    BinaryTree<int>* tree = new BinaryTree<int>();
    assert(tree->GetRoot() == nullptr);
    for(i=0;i<7;i++)
    {
        tree->Add(&arr[i]);
    }
    assert(*(tree->GetRoot()->Value) == arr[0]);
    assert(*(tree->GetRoot()->Right->Right->Right->Value) == arr[3]);
    assert(*(tree->GetRoot()->Left->Value) == arr[4]);

    assert(*(tree->GetRoot()->Value)==arr[0]);
    tree->DeleteFromTree(tree,&arr[0]);
    assert(*(tree->GetRoot()->Value)==arr[6]);

    tree = new BinaryTree<int>();
    for(i=0;i<7;i++)
    {
        tree->Add(&arr[i]);
    }

    assert(tree->SearchItem(tree->GetRoot(),&arr[4]));

    BinaryTree<int>* tree1 = new BinaryTree<int>();
    tree1->Add(&arr[0]);
    tree1->Add(&arr[1]);
    tree1->Add(&arr[4]);

    assert(tree->SearchTree(tree,tree1));


    tree1 = tree->Sub(tree,&arr[0]);
    assert(*(tree1->GetRoot()->Value) == arr[0]);
    assert(*(tree1->GetRoot()->Right->Value) == arr[1]);

    tree1 = tree->Sub(tree,&arr[1]);
    assert(*(tree1->GetRoot()->Value) == arr[1]);
    assert(*(tree1->GetRoot()->Right->Value) == arr[2]);

    Tree<int>* tre = new Tree<int>(10);
    Tree<int>* tre1 = new Tree<int>(5);
    Tree<int>* tre2 = new Tree<int>(4);
    tre->addChild(tre1);
    tre1 = new Tree<int>(6);
    tre->addChild(tre1);
    tre1->addChild(tre2);
    tre2  = new Tree<int>(1);
    tre->addChild(tre2);


    assert(tre2->get_root()->getValue() == tre->getValue());
    assert(tre1->get_root()->getValue() == tre->getValue());

    assert(tre->getChildren().size()==3);
    assert(tre1->getChildren().size()==1);
    assert(tre2->getChildren().size()==0);


    tre->delete_child(tre1);
    assert(tre->getChildren().size()==3);



    Tree<int>* tre3 = new Tree<int>(21);
    Tree<int>* tre13 = new Tree<int>(22);
    Tree<int>* tre23 = new Tree<int>(23);
    tre3->addChild(tre13);
    tre13 = new Tree<int>(24);
    tre3->addChild(tre13);
    tre13->addChild(tre23);
    tre23  = new Tree<int>(25);
    tre3->addChild(tre23);


    assert(tre23->get_root()->getValue() == tre3->getValue());
    assert(tre13->get_root()->getValue() == tre3->getValue());

    assert(tre3->getChildren().size()==3);
    assert(tre13->getChildren().size()==1);
    assert(tre23->getChildren().size()==0);


    tre2->addChild(tre3);

    tre2->delete_child(tre3);
    assert(tre2->getChildren().size()==3);

    Board board,board1;
    assert(board.getValue(3) =='*');

    board.setValue(0,'O');
    board.setValue(1,'O');
    board.setValue(2,'X');

    assert(board.get_size()==3);
    assert(board.user_won()==false);
    assert(board.isFull()==false);

    board.setValue(2,'O');
    assert(board.user_won());

    board1.setValue(0,'X');
    board1.setValue(4,'X');
    board1.setValue(8,'X');
    assert(board1.cpu_won());

    int arr3[] = {1,2,3};
    int arr4[] = {3,4,5};
    auto set3 = new Set<int>();
    auto set4 = new Set<int>();
    for (int i=0;i<3;i++)
    {
        set3->Add(&arr3[i]);
        set4->Add(&arr4[i]);
    }

    assert((*set3 | *set4)->GetCount() == 5);
    assert((*set3 - *set4)->GetCount() == 2);
    assert((*set3 & *set4)->GetCount() == 1);

    int arr1[] = {1,2,3,3};
    int arr2[] = {2,2,1,3};
    auto set1 = new Set<int>();
    auto set2 = new Set<int>();
    for (int i=0;i<4;i++)
    {
        set1->Add(&arr1[i]);
        set2->Add(&arr2[i]);
    }

    assert((*set1 & *set2)->GetCount() == 3);
    assert((*set1 - *set2)->GetCount() == 0);
    assert(*set1==*set2);



}

#endif //SEM_3_LABA2_TESTS_H
