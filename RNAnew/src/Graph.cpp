/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Graph.cpp
 * Author: sylwester
 * 
 * Created on November 17, 2018, 3:58 PM
 */

#include "Graph.h"

Graph::Graph(int N) {
    V = VVI(N);
    L = VI(N,N+1);
    arcBeg = VI(N);
    arcEnd = VI(N);
}

Graph::Graph(const Graph& orig) {
    V = orig.V;
    L = orig.L;
}

Graph::~Graph() {
    clear();
}

void Graph::write() {
    cerr << "size = " << size() << endl;
    REP(i,size()){
        cerr << i << ":\t";
        REP(k, V[i].size() ) cerr << V[i][k] << " ";
        cerr << endl;
    }
}


