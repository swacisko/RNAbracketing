/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RandomBracketingGenerator.h
 * Author: sylwester
 *
 * Created on November 18, 2018, 12:45 AM
 */

#ifndef RANDOMBRACKETINGGENERATOR_H
#define RANDOMBRACKETINGGENERATOR_H

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

#define REP(i,N) for(int i=0; i<N; i++)
typedef vector<int> VI;
typedef vector< VI > VVI;

class RandomBracketingGenerator {
public:
    RandomBracketingGenerator();
    RandomBracketingGenerator(const RandomBracketingGenerator& orig);
    virtual ~RandomBracketingGenerator();
    
    static void generateRandomBracketing( int N, int M );
private:

};

#endif /* RANDOMBRACKETINGGENERATOR_H */

