/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DisjointComponentMerger.cpp
 * Author: sylwester
 * 
 * Created on November 21, 2018, 2:56 PM
 */

#include "DisjointComponentMerger.h"

DisjointComponentMerger::DisjointComponentMerger() {
}

DisjointComponentMerger::DisjointComponentMerger(const DisjointComponentMerger& orig) {
}

DisjointComponentMerger::~DisjointComponentMerger() {
}

VVI DisjointComponentMerger::mergeBracketsFromComponents(VVVI brackets) {
    VVI res;
    for( VVI V : brackets ){
        while( V.size() > res.size() ) res.push_back( VI() );
        
        for( int i=0; i<V.size(); i++ ){
            for( int a : V[i] ) res[i].push_back(a);
        }        
    }
    return res;
}
