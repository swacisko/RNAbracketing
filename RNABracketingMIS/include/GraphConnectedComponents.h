/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GraphConnectedComponents.h
 * Author: sylwester
 *
 * Created on November 21, 2018, 2:41 PM
 */

#ifndef GRAPHCONNECTEDCOMPONENTS_H
#define GRAPHCONNECTEDCOMPONENTS_H

#include "Graph.h"

class GraphConnectedComponents {
public:
    GraphConnectedComponents(Graph & G);
    GraphConnectedComponents(const GraphConnectedComponents& orig);
    virtual ~GraphConnectedComponents();
    
    VVI getConnectedComponents();
    
private:
    Graph * G;
    VB was;
    VVI components;
    
    void markComponent(int num);
};

#endif /* GRAPHCONNECTEDCOMPONENTS_H */

