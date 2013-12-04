#include "UnionFind.h"
#include <iostream>

UnionFind::UnionFind(UINT size)
{
    //If size equals to zero, do nothing
    if (0 == size)
    {
        return ;
    }
    this->elements = size;
    this->subsets = size;
    relation = new UINT[size];
    weight = new UINT[size];
    if ((NULL != relation) && (NULL != weight))
    {
        //Each element's root is itself initially
        for (UINT i = 0; i < size; i++)
        {
            relation[i] = i;
            weight[i] = 1;
        }
    }
}

UnionFind::~UnionFind()
{
    //Release memory
    if (NULL != relation)
    {
        delete [] relation;
        relation = NULL;
    }
}

//************************************************************
// Function: Find element p's root
// Parameter: UINT p
// Return: p's root
//************************************************************
UINT UnionFind::Root(UINT p)
{
    UINT i = p, j = p;
    UINT temp = p;
    while (i != relation[i])
    {
        //Set i to i's parent
        i = relation[i];
    }
    //Set each element along the path from p to root to directly connected to root
    while (j != i)
    {
        temp = relation[j];
        relation[j] = i;
        j = temp;
    }
    return i;
}


//************************************************************
// Function: Check whethe two elements are in the same subset
// Parameter: UINT p, UINT q
// Return: true if is, false if no
//************************************************************
bool UnionFind::isConnected(UINT p, UINT q)
{
    //Invalid element
    if ((p > elements) || (q > elements))
    {
        return false;
    }
    return Root(p) == Root(q);
}


//************************************************************
// Function: Merge two elements into the same subset
// Parameter: UINT p, UINT q
// Return: 1 for success, 0 for fail
//************************************************************
int UnionFind::Union(UINT p, UINT q)
{
    //Invalid element
    if ((p > elements) || (q > elements))
    {
        return 0;
    }
    UINT pRoot = Root(p);
    UINT qRoot = Root(q);
    //Subtree pRoot is taller than subtree qRoot
    if (weight[pRoot] > weight[qRoot])
    {
        //Append subtree qRoot to pRoot
        relation[qRoot] = pRoot;
        weight[pRoot] += weight[qRoot];
    }
    else
    {
        //ApRootpRootend pRoot to qRoot
        relation[pRoot] = qRoot;
        weight[qRoot] += weight[pRoot];
    }
    subsets -= 1;
    return 1;
}

UINT UnionFind::getSubsetsNum()
{
    return this->subsets;
}
