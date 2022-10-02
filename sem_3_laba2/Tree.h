#pragma once

#include <vector>
#include "Board.h"

template <typename T>
class Tree
{
public:

    Tree()
    {
        this->root = this;
    }

    Tree( T t )
    {
        this->root = this;
        this->t = t;
    }

    ~Tree() = default;

    Tree* get_root()
    {
        return this->root;
    }

    void set_root(Tree* tree)
    {
        this->root = tree;
    }

    void addChild(Tree* tree)
    {
        tree->setParent(this);
        tree->set_root(this->root);
        this->children.push_back(tree);
    }

    void setValue( T q )
    {
        this->t = q;
    }

    void setParent( Tree* p )
    {
        this->parent_path = p;

    }


    T getValue()
    {
        return this->t;
    }

    void remove_child(Tree* tree)
    {
        for (int i=0;i<children.size();i++)
        {
            if (children[i] == tree)
            {   children[i]->setParent(nullptr);
                children.erase(children.begin() + i);
                break;
            }
        }
    }

    Tree* getParent()
    {
        return this->parent_path;
    }

    void delete_child(Tree* tree)
    {
        int tt = tree->getChildren().size();
        for (int i=0;i<tt;i++)
        {
            tree->parent_path->addChild(tree->getChildren()[i]);
        }
        this->remove_child(tree);
    }

    std::vector< Tree *> getChildren()
    {
        return this->children;
    }

    void print( int depth = 0 )
    {
        for ( int i = 0 ; i < depth ; ++i )
        {
            if ( i != depth-1 ) std::cout << "    ";
            else std::cout << "|-- ";
        }
        cout<<this->t<<endl;
        for ( uint i = 0 ; i < this->children.size() ; ++i )
        {
            this->children.at(i)->print( depth+1 );
        }
    }

private:
    T t;
    Tree* parent_path = nullptr;
    std::vector<Tree*> children;
    Tree* root = nullptr;
};

