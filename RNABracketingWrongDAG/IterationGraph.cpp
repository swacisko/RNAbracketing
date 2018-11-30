/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IterationGraph.cpp
 * Author: sylwester
 * 
 * Created on November 17, 2018, 10:03 PM
 */

#include "IterationGraph.h"

IterationGraph::IterationGraph(Graph & G, VB presentVertices) : lpc(G,presentVertices) {
    this->G = &G;
    this->presentVertices = presentVertices;
    
}

IterationGraph::IterationGraph(const IterationGraph& orig) : lpc(orig.lpc) {
    presentVertices = orig.presentVertices;
    sequenceOfPaths = orig.sequenceOfPaths;
    G = orig.G;  
}

IterationGraph::~IterationGraph() {
    clear();
}

void IterationGraph::clear() {
    sequenceOfPaths.clear();
    presentVertices.clear();
    lpc.clear();
}

void IterationGraph::write() {
    cout << sequenceOfPaths.size() << "paths:" << endl;
    for( VI v : sequenceOfPaths ){
        for( int a : v ) cout << a << " ";
        cout << endl;
    }
}

void IterationGraph::addPath(VI path) {    
    sequenceOfPaths.push_back( path );
    for( int a : path ) presentVertices[a] = false;
    lpc.clear();
    lpc = LongestPathCreator( *G, presentVertices );    
}


bool IterationGraph::operator <( const IterationGraph& oth){
    for( int i=0; i<min( sequenceOfPaths.size(), oth.sequenceOfPaths.size() ); i++ ){
        if( sequenceOfPaths[i].size() < oth.sequenceOfPaths[i].size() ) return true;
        if( sequenceOfPaths[i].size() > oth.sequenceOfPaths[i].size() ) return false;
    }
    if( sequenceOfPaths.size() < oth.sequenceOfPaths.size() ) return true;
    return getMaxPathLength() < oth.getMaxPathLength(); // in our program this should always decide due to the fact that all compared IterationGraphs will have the same sizes in sequenceOfPaths
}
