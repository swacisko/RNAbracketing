/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   iterationcontrollertest.cpp
 * Author: sylwester
 *
 * Created on November 17, 2018, 11:48 PM
 */


#include "IterationController.h"

/*
 * Simple C++ Test Suite
 */

void test1() {
    std::cout << "iterationcontrollertest test 1" << std::endl;
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
    
    IterationController ic(G);
    ic.startIterations();
    
}

void test2() {
    std::cout << "iterationcontrollertest test 2" << std::endl;
    
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% iterationcontrollertest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (iterationcontrollertest)" << std::endl;
    test1();
    std::cout << "%TEST_FINISHED% time=0 test1 (iterationcontrollertest)" << std::endl;

    std::cout << "%TEST_STARTED% test2 (iterationcontrollertest)\n" << std::endl;
    test2();
    std::cout << "%TEST_FINISHED% time=0 test2 (iterationcontrollertest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

