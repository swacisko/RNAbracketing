/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GlobalParams.h
 * Author: sylwester
 *
 * Created on November 19, 2018, 10:29 PM
 */

#ifndef GLOBALPARAMS_H
#define GLOBALPARAMS_H

class GlobalParams {
public:
    GlobalParams();
    GlobalParams(const GlobalParams& orig);
    virtual ~GlobalParams();
    static int MAX_STORE_SIZE;
    static int RANDOM_MIS_PER_MAXIS;
    static int SEARCHES_PER_ITERATION ;
    static int SEARCHES_PER_ITERATION_GEN2;
    
    static const int INITIAL_MAX_STORE_SIZE = 10;
    static const int INITIAL_RANDOM_MIS_PER_MAXIS = 100;
    static const int INITIAL_SEARCHES_PER_ITERATION = 50;
    static const int INITIAL_SEARCHES_PER_ITERATION_GEN2 = 25;
    
    static void resetParams(){
        SEARCHES_PER_ITERATION_GEN2 = INITIAL_SEARCHES_PER_ITERATION_GEN2;
        SEARCHES_PER_ITERATION = INITIAL_SEARCHES_PER_ITERATION;
        RANDOM_MIS_PER_MAXIS = INITIAL_RANDOM_MIS_PER_MAXIS; 
        MAX_STORE_SIZE = INITIAL_MAX_STORE_SIZE;
    }
private:

};

#endif /* GLOBALPARAMS_H */

