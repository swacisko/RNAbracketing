/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MISNodes.h
 * Author: sylwester
 *
 * Created on November 19, 2018, 9:09 PM
 */

#ifndef MISNODES_H
#define MISNODES_H

#include<vector>
using namespace std;
typedef vector<int> VI;


class MISNodes {
public:
    MISNodes(VI & V);
    MISNodes(const MISNodes& orig);
    virtual ~MISNodes();
    
    VI& getNodes(){return nodes;}
    int size()const{ return nodes.size(); }
    bool operator<( const MISNodes & oth ){
        return size() < oth.size();
    }
private:
    VI nodes;
};

#endif /* MISNODES_H */

