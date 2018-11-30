/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RandomBracketingGenerator.cpp
 * Author: sylwester
 * 
 * Created on November 18, 2018, 12:45 AM
 */

#include "RandomBracketingGenerator.h"

RandomBracketingGenerator::RandomBracketingGenerator() {
}

RandomBracketingGenerator::RandomBracketingGenerator(const RandomBracketingGenerator& orig) {
}

RandomBracketingGenerator::~RandomBracketingGenerator() {
}

void RandomBracketingGenerator::generateRandomBracketing(int N, int M) {
    VI tab(N);
    for(int i=0; i<N; i++) tab[i] = i+1;
    random_shuffle( tab.begin(), tab.end() );
    
    M = min( M, N/2 );    
    VI ends(N+1,0);
    for(int i=0; i<M; i++){
        int a = tab[2*i];
        int b = tab[2*i+1];
        if( a > b ) swap(a,b);
        ends[a] = b;
        ends[b] = a;
    }
    
    cout << N << endl;
    for(int i=1; i<=N; i++){
        if( i > 1 ) cout << " ";
        cout << ends[i];        
    }
    cout << endl;
}

