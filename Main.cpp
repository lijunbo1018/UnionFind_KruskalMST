#include"MST.h"
#include"UnionFind.h"
#include<iostream>
using namespace std;

int main()
{
    MST minimum_spanning_tree;
    minimum_spanning_tree.initGraph();

    int MST_cost = minimum_spanning_tree.generateMST();
    if (MST_cost > 0)
    {
        cout << "The cost of this graph's MST is: " << MST_cost <<endl;
        cout << "The edges in the MST are: " << endl;
        minimum_spanning_tree.print_MST();
    }
    else
    {
        cout << "This is not a connect graph!" << endl;
    }
    return 0;
}
