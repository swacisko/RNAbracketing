/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IterationGraph.h
 * Author: sylwester
 *
 * Created on November 17, 2018, 10:03 PM
 */

#ifndef ITERATIONGRAPH_H
#define ITERATIONGRAPH_H


#include<iostream>
using namespace std;
#include<vector>

#include "Graph.h"
#include "LongestPathCreator.h"

#define REP(i,N) for(int i=0; i<N; i++)
typedef vector<int> VI;
typedef vector< VI > VVI;
typedef vector<bool> VB;

/**
 * 
 * This class is a graph that will be kept in each iteration in 'priority_queue'. It is the initial graph G with given presentVertices and sequence of paths
 */
class IterationGraph {
public:
    IterationGraph(Graph & G, VB  presentVertices);
    IterationGraph(const IterationGraph& orig);
    virtual ~IterationGraph();
    
    bool operator<(  const IterationGraph& oth );
    void clear();
    VVI getSequenceOfPaths(){ return sequenceOfPaths; }
    
    /**
     * This function is useful in creating new IterationGraphs. I create a copy of this graph and only add new path to it.
     * @param path path to be added to sequence of paths.
     */
    void addPath( VI path );
    
    int getNumberOfLongestPaths(){ return lpc.getNumberOfLongestPaths(); }
    int getMaxPathLength() const { return lpc.getMaxLength(); }
    VI getKthLongestPath(int K){ return lpc.getKthLongestPath(K); }
    
    void write();
    
private:
    Graph *G;
    
    VVI sequenceOfPaths;
    VB presentVertices;
    LongestPathCreator lpc;
    
};

#endif /* ITERATIONGRAPH_H */

