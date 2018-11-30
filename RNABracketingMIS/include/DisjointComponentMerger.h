/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DisjointComponentMerger.h
 * Author: sylwester
 *
 * Created on November 21, 2018, 2:56 PM
 */

#ifndef DISJOINTCOMPONENTMERGER_H
#define DISJOINTCOMPONENTMERGER_H

#include<iostream>
using namespace std;
#include<vector>

#define REP(i,N) for(int i=0; i<N; i++)
typedef vector<int> VI;
typedef vector< VI > VVI;
typedef vector< VVI > VVVI;

class DisjointComponentMerger {
public:
    DisjointComponentMerger();
    DisjointComponentMerger(const DisjointComponentMerger& orig);
    virtual ~DisjointComponentMerger();
    
    VVI mergeBracketsFromComponents( VVVI brackets );
private:

};

#endif /* DISJOINTCOMPONENTMERGER_H */

