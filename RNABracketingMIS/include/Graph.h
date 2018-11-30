/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Graph.h
 * Author: sylwester
 *
 * Created on November 17, 2018, 3:58 PM
 */

#ifndef GRAPH_H
#define GRAPH_H

#include<iostream>
using namespace std;
#include<vector>

#define REP(i,N) for(int i=0; i<N; i++)
typedef vector<int> VI;
typedef vector< VI > VVI;
typedef vector<bool> VB;



class Graph {
public:
    Graph(int N);
    Graph(const Graph& orig);
    virtual ~Graph();
    
    VI& operator[](int a){ return V[a]; }
    VVI::iterator begin(){ return V.begin(); }
    VVI::iterator end(){ return V.end(); }
    int size(){ return V.size(); }
    void clear(){ V.clear(); }
    void push_back( VI row ){ V.push_back(row); }
    void pop_back(){ V.pop_back(); }
    
    void write();
    
    
private:
    
    VVI V;

};

#endif /* GRAPH_H */

