/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MIS.cpp
 * Author: sylwester
 * 
 * Created on November 19, 2018, 9:08 PM
 */

#include <valarray>

#include "MIS.h"

MIS::MIS(Graph & G, VB presentVertices) {
    this->G = &G;
    this->presentVertices = presentVertices;
}

MIS::MIS(const MIS& orig) {
}

MIS::~MIS() {
}

VI MIS::searchForMaxIS(int iterations, int mode ) {
    VI maxIS;
    
    for( int i=0; i<iterations; i++ ){
        VI S = getRandomIS(mode);
        if( S.size() > maxIS.size() ) maxIS = S;
    }
    return maxIS;
}



VI MIS::getRandomIS(int mode ) {
    int N = G->size();
    VI perm(N);
    for(int i=0; i<N; i++) perm[i] = i;
    
    VB X(N,false);
    for( int i = 0; i<presentVertices.size(); i++ ){
        if( presentVertices[i] ) X[i] = true; // we find MIS only in the induced graph G[ presentVertices ]
    } 
    VI S;
    
    random_shuffle( perm.begin(), perm.end() );
    
    int p = 0;
    while( p < N ){
        int v = perm[p];
        if( X[v] ){
            S.push_back(v);
            removeNodesFromX(X,v,mode);
        }
        p++;        
    }    
    return S;    
}

int MIS::removeNodesFromX(VB& X, int v, int mode) {
    int removed = 0;
    
    if( X[v] ){
        X[v] = false;
        removed++;
    }
    
    if( mode == MIS_MODE ){
        for(int a : (*G)[v]){
            if( X[a] ){
                removed++;
                X[a] = false;
            }
        }
    }else{ // CLIQUE_MODE
        VB nonneigh(G->size(),true);
        for(int a :(*G)[v]) nonneigh[a] = false;
        nonneigh[v] = false;
        
        for( int i=0; i<nonneigh.size(); i++ ){
            if( nonneigh[i] && X[i] ){
                X[i] = false;
                removed++;
            }
        }
        
    }
    return removed;
}
