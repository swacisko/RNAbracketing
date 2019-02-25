/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   InputReader.h
 * Author: sylwester
 *
 * Created on November 17, 2018, 3:48 PM
 */

#ifndef INPUTREADER_H
#define INPUTREADER_H

#include<iostream>
#include<vector>
using namespace std;


typedef vector<int> VI;
typedef vector< VI > VVI;


class InputReader {
public:
    InputReader();
    InputReader(const InputReader& orig);
    virtual ~InputReader();
    
    /**
     * 
     * @return vector tab such that tab[i] is the number of the bracket that has one end with index i or -1 if no bracket has end with index i. Brackets
     * are numbered from 0.
     */
    VI readInput();
    
    string getInputSequence(){ return inputSequence; }
    
private:
    string inputSequence;
};

#endif /* INPUTREADER_H */

