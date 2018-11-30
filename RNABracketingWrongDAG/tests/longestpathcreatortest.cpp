/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   longestpathcreatortest.cpp
 * Author: sylwester
 *
 * Created on November 17, 2018, 9:02 PM
 */

#include <stdlib.h>
#include <iostream>

#include "Graph.h"
#include "LongestPathCreator.h"

/*
 * Simple C++ Test Suite
 */

void test1() {
    std::cout << "longestpathcreatortest test 1" << std::endl;
    int N = 7;
    Graph G(N);
    G[0].push_back(3);
    G[1].push_back(3);
    G[2].push_back(3);
    G[3].push_back(4);
    G[3].push_back(5);
    G[4].push_back(6);
    
    G.write();
    
    VB l(N,true);
  //  l[3] = false;
    LongestPathCreator lpc(G,l);
    
    lpc.write();
    
    for( int i=1; i<=lpc.getNumberOfLongestPaths(); i++ ){
        cout << i << "-th longest path:\t\t";
        VI path = lpc.getKthLongestPath(i);
        for(int k=0; k<path.size(); k++) cout << path[k] << " ";
        cout << endl;
    }
}

void test2() {
    std::cout << "longestpathcreatortest test 2" << std::endl;
    int N = 6;
    Graph G(N);
    G[0].push_back(1);
    G[0].push_back(3);
    G[1].push_back(2);
    G[3].push_back(2);
    G[4].push_back(3);
    G[4].push_back(1);
    
    G.write();
    
    VB l(N,true);
    LongestPathCreator lpc(G,l);
    
    lpc.write();
    
    for( int i=1; i<=lpc.getNumberOfLongestPaths(); i++ ){
        cout << i << "-th longest path:\t\t";
        VI path = lpc.getKthLongestPath(i);
        for(int k=0; k<path.size(); k++) cout << path[k] << " ";
        cout << endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% longestpathcreatortest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (longestpathcreatortest)" << std::endl;
    test1();
    std::cout << "%TEST_FINISHED% time=0 test1 (longestpathcreatortest)" << std::endl;

    std::cout << "%TEST_STARTED% test2 (longestpathcreatortest)\n" << std::endl;
    test2();
    std::cout << "%TEST_FINISHED% time=0 test2 (longestpathcreatortest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

