#pragma once

#include <queue>
#include <vector>
#include "UnionFind.h"

typedef struct 
{
    UINT head;
    UINT tail;
    UINT cost;
}Edge;                                                                                     //Edge struct

struct CompareEdge                                                                         //Simu Function
{
public:
    bool operator() (const Edge& a, const Edge& b) const
    {
        return a.cost > b.cost;
    }
};

class MST
{
public:
    MST();
    ~MST();
    void initGraph();                                                                      //Initiate graph
    UINT generateMST();                                                                    //Generate the MST, return its cost

    void print_MST();                                                                      //Print the edge list
private:
    UnionFind *union_find;                                                                 //UnionFind class

    std::priority_queue<Edge, std::vector<Edge>, CompareEdge> edge_list;                   //Vector to store all the edges in graph
    std::vector<Edge> minimum_spanning_tree;                                               //Store all edges in the MST

    UINT total_vertices;                                                                   //Total vertices in graph
};
