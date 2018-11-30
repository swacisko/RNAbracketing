/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ResultProcessor.cpp
 * Author: sylwester
 * 
 * Created on November 18, 2018, 12:58 AM
 */

#include "ResultProcessor.h"
#include "InputProcessor.h"

ResultProcessor::ResultProcessor(VI & ends, VVI sequenceOfMaxIS) {
    this->ends = ends;
    this->sequenceOfMaxIS = sequenceOfMaxIS;
    
    createBrackets();
}

ResultProcessor::ResultProcessor(const ResultProcessor& orig) {
}

ResultProcessor::~ResultProcessor() {
    clear();
}

void ResultProcessor::clear() {
    ends.clear();
    sequenceOfMaxIS.clear();
    brackets.clear();
}


void ResultProcessor::createBrackets() {
    
    brackets.push_back({ '(',')' });
    brackets.push_back({ '[',']' });
    brackets.push_back({ '{','}' });
    brackets.push_back({ '<','>' });
    for( int i=0; i<25; i++ ){
        brackets.push_back({ (char)( 'A' + i ), (char)('a'+i) });
    }
    
    /*for( int i=1; i<=5; i++ ){
        for( int k=i+1; k<=9; k++ ){
            brackets.push_back( pair<int,int>( 10*i+k, 10*k+i ) );
        }
    }*/
}


string ResultProcessor::getAnswer() {
    string res( ends.size(), 'X' );    
    
    int p = 0;
    for( int i=0; i<ends.size(); i++ ){
        if( ends[i] > i ) p++;
    }    
    
    VI bracketType(p);
    for( int i=0; i<sequenceOfMaxIS.size(); i++ ){
        for( int a : sequenceOfMaxIS[i] ){            
            bracketType[a] = i;
        }
    }
    
    p = 0;
    for( int i=0; i<ends.size(); i++ ){
        if( ends[i] > i ){
            res[i] = brackets[ bracketType[p] ].first;
            res[ ends[i] ] = brackets[ bracketType[p] ].second;
            p++;
        }
    }
    
    res.erase( res.begin() );
    return res;
}
