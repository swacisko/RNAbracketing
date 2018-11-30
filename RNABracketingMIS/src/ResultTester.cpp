/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ResultTester.cpp
 * Author: sylwester
 * 
 * Created on November 21, 2018, 4:18 PM
 */

#include "ResultTester.h"

ResultTester::ResultTester() {
}

ResultTester::ResultTester(const ResultTester& orig) {
}

ResultTester::~ResultTester() {
}

bool ResultTester::isCorrect(Graph& G, VVI& brackets) {
    set< pair<int,int> > edges;
    
    for( int i=0; i<G.size(); i++ ){
        for( int a : G[i] ){
            if( i < a ) edges.insert( {i,a} );
        }
    }
    
   // cerr << "edges" << endl;
  //  for( auto a : edges ) cerr << a.first << " " << a.second << endl;
    
    for( VI V : brackets ){
        for( int a : V ){
            for( int b : V ){
                if( a < b && edges.count( {a,b} ) ) return false;
            }
        }
    }
    
    return true;
}

