/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newsimpletest.cpp
 * Author: sylwester
 *
 * Created on November 18, 2018, 12:51 AM
 */

#include <stdlib.h>
#include <iostream>

#include "RandomBracketingGenerator.h"

/*
 * Simple C++ Test Suite
 */

void test1() {
    std::cout << "newsimpletest test 1" << std::endl;
    
    int N = 1200;
    int M = 500;
    RandomBracketingGenerator::generateRandomBracketing(N,M);
}

void test2() {
    std::cout << "newsimpletest test 2" << std::endl;
}

int main(int argc, char** argv) {
    srand( unsigned(time(0)) );
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

