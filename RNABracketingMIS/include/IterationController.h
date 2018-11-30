/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IterationController.h
 * Author: sylwester
 *
 * Created on November 17, 2018, 9:50 PM
 */

#ifndef ITERATIONCONTROLLER_H
#define ITERATIONCONTROLLER_H

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

#include "Graph.h"
#include "GlobalParams.h"
#include "IterationGraph.h"
#include<set>

typedef vector<int> VI;
typedef vector< VI > VVI;
typedef vector<bool> VB;

/**
 * Class responsible for conducting iterations. In each iteration for each IterationGraph IG stored we will seek a longest path P. We remove P from IG and store the resulting graph.
 * From all the resulting graphs we will store only GlobalParams::
 */
class IterationController {
public:
    IterationController( Graph & G, VB presentVertices ); // G is the initial graph;
    IterationController(const IterationController& orig);
    virtual ~IterationController();
    
    void startIterations();
    void clear();
    
    VVI getMaxIndSets(){ return MaxIndSets; }
    
private:
    Graph* G;
    int iteration;
    int verticesMarkedInG;
    
    VVI MaxIndSets; // vector of maximal independent set, that form together a cover of G.
    vector< IterationGraph > currentIterationGraphs;
    set< IterationGraph > nextIterationGraphs;
    
    void nextIteration();
    void addInitialGraph(VB presentVertices);
    
};

#endif /* ITERATIONCONTROLLER_H */

