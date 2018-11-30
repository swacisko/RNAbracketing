/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GraphConnectedComponents.cpp
 * Author: sylwester
 * 
 * Created on November 21, 2018, 2:41 PM
 */

#include "GraphConnectedComponents.h"

GraphConnectedComponents::GraphConnectedComponents( Graph & G ) {
    this->G = &G;
}

GraphConnectedComponents::GraphConnectedComponents(const GraphConnectedComponents& orig) {
}

GraphConnectedComponents::~GraphConnectedComponents() {
}

void GraphConnectedComponents::markComponent( int num ) {
    was[num] = true;
    components.back().push_back(num);
    for( int a : (*G)[num] ){
        if( !was[a] ) markComponent(a);
    }
}


VVI GraphConnectedComponents::getConnectedComponents() {
    int N = G->size();
    was = VB( N,false );
    for( int i=0; i<N; i++ ){
        if(!was[i]) {
            components.push_back( VI() );
            markComponent(i);
        }
    }
    return components;
}

