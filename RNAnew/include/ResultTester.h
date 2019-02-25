/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ResultTester.h
 * Author: sylwester
 *
 * Created on November 21, 2018, 4:18 PM
 */

#ifndef RESULTTESTER_H
#define RESULTTESTER_H


#include "Graph.h"
#include<set>
#include <map>

class ResultTester {
public:
    ResultTester();
    ResultTester(const ResultTester& orig);
    virtual ~ResultTester();
    bool isCorrect( Graph & G, VVI & brackets );

    map<char,int> getStatsForString( string s );

    void testSolution();
private:

};

#endif /* RESULTTESTER_H */

