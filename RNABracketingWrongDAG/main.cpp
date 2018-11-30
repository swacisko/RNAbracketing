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



#include<iostream>
using namespace std;
#include<vector>
#include<ctime>

#define REP(i,N) for(int i=0; i<N; i++)
typedef vector<int> VI;
typedef vector< VI > VVI;

/*
 * 
 */
int main(int argc, char** argv) {
    
    srand( unsigned(time(0)) );
    InputReader reader;
    VI ends = reader.readInput();
    InputProcessor proc;    
    Graph G = proc.processInput(ends);
    IterationController controller(G);
    controller.startIterations();
    VVI paths = controller.getBestSequenceOfPaths();
    ResultProcessor resproc(ends, paths);
    VI ans = resproc.getAnswer();
    
    cout << endl << "answer:" << endl << "there are " << paths.size() << " different brackets" << endl;
    for(int a : ans) cout << a << " "; cout << endl;
    
    return 0;
}

