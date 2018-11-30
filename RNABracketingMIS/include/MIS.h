/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MIS.h
 * Author: sylwester
 *
 * Created on November 19, 2018, 9:08 PM
 */

#ifndef MIS_H
#define MIS_H

#include "Graph.h"
#include<algorithm>

typedef vector<bool> VB;

class MIS {
public:
    MIS(Graph &G, VB presentVertices);
    MIS(const MIS& orig);
    virtual ~MIS();
    
    /**
     * Returns random MIS in O(E) time (all edges in G in worst case) or random maximal clique in O(N^2) (must find compliment of G in N^2)
     * @param mis if mis = MIS_MODE then random MIS is returned. Otherwise random CLIQUE is returned.
     * @return 
     */
    VI getRandomIS( int mode = MIS_MODE ); 
    VI searchForMaxIS( int iterations = 0, int mode = MIS_MODE );
    
    static const int MIS_MODE = 1;
    static const int CLIQUE_MODE = 0;
private:

    Graph *G;
    VB presentVertices;
    /**
     * @param X array from which to remove neighbors (in case of looking for MIS neighbors of v are removed from X, in case of clique all nonneighbors of v are removed from X).
     * @param v
     * @param mis
     * @return returns number of removed nodes
     */
    int removeNodesFromX( VB & X, int v, int mode = MIS_MODE );
};

#endif /* MIS_H */

