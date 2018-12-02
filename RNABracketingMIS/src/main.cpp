/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: sylwester
 *
 * Created on November 17, 2018, 3:47 PM
 */


#include "InputReader.h"
#include "InputProcessor.h"
#include "IterationController.h"
#include "ResultProcessor.h"
#include "GlobalIterator.h"
#include "ResultTester.h"



#include<iostream>
using namespace std;
#include<vector>
#include<ctime>

#define REP(i,N) for(int i=0; i<N; i++)
typedef vector<int> VI;
typedef vector< VI > VVI;

int GlobalParams::MAX_STORE_SIZE = GlobalParams::INITIAL_MAX_STORE_SIZE;
int GlobalParams::RANDOM_MIS_PER_MAXIS = GlobalParams::INITIAL_RANDOM_MIS_PER_MAXIS;
int GlobalParams::SEARCHES_PER_ITERATION = GlobalParams::INITIAL_SEARCHES_PER_ITERATION;
int GlobalParams::SEARCHES_PER_ITERATION_GEN2 = GlobalParams::INITIAL_SEARCHES_PER_ITERATION_GEN2;


/*
 * 
 */
int main(int argc, char** argv) {

    ResultTester tester;
    tester.testSolution();
    return 0;


   // srand( unsigned(time(0)) );
    InputReader reader;
    VI ends = reader.readInput();
    InputProcessor proc;    
    Graph G = proc.processInput(ends);
    
    /* // this checks only once for given params in GlobalParams
    IterationController controller(G, VB(G.size(), true));
    controller.startIterations();
    
    VVI seqOfMaxIS = controller.getMaxIndSets();
    */
    
    
    // this version is to iterate with different parameters from GLobalParams
    GlobalIterator iter(G);
    int iterations = 20;
    iter.startIterations( iterations);
    VVI seqOfMaxIS = iter.getBestAnswer();
    
    ResultProcessor resproc( ends, seqOfMaxIS );
    
    string ans = resproc.getAnswer();
    
    
    cout << endl << endl << endl;  
    cout << "Now sizes of consequent MaxIS:" << endl;
    for( VI v : seqOfMaxIS ) cout << v.size() << " "; cout << endl;
    cout << "Now consequent MaxIS:" << endl;
    WRITE2(seqOfMaxIS);
      
    
    if( !ResultTester().isCorrect(G,seqOfMaxIS) ){
        for( int i=0; i<10; i++ ) cerr << "ERROR" << endl;
        cerr << endl << "RESULT NOT CORRECT" << endl << endl;
    }
    
   // for( int a : ans ) cout << a << " "; cout << endl;
    cout << reader.getInputSequence() << endl;
    cout << ans << endl;
    
    
    return 0;
}

