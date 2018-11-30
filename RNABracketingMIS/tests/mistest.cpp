/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mistest.cpp
 * Author: sylwester
 *
 * Created on November 19, 2018, 9:51 PM
 */

#include <stdlib.h>
#include <iostream>
#include "MIS.h"
#include "InputProcessor.h"
#include "InputReader.h"

/*
 * Simple C++ Test Suite
 */

void test1() {
    std::cout << "mistest test 1" << std::endl;
    InputReader reader;
    VI ends = reader.readInput();
    InputProcessor proc;    
    Graph G = proc.processInput(ends);
    MIS mis(G, VB(ends.size(),true));
    
    VI rMIS = mis.getRandomIS( MIS::MIS_MODE );
    cout << "random IS:" << endl; for(int a : rMIS) cout << a << " "; cout << endl;
    
    VI clique = mis.getRandomIS( MIS::CLIQUE_MODE );
    cout << "random maximal clique:" << endl; for(int a : clique) cout << a << " "; cout << endl;
    
    rMIS = mis.searchForMaxIS( 10*G.size(), MIS::MIS_MODE );
    cout << "found MaxIS:" << endl; for(int a : rMIS) cout << a << " "; cout << endl;
    
    clique = mis.searchForMaxIS( 10*G.size(), MIS::CLIQUE_MODE );
    cout << "best found maximal clique:" << endl; for(int a : clique) cout << a << " "; cout << endl;
    
}

void test2() {
    std::cout << "mistest test 2" << std::endl;
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% mistest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (mistest)" << std::endl;
    test1();
    std::cout << "%TEST_FINISHED% time=0 test1 (mistest)" << std::endl;

    std::cout << "%TEST_STARTED% test2 (mistest)\n" << std::endl;
    test2();
    std::cout << "%TEST_FINISHED% time=0 test2 (mistest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

