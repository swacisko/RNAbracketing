/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bucketworkflowtest.cpp
 * Author: sylwester
 *
 * Created on November 17, 2018, 6:09 PM
 */

#include <stdlib.h>
#include <iostream>

#include "BucketWorkflowDistributor.h"

/*
 * Simple C++ Test Suite
 */

void test1() {
    std::cout << "bucketworkflowtest test 1" << std::endl;
    
    int N = 4;
    //int test[] = { 0,6,5,8,9,2,1,10,3,4,7 };
    int test[] = { 7,2,4,5 };
    
    VI tab( test, test+N );
    
    BucketWorkflowDistributor bwd( tab );
    int SUM = 0;
    for_each( tab.begin(), tab.end(), [&](int n){ SUM += n; } );
    for( int i=0; i<SUM; i++ ){
        cout << "index of job " << i << ":\t";
        PII p = bwd.getIndicesOfJob(i);
        cout << "(" << p.first << " , " << p.second << ")" << endl;
    } 
    
}

void test2() {
    std::cout << "bucketworkflowtest test 2" << std::endl;
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% bucketworkflowtest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (bucketworkflowtest)" << std::endl;
    test1();
    std::cout << "%TEST_FINISHED% time=0 test1 (bucketworkflowtest)" << std::endl;

    std::cout << "%TEST_STARTED% test2 (bucketworkflowtest)\n" << std::endl;
    test2();
    std::cout << "%TEST_FINISHED% time=0 test2 (bucketworkflowtest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

