/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TopoSort.h
 * Author: sylwester
 *
 * Created on November 17, 2018, 6:20 PM
 */

#ifndef TOPOSORT_H
#define TOPOSORT_H

#include "Graph.h"
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

#define REP(i,N) for(int i=0; i<N; i++)
typedef vector<int> VI;
typedef vector< VI > VVI;
typedef pair<int,int> PII;
typedef vector<bool> VB;



class TopoSort {
public:
    TopoSort( Graph &G, VB &presentVertices );
    TopoSort(const TopoSort& orig);
    virtual ~TopoSort();
    
    /**
     * 
     * @return vector with numbers of vertices in topological order. Here will be only included vertices that are set in presentVertices vector.
     */
    VI& getVertexOrder();
private:
    
    VI order;
    VB presentVertices; // presentVertices[i] == true if vertex number i is to be considered. Otherwise we will treat the node as though it is not in the graph
    Graph *G;
    
    VI inDegree;
    
    /**
     * 
     */
    void calculateVertexOrder();
    void toposortDfs( int num );
    void createInDegree();
};

#endif /* TOPOSORT_H */

