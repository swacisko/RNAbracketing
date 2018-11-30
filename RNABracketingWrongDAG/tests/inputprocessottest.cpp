/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   inputprocessottest.cpp
 * Author: sylwester
 *
 * Created on November 17, 2018, 4:44 PM
 */

#include <stdlib.h>
#include <iostream>

#include "InputProcessor.h"
#include "InputReader.h"
#include "Graph.h"
/*
 * Simple C++ Test Suite
 */

void test1() {
    std::cout << "inputprocessottest test 1" << std::endl;
    
    InputProcessor ip;
    
    int N = 16;
    //int test[] = { 0,6,5,8,9,2,1,10,3,4,7 };
    int test[] = { 0, 15,7,12,9,0,8,2,6,4,0,14,3,0,11,1 };
    
    VI tab( test, test+N );
    cout << "bracket ends: " << endl;
    REP(i,tab.size()) cout << tab[i] << " "; cout << endl;
    
    VI numbering = ip.getBracketNumbering(tab);
    cout << "bracket numbering:" << endl;
    REP(i,numbering.size()) cout << numbering[i] << " "; cout << endl;
    
    Graph G = ip.processInput(tab);
    G.write();
    
}

void test2() {
    std::cout << "inputprocessottest test 2" << std::endl;
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% inputprocessottest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (inputprocessottest)" << std::endl;
    test1();
    std::cout << "%TEST_FINISHED% time=0 test1 (inputprocessottest)" << std::endl;

    std::cout << "%TEST_STARTED% test2 (inputprocessottest)\n" << std::endl;
    test2();
    std::cout << "%TEST_FINISHED% time=0 test2 (inputprocessottest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

