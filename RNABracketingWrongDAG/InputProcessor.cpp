/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   InputProcessor.cpp
 * Author: sylwester
 * 
 * Created on November 17, 2018, 3:56 PM
 */

#include <algorithm>

#include "InputProcessor.h"
#include "Graph.h"

InputProcessor::InputProcessor() {
}

InputProcessor::InputProcessor(const InputProcessor& orig) {
}

InputProcessor::~InputProcessor() {
    bracketNumbering.clear();
}

VI InputProcessor::getBracketNumbering(VI& bracketEnds) {    
    VI *V = &bracketEnds;
    int N = bracketEnds.size();
    
    VI tab(N,-1); 
    int count = 0;
    for( int i=1; i<N; i++ ){
        if( (*V)[i] != 0 ){
            if( (*V)[i] > i ) tab[i] = count++;
            else if( (*V)[i] < i ) tab[i] = tab[ (*V)[i] ];
        }
    }
    bracketNumbering = tab;
    tab.clear();
    return bracketNumbering;
}


Graph InputProcessor::processInput(VI & bracketEnds ) {
    bracketNumbering = getBracketNumbering(bracketEnds);
    
    numberOfBrackets = *max_element( bracketNumbering.begin(), bracketNumbering.end() ) + 1; // number of brackets
    
    Graph G(numberOfBrackets);
    int N = bracketEnds.size();
    for(int i=0; i<N; i++){
        if( bracketEnds[i] > 0 && bracketEnds[i] < i ){
            for( int k=i+1; k<N; k++ ){
                if( bracketEnds[k] > 0 && ( bracketEnds[k] > k || bracketEnds[k] < bracketEnds[i] )  ){                    
                    G[ bracketNumbering[i] ].push_back( bracketNumbering[k] );  
                    
                  //  if( bracketEnds[k] < bracketEnds[i] ) break;
                }
            }            
        }
    }
    
    G.push_back(VI());
    for( int i=0; i<G.size()-1; i++ ) G[i].push_back( G.size()-1 ); // I add extra node so that every longest path always end in this node.
    
    
    
    return G;    
}
