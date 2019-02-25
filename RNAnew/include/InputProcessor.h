/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   InputProcessor.h
 * Author: sylwester
 *
 * Created on November 17, 2018, 3:56 PM
 */

#ifndef INPUTPROCESSOR_H
#define INPUTPROCESSOR_H

#include<vector>
using namespace std;
typedef vector<int> VI;
typedef vector< VI > VVI;

class Graph;

class InputProcessor {
public:
    InputProcessor();
    InputProcessor(const InputProcessor& orig);
    virtual ~InputProcessor();
    
    /**
     * 
     * @param tab array as returned by InputReader. tab[i] is the index matched with i.
     * @return graph in which two vertices are adjacent if corresponding arches are intersecting. We will find MaxIS in that graph.
     */
    Graph processInput( VI & bracketEnds );
    
    /**
     * 
     * @param bracketEnds
     * @return array tab such that tab[i] containt the number of bracket with its end in i. Brackets are numbered from 0.
     */
    VI getBracketNumbering( VI & bracketEnds );
private:
    
    VI bracketNumbering;
    int numberOfBrackets;

};

#endif /* INPUTPROCESSOR_H */

