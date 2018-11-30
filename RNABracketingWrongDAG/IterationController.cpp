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
#include "GlobalParams.h"

IterationController::IterationController(Graph &G) : iteration(0) {
    this->G = &G;
    
    addInitialGraph();
}

/*IterationController::IterationController(const IterationController& orig) {
}*/

IterationController::~IterationController() {
    clear();
}

void IterationController::addInitialGraph() {
    VB presentVertices(G->size(),true);
    IterationGraph ig( *G, presentVertices);
    cout << "There are " << ig.getNumberOfLongestPaths() << " longest paths in initial graph" << endl;
    iterationGraphs.push_back(ig);
}

void IterationController::nextIteration() {
    int igs = iterationGraphs.size();
    
    VI jobs(igs);
    for( int i=0; i<igs; i++ ) jobs[i] = iterationGraphs[i].getNumberOfLongestPaths();
    BucketWorkflowDistributor bwd(jobs);
    
   // cout << "jobs:" << endl; for(int a : jobs) cout << a << " "; cout << endl;
  //  cout << "total jobs:\t" << bwd.getTotalNumberOfJobs() << endl;
    
    int STEP = (int)( bwd.getTotalNumberOfJobs() / GlobalParams::PATHS_PER_ITERATION );
    if( STEP < 1 ) STEP = 1;
    
    for( int i=1; i<=bwd.getTotalNumberOfJobs(); i += STEP ){
        PII jobIndex = bwd.getIndicesOfJob(i);
        IterationGraph newIG = IterationGraph( iterationGraphs[ jobIndex.first ] );
        VI path = iterationGraphs[ jobIndex.first ].getKthLongestPath( jobIndex.second ); 
        if( path.empty() ){
            cout << "empty path, i = " << i << "  jobIndex = (" << jobIndex.first << "," << jobIndex.second << ")"  << endl;
            cout << "current iteration graph:" << endl; iterationGraphs[jobIndex.first].write(); cout << endl;
            exit(0);
        }
        newIG.addPath(path);
        
        nextIterationGraphs.push_back( newIG );
        
        if( nextIterationGraphs.size() > 10*GlobalParams::MAX_ITEARTION_GRAPHS ){
            random_shuffle( nextIterationGraphs.begin(), nextIterationGraphs.end() );
            sort( nextIterationGraphs.rbegin(), nextIterationGraphs.rend() );
            while( nextIterationGraphs.size() > GlobalParams::MAX_ITEARTION_GRAPHS ){
                nextIterationGraphs.back().clear();
                nextIterationGraphs.pop_back();
            }
        }
        
    }
    
    random_shuffle( nextIterationGraphs.begin(), nextIterationGraphs.end() );
    sort( nextIterationGraphs.rbegin(), nextIterationGraphs.rend() );
    while( nextIterationGraphs.size() > GlobalParams::MAX_ITEARTION_GRAPHS ) nextIterationGraphs.pop_back();
    
    swap( iterationGraphs, nextIterationGraphs );
    nextIterationGraphs.clear();
    
    iteration++;
}

void IterationController::clear() {
    iterationGraphs.clear();
    nextIterationGraphs.clear();
    G = 0;
}

void IterationController::startIterations() {
    
    int numberOfRemovedVertices;
    
    do{
        nextIteration();
        cout << "after iteration no. " << iteration << " i have following " << iterationGraphs.size() << " graphs:" << endl;
     /*   for( IterationGraph ig : iterationGraphs ){
            ig.write();
            cout << endl;
        }*/
        IterationGraph *ig = &iterationGraphs[0];
        numberOfRemovedVertices = 0;
        for( VI v : ig->getSequenceOfPaths() ) numberOfRemovedVertices += v.size();
    }
    while( numberOfRemovedVertices < G->size() );
        
    
}
