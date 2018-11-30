/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LongestPathCreator.cpp
 * Author: sylwester
 * 
 * Created on November 17, 2018, 3:54 PM
 */

#include "LongestPathCreator.h"
#include "Graph.h"
#include "TopoSort.h"

LongestPathCreator::LongestPathCreator(Graph & G, VB presentVertices) {
    this->G = &G;
    this->presentVertices = presentVertices;
    maxPathLength = VI(G.size(),0);
    numberOfMaxPaths = VI(G.size(),1);
    prevOnLongestPaths = VVI( G.size() );
    createLongestPathsData();
}

/*LongestPathCreator::LongestPathCreator(const LongestPathCreator& orig) {
}*/

LongestPathCreator::~LongestPathCreator() {
    clear();
    
}

void LongestPathCreator::clear() {
    presentVertices.clear();
    numberOfMaxPaths.clear();
    maxPathLength.clear();  
    prevOnLongestPaths.clear();
    topologicalOrder.clear();
    G = 0;
}


int LongestPathCreator::getNumberOfLongestPaths() {
    if( noOfLongestPaths != -1 ) return noOfLongestPaths;
    if( maxPthLength < 0 ) for( int i=0; i<G->size(); i++ ) if( presentVertices[i] && maxPthLength < maxPathLength[i] ) maxPthLength = maxPathLength[i];
    int res = 0;
    for( int i=0; i<numberOfMaxPaths.size(); i++ ){
        if( presentVertices[i] && maxPathLength[i] == maxPthLength ) res += numberOfMaxPaths[i];
    }
    noOfLongestPaths = res;
    return res;
}



VI LongestPathCreator::getKthLongestPath(int K) {
    if( K < 0 || K > noOfLongestPaths ) return VI();
    int p = topologicalOrder.size()-1;
    VI path;
    while( p >= 0 ){
        int b = topologicalOrder[p];
        if( maxPathLength[b] == maxPthLength ){
            if( numberOfMaxPaths[b] >= K ){
                path.push_back(b);
                break;
            }
            else K -= numberOfMaxPaths[b];
        }
        p--;        
    }
        
    int b = topologicalOrder[p];
    int a;
    
    while( K > 0 ){
        
        if( prevOnLongestPaths[b].empty() ) break;
        for( int i=0; i<prevOnLongestPaths[b].size(); i++ ){
            a = prevOnLongestPaths[b][i];
            if( numberOfMaxPaths[a] >= K ){
                path.push_back(a);
                break;
            }else K -= numberOfMaxPaths[a];
        }
        
        b = a;
    }
    
    reverse( path.begin(), path.end() );
    return path;    
}


void LongestPathCreator::createTopologicalOrder() {
    TopoSort ts(*G, presentVertices);
    topologicalOrder = ts.getVertexOrder();
}



void LongestPathCreator::createLongestPathsValues() {
    for( int i=0; i<topologicalOrder.size(); i++ ){
        int a = topologicalOrder[i];
        if( !presentVertices[a] ) continue;
        for( int k=0; k < (*G)[a].size(); k++ ){
            int b = (*G)[a][k];
            if( !presentVertices[b] ) continue;
            
            if( maxPathLength[a] >= maxPathLength[b] ){
                maxPathLength[b] = 1 + maxPathLength[a];
                numberOfMaxPaths[b] = numberOfMaxPaths[a];
                prevOnLongestPaths[b].clear();
                prevOnLongestPaths[b].push_back(a);
            }else if( maxPathLength[a] + 1 == maxPathLength[b] ){
                numberOfMaxPaths[b] += numberOfMaxPaths[a];
                prevOnLongestPaths[b].push_back(a);
            }            
        }
    }
}


void LongestPathCreator::createLongestPathsData() {
    createTopologicalOrder();
    createLongestPathsValues();
    getNumberOfLongestPaths(); // this is to check the number of longest paths.
}

void LongestPathCreator::write() {
    cout << "longest path length: " << maxPthLength << endl;
    cout << "number of longest paths: " << noOfLongestPaths << endl;
    cout << "maxPathLength vector:" << endl; for( int a : maxPathLength ) cout << a << " "; cout << endl;
    cout << "numberOfMaxPaths vector:" << endl; for( int a : numberOfMaxPaths ) cout << a << " "; cout << endl;
}