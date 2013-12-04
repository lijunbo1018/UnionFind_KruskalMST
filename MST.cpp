#include <iostream>
#include <iomanip>
#include <fstream>
#include "MST.h"
using namespace std;


MST::MST():union_find(NULL), total_vertices(0){}

MST::~MST()
{
    //Release memory if allocated
    if (NULL != union_find)
    {
        delete union_find;
        union_find = NULL;
    }
}

void MST::initGraph()
{
    ifstream inFile;                                         //File stream to read data
    inFile.open("./GraphData.dat", ios::in);
    //Fail to open the data file
    if (0 == inFile)
    {
        return ;
    }
    //Read the total number of vertices
    inFile >> total_vertices;
    //Read all edge into priority queue
    while (!inFile.eof())
    {
        Edge new_edge;
        inFile >> new_edge.head;
        inFile >> new_edge.tail;
        inFile >> new_edge.cost;
        edge_list.push(new_edge);
    }
    //Close and clear the file stream
    inFile.close();
    inFile.clear();

    //Initiate UnionFind class member
    union_find = new UnionFind(total_vertices);
}

//Print edge list
void MST::print_MST()
{
    vector<Edge>::iterator iter;
    for (iter = minimum_spanning_tree.begin(); iter != minimum_spanning_tree.end(); iter++)
    {
        cout << setw(2) << (*iter).head << "-->";
        cout << setw(2) << (*iter).tail << ", cost: ";
        cout << setw(2) << (*iter).cost << endl;
    }
}

UINT MST::generateMST()
{
    Edge shortest;
    UINT MST_cost = 0;
    while (!edge_list.empty())
    {
        shortest = edge_list.top();
        if (!union_find->isConnected(shortest.head, shortest.tail))
        {
            union_find->Union(shortest.head, shortest.tail);
            MST_cost += shortest.cost;
            minimum_spanning_tree.push_back(shortest);
            if (1 == union_find->getSubsetsNum())
            {
                return MST_cost;
            }
        }
        edge_list.pop();
    }
    return 0;
}

