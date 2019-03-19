/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IterationGraph.h
 * Author: sylwester
 *
 * Created on November 19, 2018, 11:05 PM
 */

#ifndef ITERATIONGRAPH_H
#define ITERATIONGRAPH_H

#include "Graph.h"

typedef vector<bool> VB;

class IterationGraph {
public:
    IterationGraph(Graph & G, VB presentVertices);
    virtual ~IterationGraph();
    
    bool operator<( const IterationGraph & oth )const;
    int getMaxISsize(){ return MaxISsize; }
    
    VVI getSequnceOfMaxIS(){ return sequenceOfMaxIS; }
    VB getPresentVertices(){return presentVertices;}
    void clear();
    void addMaxISToSequence( VI maxIS );
    void write();
    int calculateMaxISsize() ;
    
private:
    
    
    int MaxISsize = -1;
    int hash = -1;
    Graph * G;
    VB presentVertices;
    VVI sequenceOfMaxIS;
    
    static bool compareVectorSizes( const VI & a, const VI & b ){ return a.size() < b.size(); }
    
};

#endif /* ITERATIONGRAPH_H */

