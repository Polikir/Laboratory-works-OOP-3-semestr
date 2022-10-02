#include <iostream>
#include <cassert>
#include "Graph.h"
#include "UndirectedGraph.h"


using namespace std;

void Test()
{
    Graph<int,int>* graph;
    UndirectedGraph<int,int>* u_graph;

    graph = new Graph<int,int>();
    u_graph = new UndirectedGraph<int,int>();

    u_graph->addVertex(1);
    u_graph->addVertex(2);

    graph->addVertex(1);
    graph->addVertex(2);

    u_graph->addEdge(1,2);
    graph->addEdge(1,2);

    assert(graph->containsEdge(1,2));
    assert(!graph->containsEdge(2,1));

    assert(u_graph->containsEdge(1,2));
    assert(u_graph->containsEdge(2,1));

    assert(graph->getVertexCount()==2);
    assert(u_graph->getVertexCount()==2);
    assert(graph->containsVertex(3)==-1);

    assert(u_graph->containsVertex(1)!=-1);
    assert(u_graph->containsVertex(3)==-1);

    assert(graph->getVertexes()->Get(graph->containsVertex(1))->GetDegree()==1);
    assert(graph->getVertexes()->Get(graph->containsVertex(2))->GetDegree()==0);

    assert(u_graph->getVertexes()->Get(u_graph->containsVertex(1))->GetDegree()==1);
    assert(u_graph->getVertexes()->Get(u_graph->containsVertex(2))->GetDegree()==1);

    u_graph->addVertex(3);
    u_graph->addVertex(4);

    graph->addVertex(3);
    graph->addVertex(4);

    u_graph->addEdge(2,3);
    graph->addEdge(2,3);

    u_graph->addEdge(3,4);
    graph->addEdge(3,4);

    u_graph->addEdge(1,4);
    graph->addEdge(1,4);


    assert(graph->containsEdge(2,3));
    assert(!graph->containsEdge(3,2));

    assert(u_graph->containsEdge(2,3));
    assert(u_graph->containsEdge(3,2));

    assert(graph->getVertexCount()==4);
    assert(u_graph->getVertexCount()==4);
    assert(graph->containsVertex(5)==-1);

    assert(u_graph->containsVertex(1)!=-1);
    assert(u_graph->containsVertex(5)==-1);

    assert(graph->getVertexes()->Get(graph->containsVertex(1))->GetDegree()==2);
    assert(graph->getVertexes()->Get(graph->containsVertex(4))->GetDegree()==0);

    assert(u_graph->getVertexes()->Get(u_graph->containsVertex(1))->GetDegree()==2);
    assert(u_graph->getVertexes()->Get(u_graph->containsVertex(2))->GetDegree()==2);
    assert(u_graph->getVertexes()->Get(u_graph->containsVertex(3))->GetDegree()==2);
    assert(u_graph->getVertexes()->Get(u_graph->containsVertex(4))->GetDegree()==2);


}