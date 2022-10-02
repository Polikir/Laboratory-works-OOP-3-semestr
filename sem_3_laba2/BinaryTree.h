

#ifndef SEM_3_LABA2_BINARYTREE_H
#define SEM_3_LABA2_BINARYTREE_H



#include <iostream>
#include "ArraySequence.h"
#include <queue>
#pragma once
using namespace std;


template <typename T>
class BinaryTree {
private:
    struct Node {
        Node* Left;
        Node* Right;
        Node* Parent;
        T* Value;
    };
    int size = 0;
    BinaryTree<T>* RoundForMap(T* (*Fun)(T*), Node* Original, BinaryTree<T>* Result);
    BinaryTree<T>* RoundForMap(T* (& Fun)(BinaryTree<T>*), BinaryTree<T>* Original, Node* OriginalNode, BinaryTree<T>* Result);
    BinaryTree<T>* RoundForWhere(bool (*Fun)(T*), Node* Original, BinaryTree<T>* Result);
    BinaryTree<T>* RoundForWhere(void (*Fun)(Node*), Node* Original, BinaryTree<T>* Result);
    void RoundForDeleteFromTree(Node* target);
    bool RoundForSearch(Node* tree, Node* value , bool);
    bool RoundForSearchTree(Node* root1, Node* root2, bool result);
    void TreePrintKPL(Node* tree);
    void TreePrintLKP(Node* tree);
    void FreeMem(Node *tree);
    string ToStringKPL(Node* tree , string result);
    string ToStringLKP(Node* tree , string result);
    BinaryTree<T>* RoundForSub(Node* tree, bool find, T* subElem, BinaryTree<T>* Result);

    Node* Root;


public:
    Node* GetRoot() { return Root; }
    void PrintTree(BinaryTree<T>* Root);
    BinaryTree<T>();
    ~BinaryTree<T>();
    void Add(T* Value) { AddNode(Value, Root, nullptr);size+=1;}
    Node* AddNode(T* Value, Node*& New_Node, Node * parent)
    {
        if (New_Node == nullptr)
        {
            New_Node = new Node;
            New_Node->Right = New_Node->Left = nullptr;
            New_Node->Value = Value;
            New_Node->Parent = parent;
            if (Root == nullptr)
                Root = New_Node;
        }
        else if (*Value < *(New_Node->Value))
        {
            New_Node->Left = AddNode(Value, New_Node->Left, New_Node);

        }
        else if (*Value >= *(New_Node->Value))
        {
            New_Node->Right = AddNode(Value, New_Node->Right, New_Node);
        }
        return New_Node;
    }


    int GetSize()
    {
        return size;
    }
    void MinSize()
    {
        this->size -= 1;
    }
    T* GetValue()
    {
        return this->Value;
    }
    BinaryTree<T>* Map(T* (*Fun)(T*));
    BinaryTree<T>* Map(BinaryTree<T>* (& Fun)(BinaryTree<T>*));
    BinaryTree<T>* Where(bool (*Fun)(T*));
    void* DeleteFromTree(BinaryTree<T>* tree,T* num);
    bool SearchItem(Node *tree,T* Value);
    static void ToArray(Node* tree1,ArraySequence<T>* arr);


    bool SearchTree(BinaryTree<T>* tree1, BinaryTree<T>* tree2);
    BinaryTree<T>* Sub(BinaryTree<T>* tree, T* subElem);
    string ToString();

};

template<typename T>
void BinaryTree<T>::TreePrintKPL(Node * tree)
{
    if (tree != nullptr)
    {
        cout << ToStrings(*(tree->Value)) << "\t";
        TreePrintKPL(tree->Right);
        TreePrintKPL(tree->Left);
    }
};


template<typename T>
void BinaryTree<T>::TreePrintLKP(Node * tree)
{
    if (tree != nullptr)
    {
        cout << " < ";
        TreePrintLKP(tree->Left);
        cout << " > ";
        cout << " [ " <<ToStrings(*(tree->Value)) << " ] ( ";
        TreePrintLKP(tree->Right);
        cout << " ) ";
    }

};

template<typename T>
void BinaryTree<T>::FreeMem(Node * tree)
{
    if (tree != NULL) {
        FreeMem(tree->Left);
        FreeMem(tree->Right);
        delete tree->Value;
    }
}

template<typename T>
string BinaryTree<T>::ToStringKPL(Node * tree, string result)
{
    if (tree != nullptr) {
        result += "<" + ToStrings(*(tree->Value)) + "> ( ";
        result = ToStringKPL(tree->Right, result);
        result += ") [ ";
        result = ToStringKPL(tree->Left, result);
        result += "] ";
    }
    return result;
}

template<typename T>
string BinaryTree<T>::ToStringLKP(Node * tree, string result)
{
    if (tree != nullptr)
    {
        result += " ( ";
        result = ToStringLKP(tree->Left, result);
        result += " ) < " + ToStrings(*(tree->Value)) + " > [ ";
        result = ToStringLKP(tree->Right, result);
        result += " ] ";

    }
    return result;
}

template<typename T>
void BinaryTree<T>::PrintTree(BinaryTree<T>* tree)
{
    cout << tree->ToString() << endl;
};

template<typename T>
BinaryTree<T>::~BinaryTree<T>()
{
    FreeMem(Root);
}

template<typename T>
BinaryTree<T>* BinaryTree<T>::Map(T* (*Fun)(T*))
{
    BinaryTree<T> *Result = new BinaryTree<T>();
    Result = RoundForMap(Fun, Root, Result);
    return Result;
}

template<typename T>
BinaryTree<T>* BinaryTree<T>::Where(bool(*Fun)(T*))
{
    BinaryTree<T>* Result = new BinaryTree<T>();
    RoundForWhere(Fun, Root, Result);
    return Result;
}



template<typename T>
bool BinaryTree<T>::SearchItem(Node* tree, T* Value)
{
    Node* New_node = new Node;
    New_node->Value = Value;
    New_node->Left = nullptr;
    New_node->Right = nullptr;
    bool result = false;
    result =  RoundForSearch(tree, New_node , result);
    return result;
}


template<typename T>
bool BinaryTree<T>::SearchTree(BinaryTree<T>* tree1, BinaryTree<T>* tree2)
{
    bool result = false;
    result = this->RoundForSearchTree(tree1->GetRoot(), tree2->GetRoot(), result);
    return result;
}

template<typename T>
BinaryTree<T>* BinaryTree<T>::Sub(BinaryTree<T>* tree, T* subElem)
{
    BinaryTree<T>* result = new BinaryTree<T>();
    bool find = false;
    result = RoundForSub(tree->GetRoot(), find, subElem, result);
    return result;
}

template<typename T>
string BinaryTree<T>::ToString()
{
    int choise;
    cout << "Choose format:\n1. LKP Format\n2. KPL Format\n";
    cin >> choise;
    string result = "";
    switch (choise)
    {
        case 1:
            result = ToStringLKP(Root , result);
            return result;
            break;
        case 2:
            result = ToStringKPL(Root , result);
            return result;
            break;
        default:
            cout << "Ooops!";
            return 0;
            break;
    }

}

template<typename T>
BinaryTree<T>* BinaryTree<T>::RoundForSub(Node* tree, bool find, T* subElem, BinaryTree<T>* Result)

{
    if (tree != nullptr)
    {
        if (*(tree->Value) == *subElem || find)
        {
            find = true;
            Result->Add(tree->Value);
        }
        Result = RoundForSub(tree->Left, find, subElem, Result);
        Result = RoundForSub(tree->Right, find, subElem, Result);
    }
    return Result;
}

template<typename T>
BinaryTree<T>* BinaryTree<T>::RoundForWhere(bool (*Fun)(T*), Node* Original, BinaryTree<T>* Result)
{
    if (Original != nullptr) {
        if (Fun(Original->Value))
            Result->Add(Original->Value);
        Result = RoundForWhere(Fun, Original->Left, Result);
        Result = RoundForWhere(Fun, Original->Right, Result);
    }
    return Result;
}

template<typename T>
BinaryTree<T>* BinaryTree<T>::RoundForWhere(void (*Fun)(Node*), Node* Original, BinaryTree<T>* Result)
{
    if (Original != nullptr) {
        if (Fun(Original))
            Result->Add(Original->Value);
        Result = RoundForWhere(Fun, Original->Left, Result);
        Result = RoundForWhere(Fun, Original->Right, Result);
    }
    return Result;
}





template<typename T>
BinaryTree<T>::BinaryTree()
{
    Root = nullptr;
}

template<typename T>
BinaryTree<T>* BinaryTree<T>::RoundForMap(T* (*Fun)(T*), Node* Original, BinaryTree<T>* Result)
{
    if (Original != nullptr) {
        Result->Add(Fun(Original->Value));
        Result = RoundForMap(Fun, Original->Left, Result);
        Result = RoundForMap(Fun, Original->Right, Result);
    }
    return Result;
}

template<typename T>
BinaryTree<T>* BinaryTree<T>::RoundForMap(T* (&Fun)(BinaryTree<T>*), BinaryTree<T>* Original, Node* OriginalNode, BinaryTree<T>* Result)
{
    if (Original != nullptr) {
        Result->Add(Fun(Original->GetRoot));
        Result = RoundForMap(Fun, (Original->GetRoot), OriginalNode->Left, Result);
        Result = RoundForMap(Fun, (Original->GetRoot), OriginalNode->Right, Result);
    }
    return Result;
}

template<typename T>
void BinaryTree<T>::RoundForDeleteFromTree(Node* target)
{

    if (target->Parent == nullptr)
    {
        if (target->Left == nullptr && target->Right == nullptr)
        {
            target->Value = nullptr;
            target->Right = nullptr;
            target->Left = nullptr;
        }
        else if (target->Left == nullptr)
        {   target->Value = target->Right->Value;
            target->Right = target->Right->Right;
            target->Left = target->Right->Parent->Left;

        }
        else if (target->Right == nullptr)
        {
            target->Value = target->Left->Value;
            target->Left = target->Left->Left;
            target->Right = target->Left->Parent->Right;

        }
        else
        {
            Node* localMax0;
            localMax0 = target->Left;
            while (localMax0->Right != nullptr)
            {
                localMax0 = localMax0->Right;
            }
            target->Value = localMax0->Value;
            RoundForDeleteFromTree(localMax0);

        };
    }
    else{
        Node* localMax;
        if (target->Left != nullptr)
        {
            localMax = target->Left;
        }
        else
        {
            localMax = target;
        }
        while (localMax->Right != nullptr)
        {
            localMax = localMax->Right;
        }

        if (target->Left && target->Right) {
            target->Value = localMax->Value;
            RoundForDeleteFromTree(localMax);
        } else if (target->Left) {
            if (target == target->Parent->Left) {
                target->Parent->Left = target->Left;
            } else {
                target->Parent->Right = target->Left;
            }
        } else if (target->Right) {
            if (target == target->Parent->Right) {
                target->Parent->Right = target->Right;
            } else {
                target->Parent->Left = target->Right;
            }
        } else {
            if (target == target->Parent->Left) {
                target->Parent->Left = nullptr;
            } else {
                target->Parent->Right = nullptr;
            }
        }}
}

template<typename T>
bool BinaryTree<T>::RoundForSearch(Node* tree, Node* Node_value , bool Result)
{
    if (Node_value == nullptr) {
        return true;
    }
    else if ((tree == nullptr) && (Node_value != nullptr)) {
        return false;
    }
    else if (tree != nullptr) {
        if (*(tree->Value) == *(Node_value->Value)) {
            if (RoundForSearch(tree->Left, Node_value->Left, Result) && RoundForSearch(tree->Right, Node_value->Right, Result)) {
                return true;
            }
        }
        Result = RoundForSearch(tree->Left, Node_value, Result) || RoundForSearch(tree->Right, Node_value, Result);
    }
    return Result;
}




template<typename T>
bool BinaryTree<T>::RoundForSearchTree(Node* root1, Node* root2, bool result)
{
    if (root2 == nullptr) {
        return true;
    }
    else if ((root1 == nullptr) && (root2 != nullptr)) {
        return false;
    }
    else if (root1 != nullptr) {
        if (*(root1->Value) == *(root2->Value)) {
            if (RoundForSearchTree(root1->Left, root2->Left, result) && RoundForSearchTree(root1->Right, root2->Right, result)) {
                return true;
            }
        }
        result = RoundForSearchTree(root1->Left, root2, result) || RoundForSearchTree(root1->Right, root2, result);
    }
    return result;
}

template<typename T>
void* BinaryTree<T>::DeleteFromTree(BinaryTree<T>* tree,T* num)
{   Node* target;
    target = tree->GetRoot();
    for(;;)
    {
        if (*(target->Value) == *num)
        {
            break;
        }
        else if (*(target->Value) > *num)
        {

            target = target->Left;
        }
        else
        {
            target = target->Right;
        }
    }

    RoundForDeleteFromTree(target);
    tree->MinSize();

}


template<typename T>
BinaryTree<T>* BinaryTree<T>::Map(BinaryTree<T>* (&Fun)(BinaryTree<T>*))
{
    BinaryTree<T>* Result = new BinaryTree<T>();
    Result = RoundForMap(Fun, this, Root, Result);
    return Result;
}

template<typename T>
void BinaryTree<T>::ToArray(Node* tree1,ArraySequence<T>* arr)
{
    if (tree1 != nullptr)
    {
        arr->Append(*(tree1->Value));
        ToArray(tree1->Right,arr);
        ToArray(tree1->Left,arr);
    }
}



#endif //SEM_3_LABA2_BINARYTREE_H
