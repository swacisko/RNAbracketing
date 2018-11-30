/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GlobalParams.h
 * Author: sylwester
 *
 * Created on November 17, 2018, 9:38 PM
 */

#ifndef GLOBALPARAMS_H
#define GLOBALPARAMS_H

class GlobalParams {
public:
    GlobalParams();
    GlobalParams(const GlobalParams& orig);
    virtual ~GlobalParams();
    
    
    
    
    
    /**
     * this is the maximal number of longest paths that will be checked in each iteration.
     * There should be not more than 10 iteration, in each PATHS_PER_ITERATION times will be done TopoSort.
     * Complexity is therefore O( 10 * PATHS_PER_ITERATION * E ), where E is the number of edges in graph G. However due to presentVertices array it should be faster for
     * all iterations, excluding the first one.
     */
    static const int PATHS_PER_ITERATION = 150; 
    
    /**
     * this is the maximal number of graphs that will be kept during each iteration. Of course each of these graphs will have the same value of maxPthLength.
     */
    static const int MAX_ITEARTION_GRAPHS = 50;
private:

};
/*
int GlobalParams::PATHS_PER_ITERATION = 1000000;
int GlobalParams::MAX_ITEARTION_GRAPHS = 100;*/

#endif /* GLOBALPARAMS_H */

