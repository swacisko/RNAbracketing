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
}

Graph::Graph(const Graph& orig) {
    V = orig.V;
}

Graph::~Graph() {
    clear();
}

void Graph::write() {
    cout << "size = " << size() << endl;
    REP(i,size()){
        cout << i << ":\t";
        REP(k, V[i].size() ) cout << V[i][k] << " ";
        cout << endl;
    }
}


