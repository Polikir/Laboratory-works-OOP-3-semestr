#include "ListSequence.h"
#include "random"
#include "ctime"
#include "ISorter.h"
#include <fstream>
using namespace std;
#include<stdlib.h>
#include<time.h>


random_device rd;
mt19937 eng(time(0));
uniform_int_distribution<int> dist(0, 15);

string RandomHEXColor(){
    string hex="0123456789ABCDEF";
    string color ="#";
    for(int i = 0 ; i < 6; i++ ) {
        color += hex[ dist(eng) ];
    }
    return color;
}

template <class Tver, class Twei>
class U_Edge;

template <class Tver, class Twei>
class U_Vertex {
private:
    Tver name;
    string color;
    Sequence<U_Edge<Tver,Twei>*>* incidents;

public:
    U_Vertex(Tver name) {
        this->name = name;
        incidents = new ArraySequence<U_Edge<Tver,Twei>*>();
    }

    Tver GetName() {
        return this->name;
    }
    string GetColor() {
        return this->color;
    }
    void SetColor(string clr) {
        this->color = clr;
    }
    Sequence<U_Edge<Tver,Twei>*>* GetEdges() {
        return incidents;
    }

    void AddEdge(U_Edge<Tver,Twei>* edge) {
        incidents->Append(edge);
    }
    int GetDegree(){
        return incidents->GetSize();
    }


};

template <class Tver, class Twei>
class U_Edge {
private:
    U_Vertex<Tver,Twei>* from;
    U_Vertex<Tver,Twei>* to;
    Twei weight;
public:
    U_Edge(Tver first, Tver second) {
        this->from = new U_Vertex<Tver,Twei>(first);
        this->to = new U_Vertex<Tver,Twei>(second);
    }


    pair<U_Vertex<Tver,Twei>*, U_Vertex<Tver,Twei>*> getVertex() {
        return make_pair(from, to);
    }

    void set_weight(Twei w)
    {
        weight = w;
    }

    Twei get_weight()
    {
        return weight;
    }

};

template <class Tver, class Twei>
int compare_v(U_Vertex<Tver,Twei>* v1, U_Vertex<Tver,Twei>* v2) {
    return v1->GetDegree()<v2->GetDegree() ? 1 : 0;
}


template <class Tver, class Twei>
class UndirectedGraph {

public:
    UndirectedGraph() {
        this->vertexList = new ArraySequence<U_Vertex<Tver,Twei>*>();
    }

    void addVertex(Tver name) {

        U_Vertex<Tver,Twei>* toAdd = new U_Vertex<Tver,Twei>(name);

        if (containsVertex(name) == -1) {
            vertexList->Append(toAdd);
        }

    }

    void addEdge(Tver first, Tver second) {

        if (containsEdge(first,second) == false) {
            U_Edge<Tver, Twei>* edgeToAdd = new U_Edge<Tver, Twei>(first, second);

            if (containsVertex(first) == -1) {
                U_Vertex<Tver,Twei>* firstToAdd = new U_Vertex<Tver,Twei>(first);
                firstToAdd->AddEdge(edgeToAdd);
                vertexList->Append(firstToAdd);
            }
            else {
                this->vertexList->Get(containsVertex(first))->AddEdge(edgeToAdd);
            }

            if (containsVertex(second) == -1) {
                U_Vertex<Tver,Twei>* secondToAdd = new U_Vertex<Tver,Twei>(second);
                secondToAdd->AddEdge(edgeToAdd);
                vertexList->Append(secondToAdd);
            }
            else {
                this->vertexList->Get(containsVertex(second))->AddEdge(edgeToAdd);
            }
        }
    }

    int containsVertex(Tver name) {
        for (int i = 0; i < this->getVertexCount(); ++i) {
            if (this->vertexList->Get(i)->GetName() == name) {
                return i;
            }
        }
        return -1;
    }

    bool containsEdge(Tver first, Tver second) {
        if (containsVertex(first) != -1 && containsVertex(second) != -1 ) {
            bool flag;
            U_Vertex<Tver,Twei>* first_v = this->vertexList->Get(containsVertex(first));
            U_Vertex<Tver,Twei>* second_v = this->vertexList->Get(containsVertex(second));
            for (int i =0; i<first_v->GetDegree(); i++) {
                if (first_v->GetEdges()->Get(i)->getVertex().second->GetName() == second || first_v->GetEdges()->Get(i)->getVertex().first->GetName() == second ) {
                    flag = true;
                    return flag;
                }
            }
            for (int i =0; i<second_v->GetDegree(); i++) {
                if (second_v->GetEdges()->Get(i)->getVertex().second->GetName() == first || second_v->GetEdges()->Get(i)->getVertex().first->GetName() == first ) {
                    flag = true;
                    return flag;
                }
            }
            return false;
        }
        else {
            return false;
        }
    }

    void removeEdge(Tver first, Tver second) {
        if (containsEdge(first, second) == true) {
            U_Vertex<Tver,Twei>* first_v = this->vertexList->Get(containsVertex(first));
            U_Vertex<Tver,Twei>* second_v = this->vertexList->Get(containsVertex(second));
            for (int i =0; i<first_v->GetEdges()->GetSize(); i++) {
                if (first_v->GetEdges()->Get(i)->getVertex().second->GetName() == second || first_v->GetEdges()->Get(i)->getVertex().first->GetName() == second) {
                    first_v->GetEdges()->RemoveAt(i);
                }
            }
            for (int i =0; i<second_v->GetEdges()->GetSize(); i++) {
                if (second_v->GetEdges()->Get(i)->getVertex().second->GetName() == first || second_v->GetEdges()->Get(i)->getVertex().first->GetName() == first) {
                    second_v->GetEdges()->RemoveAt(i);
                }
            }
        }
    }

    void removeVertex(Tver name) {
        if (containsVertex(name) != -1) {
            U_Vertex<Tver,Twei>* vert = this->vertexList->Get(containsVertex(name));
            for (int i=0; i<vert->GetDegree(); i++) {
                U_Edge<Tver,Twei>* edge = vert->GetEdges()->Get(i);
                this->removeEdge(edge->getVertex().first->GetName(),edge->getVertex().second->GetName());
                i--;
            }
            this->getVertexes()->RemoveAt(containsVertex(name));
        }
    }

    static void OneColor(Sequence<U_Vertex<Tver,Twei>*>* seq, Sequence<U_Vertex<Tver,Twei>*>* un_inc, UndirectedGraph<Tver,Twei> graph, string color){
        if (un_inc->GetSize()==0) {
            return;
        }
        un_inc->Get(0)->SetColor(color);
        U_Vertex<Tver,Twei>* vert = un_inc->Get(0);
        for (int i=0; i<seq->GetSize(); i++) {
            if (seq->Get(i)->GetName()==vert->GetName()){
                seq->RemoveAt(i);
                i--;
            }
        }
        un_inc->RemoveAt(0);


        for (int i =0; i<un_inc->GetSize(); i++) {
            if (graph.containsEdge(vert->GetName(),un_inc->Get(i)->GetName())) {
                un_inc->RemoveAt(i);

                i--;
            }
        }
        OneColor(seq, un_inc,graph,color);

    }
    void Coloring(){

        ISorter<U_Vertex<Tver,Twei>*>* sorter = new QuickSorter<U_Vertex<Tver,Twei>*>;
        Sequence<U_Vertex<Tver,Twei>*>* seq = this->getVertexes();
        Sequence<U_Vertex<Tver,Twei>*>* sorted_seq = sorter->Sort(seq,compare_v);

        while (sorted_seq->GetSize()>0) {
            string color = RandomHEXColor();
            Sequence<U_Vertex<Tver,Twei>*>* un_inc = sorted_seq->Clone();
            OneColor(sorted_seq,un_inc,*this,color);

        }
    }

    ArraySequence<U_Vertex<Tver,Twei>*>* getVertexes() {
        return this->vertexList;
    }

    int getVertexCount() {
        return this->vertexList->GetSize();
    }

private:
    ArraySequence<U_Vertex<Tver,Twei>*>* vertexList;
};
