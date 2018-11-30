/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GlobalIterator.cpp
 * Author: sylwester
 * 
 * Created on November 21, 2018, 12:52 PM
 */

#include "GlobalIterator.h"
#include "IterationController.h"
#include "GraphConnectedComponents.h"
#include "DisjointComponentMerger.h"

GlobalIterator::GlobalIterator(Graph & G) {
    this->G = &G;
    createConnectedComponents();
}

GlobalIterator::GlobalIterator(const GlobalIterator& orig) {
}

GlobalIterator::~GlobalIterator() {
    clear();
}

void GlobalIterator::clear() {
    graphComponents.clear();
    bestAnsPerComponent.clear();
}


void GlobalIterator::compareToBestAnswer(int comp, VVI & oth) {
    if( bestAnsPerComponent[comp].empty() ) bestAnsPerComponent[comp] = oth;
    else{
        
        int m = min( bestAnsPerComponent[comp].size(), oth.size() );
        for( int i=0; i<m; i++ ){
            if( bestAnsPerComponent[comp][i].size() < oth[i].size() ){
                bestAnsPerComponent[comp] = oth;
                return;
            }
            else if( bestAnsPerComponent[comp][i].size() > oth[i].size() ) return;
        }
    }
}

void GlobalIterator::createConnectedComponents() {
    GraphConnectedComponents connector(*G);
    graphComponents = connector.getConnectedComponents();
    bestAnsPerComponent = VVVI( graphComponents.size() );
    
    cout << "connected components sizes:\t"; for( VI V : graphComponents ) cerr << V.size() << " "; cerr << endl;
   /* for( VI v : graphComponents ){
        for(int a : v) cerr << a << " ";
        cerr << endl;
    }*/
}

VVI GlobalIterator::getBestAnswer() {
    DisjointComponentMerger merger;
    VVVI brackets;
    for( VVI V : bestAnsPerComponent ) brackets.push_back(V);
    return merger.mergeBracketsFromComponents(brackets);
}

bool GlobalIterator::checkForSmallComponent(int comp) {
    if( graphComponents[comp].size() <= 2 ){
        for( int a : graphComponents[comp] ) bestAnsPerComponent[comp].push_back( VI(1,a) );
        return true;
    }else if( graphComponents[comp].size() == 3 ){
        int a = graphComponents[comp][0];
        int b = graphComponents[comp][1];
        int c = graphComponents[comp][2];
        if( (*G)[a].size() == 2 && (*G)[b].size() == 2 && (*G)[c].size() == 2 ){
            for( int a : graphComponents[comp] ) bestAnsPerComponent[comp].push_back( VI(1,a) );
        } 
        else{ // component is a path on 3 vertices
            if( (*G)[a].size() == 2 ){
                VI B(2); B[0] = b; B[1] = c;
                bestAnsPerComponent[comp].push_back( B );
                bestAnsPerComponent[comp].push_back( VI(1,a) );                
            }else if( (*G)[b].size() == 2 ){
                VI B(2); B[0] = a; B[1] = c;
                bestAnsPerComponent[comp].push_back( B );
                bestAnsPerComponent[comp].push_back( VI(1,b) );
            }else{
                VI B(2); B[0] = a; B[1] = b;
                bestAnsPerComponent[comp].push_back( B );
                bestAnsPerComponent[comp].push_back( VI(1,c) );
            }
        }
        return true;
    }
    
    return false;
    
}


void GlobalIterator::startIterationForComponent(int comp, int iterations) {
 //   cerr << "Present vertices in component:\t"; for( int a : graphComponents[comp] ) cerr << a << " "; cerr << endl;
    if( checkForSmallComponent( comp ) ) return;
    
    VB presentVerticesInComponent( G->size(), false );
    for( int a : graphComponents[comp] ) presentVerticesInComponent[a] = true;
    
    
    
    for( int i=0; i<iterations; i++ ){
        IterationController controller(*G, presentVerticesInComponent);
        controller.startIterations();
        VVI newMaxIS = controller.getMaxIndSets();
        
        
   //     cerr << "best so far:\t"; for(VI v : bestAnsPerComponent[comp]) cerr << v.size() << " "; cerr << endl;
   //     cerr << "new found:\t"; for(VI v : newMaxIS) cerr << v.size() << " "; cerr << endl;
        
        compareToBestAnswer( comp, newMaxIS );
        
    //    cerr << "After " << i << "iterations best MaxIS found so far:\t\t"; for(VI v : bestAnsPerComponent[comp]) cerr << v.size() << " "; cerr << endl;
        
        
        double factor = 1.05;
        GlobalParams::MAX_STORE_SIZE = (int)( ceil( (float)GlobalParams::MAX_STORE_SIZE * factor ) );
        GlobalParams::RANDOM_MIS_PER_MAXIS = (int)( ceil( (float)GlobalParams::RANDOM_MIS_PER_MAXIS * factor ) );
        GlobalParams::SEARCHES_PER_ITERATION = (int)( ceil( (float)GlobalParams::SEARCHES_PER_ITERATION * factor ) );
        GlobalParams::SEARCHES_PER_ITERATION_GEN2 = (int)( ceil( (float)GlobalParams::SEARCHES_PER_ITERATION_GEN2 * factor ) );        
    }
    
    GlobalParams::resetParams();
}


void GlobalIterator::startIterations( int iterations) {
    for( int i=0; i<graphComponents.size(); i++ ) {
     //   cerr << endl << endl << endl << "CONSIDERING COMPONENT " << i << endl;
        startIterationForComponent(i,iterations);
     //   cerr << "best for component:" << endl;
     //   WRITE2( bestAnsPerComponent[i] );
    }
    
}

