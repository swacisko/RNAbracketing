/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GlobalIterator.h
 * Author: sylwester
 *
 * Created on November 21, 2018, 12:52 PM
 */

#ifndef GLOBALITERATOR_H
#define GLOBALITERATOR_H

#include "Graph.h"
#include "GraphConnectedComponents.h"
#include<cmath>
#include "Makros.h"

typedef vector< VVI > VVVI;

class GlobalIterator {
public:
    GlobalIterator(Graph & G);
    GlobalIterator(const GlobalIterator& orig);
    virtual ~GlobalIterator();
    
    void clear();
    void startIterations( int iterations ); // start iterations for all components
    void startIterationForComponent( int comp, int iterations ); // starts iterations for connected components
    
    VVI getBestAnswer();
private:

    Graph * G;
    VVVI bestAnsPerComponent;
    VVI graphComponents;
    
    void compareToBestAnswer( int comp, VVI & oth );
    void createConnectedComponents();
    bool checkForSmallComponent( int comp ); // if component graphComponents[comp] has one or 2 vertices, i do not use MIS :)
};

#endif /* GLOBALITERATOR_H */

