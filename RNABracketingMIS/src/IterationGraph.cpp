/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IterationGraph.cpp
 * Author: sylwester
 * 
 * Created on November 19, 2018, 11:05 PM
 */

#include "IterationGraph.h"
#include "MIS.h"
#include "GlobalParams.h"

IterationGraph::IterationGraph(Graph & G, VB presentVertices) {
    this->G = &G;
    this->presentVertices = presentVertices;
    calculateMaxISsize();
}


IterationGraph::~IterationGraph() {
    clear();
}

void IterationGraph::clear() {
    presentVertices.clear();
    sequenceOfMaxIS.clear();
}



int IterationGraph::calculateMaxISsize() {
    VI foundMaxIS = MIS(*G, presentVertices).searchForMaxIS( GlobalParams::SEARCHES_PER_ITERATION_GEN2 );
    MaxISsize = foundMaxIS.size();
    
    hash = 0;
    int B = 17;
    int P = 10000001;
    sort( foundMaxIS.begin(), foundMaxIS.end() );
    for( int a : foundMaxIS ){
        hash *= B;
        hash += a;
        hash %= P;
    }
    return MaxISsize;
}

void IterationGraph::addMaxISToSequence(VI maxIS) {
    sequenceOfMaxIS.push_back( maxIS );
    sort( sequenceOfMaxIS.rbegin(), sequenceOfMaxIS.rend(), compareVectorSizes );
    for( int a : maxIS ) presentVertices[a] = false;
}

void IterationGraph::write() {
    cout << "presentVertices:" << endl; for(int a : presentVertices) cout << a << " "; cout << endl;
    cout << "sequenceOfMaxIS:" << endl;
    for( int i=0; i< sequenceOfMaxIS.size(); i++ ){
        cout << i << "-th MaxIS:\t"; for( int a : sequenceOfMaxIS[i] ) cout << a << " ";
        cout << endl;
    }
    cout << "presumableMaxIs size:\t" << MaxISsize << endl;
    cout << endl;
}


bool IterationGraph::operator<( const IterationGraph& oth) const {
  //  if( MaxISsize == -1 ) calculateMaxISsize();
  //  if( oth.MaxISsize == -1 ) oth.calculateMaxISsize();
    if( MaxISsize < oth.MaxISsize ) return true;
    else if( MaxISsize > oth.MaxISsize ) return false;
    else return hash < oth.hash;
}
