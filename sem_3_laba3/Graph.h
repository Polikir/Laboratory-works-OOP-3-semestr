#include "ListSequence.h"
#include "vector"

#ifndef SEM_3_LABA3_GRAPH_H
#define SEM_3_LABA3_GRAPH_H

template <class Tver, class Twei>
class Edge;

template <class Tver, class Twei>
class Vertex {
private:
    Tver name;
    Sequence<Edge<Tver,Twei>*>* out_incidents;
public:
    Vertex(Tver name) {
        this->name = name;
        out_incidents = new ArraySequence<Edge<Tver,Twei>*>();
    }

    Tver GetName() {
        return this->name;
    }
    Sequence<Edge<Tver,Twei>*>* GetEdges() {
        return out_incidents;
    }

    void AddEdge(Edge<Tver,Twei>* edge) {
        out_incidents->Append(edge);
    }
    int GetDegree(){
        return out_incidents->GetSize();
    }
};

template <class Tver, class Twei>
class Edge {
private:
    Twei weight;
    Vertex<Tver,Twei>* from;
    Vertex<Tver,Twei>* to;
public:
    Edge(Tver first, Tver second) {
        this->from = new Vertex<Tver,Twei>(first);
        this->to = new Vertex<Tver,Twei>(second);
    }

    pair<Vertex<Tver,Twei>*, Vertex<Tver,Twei>*> getVertex() {
        return make_pair(from, to);
    }

};



template <class Tver, class Twei>
class Graph {

public:
    Graph() {
        this->vertexList = new ArraySequence<Vertex<Tver,Twei>*>();
    }

    void addVertex(Tver name) {

        Vertex<Tver,Twei>* toAdd = new Vertex<Tver,Twei>(name);

        if (containsVertex(name) == -1) {
            vertexList->Append(toAdd);
        }
    }

    void addEdge(Tver first, Tver second) {

        if (containsEdge(first,second) == false) {
            Edge<Tver, Twei>* edgeToAdd = new Edge<Tver, Twei>(first, second);

            if (containsVertex(first) == -1) {
                Vertex<Tver,Twei>* firstToAdd = new Vertex<Tver,Twei>(first);
                firstToAdd->AddEdge(edgeToAdd);
                vertexList->Append(firstToAdd);
            }
            else {
                this->vertexList->Get(containsVertex(first))->AddEdge(edgeToAdd);
            }

            if (containsVertex(second) == -1) {
                Vertex<Tver,Twei>* secondToAdd = new Vertex<Tver,Twei>(second);
                vertexList->Append(secondToAdd);
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
            Vertex<Tver,Twei>* first_v = this->vertexList->Get(containsVertex(first));
            for (int i =0; i<first_v->GetDegree(); i++) {
                if (first_v->GetEdges()->Get(i)->getVertex().second->GetName() == second) {
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
            Vertex<Tver,Twei>* first_v = this->vertexList->Get(containsVertex(first));

            for (int i =0; i<first_v->GetEdges()->GetSize(); i++) {
                if (first_v->GetEdges()->Get(i)->getVertex().second->GetName() == second) {
                    first_v->GetEdges()->RemoveAt(i);
                }
            }
        }
    }


    void removeVertex(Tver name) {
        if (containsVertex(name) != -1) {
            Vertex<Tver,Twei>* vert = this->vertexList->Get(containsVertex(name));
            for (int i=0; i<vert->GetDegree(); i++) {
                Edge<Tver,Twei>* edge = vert->GetEdges()->Get(i);
                this->removeEdge(edge->getVertex().first->GetName(),edge->getVertex().second->GetName());
                i--;
            }
            for (int i =0; i<this->getVertexes()->GetSize(); i++) {
                if (this->getVertexes()->Get(i)->GetName()==name) {
                    continue;
                }
                else {
                    Vertex<Tver,Twei>* vert = getVertexes()->Get(i);
                    for (int j =0; j<vert->GetDegree(); j++) {
                        Edge<Tver,Twei>* edge = vert->GetEdges()->Get(j);
                        if (edge->getVertex().second->GetName()==name) {
                            this->removeEdge(vert->GetName(), name);
                            j--;
                        }
                    }
                }
            }
            this->getVertexes()->RemoveAt(containsVertex(name));
        }
    }


    ArraySequence<Vertex<Tver,Twei>*>* getVertexes() {
        return this->vertexList;
    }

    int getVertexCount() {
        return this->vertexList->GetSize();
    }

private:
    ArraySequence<Vertex<Tver,Twei>*>* vertexList;
};

#endif //SEM_3_LABA3_GRAPH_H
