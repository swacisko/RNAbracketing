/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   InputReader.cpp
 * Author: sylwester
 * 
 * Created on November 17, 2018, 3:48 PM
 */

#include "InputReader.h"

InputReader::InputReader() {
}

InputReader::InputReader(const InputReader& orig) {
}

InputReader::~InputReader() {
}

VI InputReader::readInput() {
    int N; // N is the length of the sequence. The sequence must have its first index with 1
    cin >> N;
    VI V(N+1,0);
    for(int i=0; i<N; i++) cin >> V[i+1];
    return V;    
}

