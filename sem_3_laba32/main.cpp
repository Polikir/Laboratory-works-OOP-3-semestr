#include <iostream>
//#include "Graph.h"
//#include "UndirectedGraph.h"
#include "Tests.h"
#include <fstream>
#include "random"
#include <ctime>
using namespace std;

template <class Tver, class Twei>
void d_graph_to_file(Graph<Tver,Twei>* graph)
{
    ofstream out;
    out.open("/Users/kirillgolubev/Hlam/GV/graph");
    if (out.is_open())
    {
        out<<0<<endl;
        for (int i=0;i<graph->getVertexCount();i++)
        {
            out <<graph->getVertexes()->Get(i)->GetName()<<",";

        }
        out<<""<<endl;
        for (int i=0;i<graph->getVertexCount();i++)
        {
            for (int j=0;j<(graph->getVertexes()->Get(i)->GetDegree());j++)
            {
                out <<graph->getVertexes()->Get(i)->GetEdges()->Get(j)->getVertex().first->GetName()<<"-"<<graph->getVertexes()->Get(i)->GetEdges()->Get(j)->getVertex().second->GetName()<<",";
            }

        }

    }
}

template <class Tver, class Twei>
void u_graph_to_file(UndirectedGraph<Tver,Twei>* graph)
{
    ofstream out;
    out.open("/Users/kirillgolubev/Hlam/GV/graph");
    if (out.is_open())
    {
        out<<1<<endl;
        for (int i=0;i<graph->getVertexCount();i++)
        {
            out <<graph->getVertexes()->Get(i)->GetName()<<",";

        }
        out<<""<<endl;

        for (int i=0;i<graph->getVertexCount();i++)
        {
            out <<graph->getVertexes()->Get(i)->GetColor()<<",";

        }
        out<<""<<endl;

        for (int i=0;i<graph->getVertexCount();i++)
        {
            for (int j=0;j<(graph->getVertexes()->Get(i)->GetDegree());j++)
            {
                out <<graph->getVertexes()->Get(i)->GetEdges()->Get(j)->getVertex().first->GetName()<<"-"<<graph->getVertexes()->Get(i)->GetEdges()->Get(j)->getVertex().second->GetName()<<",";
            }

        }

    }
}


template<typename T, typename K>
void Undirected_UI() {
    UndirectedGraph<T, K> graph = UndirectedGraph<T, K>();
    while (true) {
        //----------------------------------------------------------
        {
            cout << "Commands:\n";
            cout << "	0 - Show colored graph\n";
            cout << "	1 - Add edge\n";
            cout << "	2 - Add vertex\n";
            cout << "	3 - Remove Edge\n";
            cout << "	4 - Remove Vertex\n";
            cout << "	q - quit\n";
        }
        //----------------------------------------------------------
        char command;
        cin >> command;
        if (command == 'q') {
            return;
        }
        if (command == '0') {
            graph.Coloring();
            u_graph_to_file(&graph);
        }
        if (command == '1') {
            int count;
            cout << "Enter the number of edges";
            cin >> count;
            for (int i = 0; i < count; i++) {
                T from, to;
                cout << "input keys: ";
                cin >> from >> to;
                graph.addEdge(from, to);
            }
        }
        if (command == '2') {
            int count;
            cout << "Enter the number of vertexes ";
            cin >> count;
            for (int i = 0; i < count; i++) {
                T v;
                cout << "input keys: ";
                cin >> v;
                graph.addVertex(v);
            }}
        if (command == '3') {
                T from, to;
                cout << "input keys: ";
                cin >> from >> to;
                graph.removeEdge(from, to);
        }

        if (command == '4') {
                T v;
                cout << "input keys: ";
                cin >> v;
                graph.removeVertex(v);
        }

    }
}

template <typename T, typename K>
void Directed_UI() {
    Graph<T,K> graph = Graph<T,K>();
    while (true) {
        //----------------------------------------------------------
        {
            cout << "Commands:\n";
            cout << "	0 - Show graph\n";
            cout << "	1 - Add edge\n";
            cout << "	2 - Add vertex\n";
            cout << "	3 - Remove Edge\n";
            cout << "	4 - Remove Vertex\n";
            cout << "	q - quit\n";
        }
        //----------------------------------------------------------
        char command;
        cin >> command;
        if (command == 'q') {
            return;
        }
        if (command == '0') {
            d_graph_to_file(&graph);

        }

        if (command == '1') {
            int count;
            cout << "Enter the number of edges: ";
            cin >> count;
            for (int i = 0; i < count; i++) {
                T from, to;
                cout << "input keys: ";
                cin >> from >> to;
                graph.addEdge(from, to);
            }
        }
        if (command == '2') {
            int count;
            cout << "Enter the number of vertexes: ";
            cin >> count;
            for (int i = 0; i < count; i++) {
                T v;
                cout << "input keys: ";
                cin >> v;
                graph.addVertex(v);
            }
        }
        if (command == '3') {
            T from, to;
            cout << "input keys: ";
            cin >> from >> to;
            graph.removeEdge(from, to);
        }

        if (command == '4') {
            T v;
            cout << "input keys: ";
            cin >> v;
            graph.removeVertex(v);
        }
    }
}

void Menu() {
    char command;
    //----------------------------------------------------------
    while (true) {

        cout << "Choose the graph\n";
        cout << "	1 - Directed\n";
        cout << "	2 - Undirected\n";
        cout << "	0 - exit\n";

        //----------------------------------------------------------

        cin >> command;

        if (command == '0') {
            return;
        }
        if (command == '1') {
            Directed_UI<int, int>();

        }
        if (command == '2') {
            Undirected_UI<int, int>();
        }
    }
}

int main()
{   Test();
    Menu();
    return 0;
}