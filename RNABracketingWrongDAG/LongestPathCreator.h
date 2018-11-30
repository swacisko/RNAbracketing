/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LongestPathCreator.h
 * Author: sylwester
 *
 * Created on November 17, 2018, 3:54 PM
 */

#ifndef LONGESTPATHCREATOR_H
#define LONGESTPATHCREATOR_H

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

#include "BucketWorkflowDistributor.h"

#define REP(i,N) for(int i=0; i<N; i++)
typedef vector<int> VI;
typedef vector< VI > VVI;
typedef vector<bool> VB;

class Graph;

class LongestPathCreator {
public:
    LongestPathCreator(Graph &G, VB presentVertices);
    //LongestPathCreator(const LongestPathCreator& orig);
    virtual ~LongestPathCreator();
    
    /**
     * 
     * @return number of longest paths in graph G.
     */
    int getNumberOfLongestPaths();
    
    int getMaxLength() const{ return maxPthLength; } // returns length of the longest path
    
    /**
     * 
     * @param K number of longest paths to be returned
     * @return longest path that is K-th in order.
     */
    VI getKthLongestPath( int K );
    
    
    void clear();
    
    void write(); // writes data in arrays;
    
private:
    Graph *G;
    int maxPthLength = -1; // maximal length of a path in G.
    int noOfLongestPaths = -1; // this is the number of longest paths;
    VB presentVertices;
    VI maxPathLength; // maxPathLength[i] is the length of the longest path with end in i.
    VI numberOfMaxPaths; // numberOfMaxPaths[i] is the number of paths with end in i that have length maxPathLength[i]
    VI topologicalOrder;
    VVI prevOnLongestPaths; // prevOnLongestPath[i] is a list of vertices that are a predecessor of i on longest paths leading to i.
   
    
    
    void createLongestPathsData(); // creates all data required to access K-th longest path via getKthLongestPath function
    void createLongestPathsValues(); // creates arrays maxPathLength and numberOfMaxPAths and prevOnLongestPaths
    void createTopologicalOrder(); // creates topologicalOrder - vector of vertices present in G in topological order.
    
};

#endif /* LONGESTPATHCREATOR_H */

