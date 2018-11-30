/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TopoSort.cpp
 * Author: sylwester
 * 
 * Created on November 17, 2018, 6:20 PM
 */

#include "TopoSort.h"

TopoSort::TopoSort(Graph &G, VB & presentVertices ) {
    this->G = &G;
    this->presentVertices = presentVertices;
    calculateVertexOrder();
}

TopoSort::TopoSort(const TopoSort& orig) {
}

TopoSort::~TopoSort() {
    order.clear();
    presentVertices.clear();
    G = 0;
    inDegree.clear();
}

void TopoSort::createInDegree() {
    inDegree = VI( G->size(),0 );
    for( int i=0; i<G->size(); i++ ){
        if( presentVertices[i] ){
            for( int k=0; k<(*G)[i].size(); k++ ){
                int neigh = (*G)[i][k];
                if( presentVertices[neigh] ){
                    inDegree[neigh]++;
                }
            }
        }
    }
}


void TopoSort::toposortDfs(int num) {
    order.push_back(num);
    for( int i=0; i<(*G)[num].size(); i++ ){
        int neigh = (*G)[num][i];
        if( presentVertices[neigh] ) inDegree[neigh]--;
    }
    for( int i=0; i<(*G)[num].size(); i++ ){
        int neigh = (*G)[num][i];
        if( presentVertices[neigh] && inDegree[neigh] == 0 ) toposortDfs(neigh);
    }
    inDegree[num]--;
}



void TopoSort::calculateVertexOrder() {
    createInDegree();
    for( int i=0; i<G->size(); i++ ){
        if( presentVertices[i] && inDegree[i] == 0 ){
            toposortDfs(i);
        }
    }
}

VI& TopoSort::getVertexOrder() {
    return order;
}
