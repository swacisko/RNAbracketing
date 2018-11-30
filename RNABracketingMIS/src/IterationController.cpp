/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IterationController.cpp
 * Author: sylwester
 * 
 * Created on November 17, 2018, 9:50 PM
 */

#include "IterationController.h"
#include "MIS.h"

IterationController::IterationController(Graph &G, VB presentVertices) :iteration(0), verticesMarkedInG(0) {
    this->G = &G;
    addInitialGraph(presentVertices);
}

/*IterationController::IterationController(const IterationController& orig) {
}*/

IterationController::~IterationController() {
    clear();
}


void IterationController::nextIteration() {
    
    int p = 0;
    while( p < GlobalParams::SEARCHES_PER_ITERATION ){
        IterationGraph ig = currentIterationGraphs[ p % currentIterationGraphs.size() ];
        VI maxIS = MIS( *G,ig.getPresentVertices() ).searchForMaxIS( GlobalParams::RANDOM_MIS_PER_MAXIS );
        
        
        
        ig.addMaxISToSequence(maxIS);
        ig.calculateMaxISsize();                
        nextIterationGraphs.insert( ig );
        
      //  cout << "p = " << p << " maxIS = "; for(int a : maxIS) cout << a << " ";  cout << "      ig.maxIS = " << ig.getMaxISsize() << "    nextIterGr.size() = " << nextIterationGraphs.size() << endl;
        
        if( nextIterationGraphs.size() > GlobalParams::MAX_STORE_SIZE ) nextIterationGraphs.erase( nextIterationGraphs.begin() );
        
        p++;
    }
//    cout << "nextIterationGraphs.size() = " << nextIterationGraphs.size() << endl;
    currentIterationGraphs.clear();
    currentIterationGraphs.insert( currentIterationGraphs.begin(), nextIterationGraphs.begin(), nextIterationGraphs.end() );
    nextIterationGraphs.clear();
    
    iteration++;
}

void IterationController::addInitialGraph(VB presentVertices) {
    currentIterationGraphs.push_back( IterationGraph( *G, presentVertices ) );
    for( bool b : presentVertices ) if(b) verticesMarkedInG++;
}


void IterationController::clear() {
    G = 0;
    currentIterationGraphs.clear();
    nextIterationGraphs.clear();
}

void IterationController::startIterations() {
    int numberOfRemovedVertices = 0;
    
    
    do{
        nextIteration();
      //  cout << "after iteration no. " << iteration << " i have following " << currentIterationGraphs.size() << " graphs:" << endl;
    /*    for( IterationGraph ig : currentIterationGraphs ){
            ig.write();
            cout << endl;
        }*/
        IterationGraph *ig = &currentIterationGraphs[0];
        numberOfRemovedVertices = 0;
        for( VI v : ig->getSequnceOfMaxIS() ) numberOfRemovedVertices += v.size();
    }
    while( numberOfRemovedVertices < verticesMarkedInG );
        
    MaxIndSets = currentIterationGraphs[0].getSequnceOfMaxIS();
    
}
