/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ResultProcessor.h
 * Author: sylwester
 *
 * Created on November 18, 2018, 12:58 AM
 */

#ifndef RESULTPROCESSOR_H
#define RESULTPROCESSOR_H

#include<iostream>
using namespace std;
#include<vector>

#define REP(i,N) for(int i=0; i<N; i++)
typedef vector<int> VI;
typedef vector< VI > VVI;

class ResultProcessor {
public:
    ResultProcessor(VI & ends, VVI  sequenceOfMaxIS);
    ResultProcessor(const ResultProcessor& orig);
    virtual ~ResultProcessor();
    
    void clear();
    string getAnswer();
    
private:
    VI ends;
    VVI sequenceOfMaxIS;
    vector< pair<char,char> > brackets;

    void createBrackets();
};

#endif /* RESULTPROCESSOR_H */

