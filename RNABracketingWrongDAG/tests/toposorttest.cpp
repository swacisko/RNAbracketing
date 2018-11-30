/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newsimpletest.cpp
 * Author: sylwester
 *
 * Created on November 17, 2018, 6:46 PM
 */

#include <stdlib.h>
#include <iostream>
#include "InputProcessor.h"
#include "Graph.h"
#include "TopoSort.h"
using namespace std;

/*
 * Simple C++ Test Suite
 */

void test1() {
    std::cout << "newsimpletest test 1" << std::endl;
    
    InputProcessor ip;
    int N = 16;
    //int test[] = { 0,6,5,8,9,2,1,10,3,4,7 };
    int test[] = { 0, 15,7,12,9,0,8,2,6,4,0,14,3,0,11,1 };
    
    VI tab( test, test+N );
    
    Graph G = ip.processInput(tab);
    G.write();
    
    VB present(N,true);
    TopoSort ts(G,present);
    VI order = ts.getVertexOrder();
    
    cout << "Topological order:" << endl;
    for( int i=0; i<order.size(); i++ ) cout << order[i] << " "; cout << endl;
}

void test2() {
    std::cout << "newsimpletest test 2" << std::endl;
    InputProcessor ip;
    int N = 16;
    //int test[] = { 0,6,5,8,9,2,1,10,3,4,7 };
    int test[] = { 0, 15,7,12,9,0,8,2,6,4,0,14,3,0,11,1 };
    
    VI tab( test, test+N );
    
    Graph G = ip.processInput(tab);
    G.write();
    
    VB present(N,true);
    present[1] = present[5] = present[0] = false;
    TopoSort ts(G,present);
    VI order = ts.getVertexOrder();
    
    cout << "Topological order:" << endl;
    for( int i=0; i<order.size(); i++ ) cout << order[i] << " "; cout << endl;
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% newsimpletest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (newsimpletest)" << std::endl;
    test1();
    std::cout << "%TEST_FINISHED% time=0 test1 (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% test2 (newsimpletest)\n" << std::endl;
    test2();
    std::cout << "%TEST_FINISHED% time=0 test2 (newsimpletest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

