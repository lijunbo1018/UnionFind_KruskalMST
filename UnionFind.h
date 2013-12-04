#pragma once

typedef unsigned int UINT;

class UnionFind
{
public:
    explicit UnionFind(UINT size);
    ~UnionFind();
    int Union(UINT p, UINT q);                               //Connect two elements
    bool isConnected(UINT p, UINT q);                        //Check whether two elements is connected
    UINT getSubsetsNum();                                    //Return subsets in this union
private:
    UINT Root(UINT p);                                       //Find elements p's root

    UINT elements;                                           //Total elements in this union
    UINT subsets;                                            //Subsets remain in this union
    UINT *relation;                                          //Parent of each element
    UINT *weight;                                            //Total elements under each element
};
