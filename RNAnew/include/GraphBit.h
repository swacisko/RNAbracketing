//
// Created by sylwester on 2/22/19.
//

#ifndef GENOMEALIGNMENT_GRAPHBIT_H
#define GENOMEALIGNMENT_GRAPHBIT_H


#include <numeric>
#include "Bitset.h"

class GraphBit {


public:
    GraphBit(int N){
        V = vector<Bitset>(N, Bitset(N));
        vertices = Bitset(N);
        vertices.set(0,N-1,1);
        L = VI(N,N+1);
        arcBeg = VI(N);
        arcEnd = VI(N);

    }
    Bitset& operator[](int n){ return V[n]; }


    VI induce(Bitset b, bool shrink = false){
//        for( int i=0; i<vertices.size(); i++ ) if( b[i] == 0 ) V[i].set(0, vertices.size()-1,0);

        if(shrink){
//            cerr << "shrinking!" << endl << endl << endl;
            VI mapper( vertices.size(),-1 );
            VI remapper;
            int t = 0;
            vertices &= b;
            for( int i = vertices.lower_bound(0); i != Bitset::INF; i = vertices.lower_bound(i+1)  ){
                mapper[i] = t++;
                remapper.push_back(i);
            }

            vector<Bitset> newV( vertices.count(), Bitset(vertices.count()) );

            for( int i = vertices.lower_bound(0); i != Bitset::INF; i = vertices.lower_bound(i+1)  ){
                for( int u = V[i].lower_bound(0); u != Bitset::INF; u = V[i].lower_bound(u+1) ){
                    newV[ mapper[i] ].set( mapper[u],1 );
                }
            }

            V = newV;

            vertices = Bitset( vertices.count() );
            vertices.set( 0,vertices.size()-1,1 );

            return remapper;

        }else{
            vertices &= b;
            for( int i = vertices.lower_bound(0); i != Bitset::INF; i = vertices.lower_bound(i+1)  ){
                V[i] &= b;
            }

            VI r( vertices.size() );
            iota( r.begin(), r.end(),0 );
            return r;
        }



        return VI();
    }


    void markComponents( int beg, int num ){
        if( componentIds[beg] != -1 ) return;
//        cerr << beg << " -> " << num << endl;
        componentIds[beg] = num;

        for( int i = V[beg].lower_bound(0); i != Bitset::INF; i = V[beg].lower_bound(i+1)  ) markComponents(i,num);

    }

    vector<Bitset> getConnectedComponents(){
        vector<Bitset> res;

        int num = 0;
        componentIds = VI( vertices.size(), -1 );
        for( int i = vertices.lower_bound(0); i != Bitset::INF; i = vertices.lower_bound(i+1)  ) markComponents(i, num++);

        for(int k=0; k<num; k++){
            Bitset b(vertices.size());
            for( int i = vertices.lower_bound(0); i != Bitset::INF; i = vertices.lower_bound(i+1)  ){
                if( componentIds[i] == k ) b.set(i,1);
            }
            res.push_back(b);
        }

        return res;
    }

    void makeComplement(){
        for( int i = vertices.lower_bound(0); i != Bitset::INF; i = vertices.lower_bound(i+1)  ){
            V[i] = ~V[i];
            V[i] &= vertices;
            V[i].set(i,0);
        }
    }

    void write(){
        cerr << "vertices: "; for(auto p : vertices.getAllSetBits()) cerr << p << " "; cerr << endl << "edges: " << endl;
        for( int i= vertices.lower_bound(0); i!= Bitset::INF; i = vertices.lower_bound(i+1) ){
            for( auto p : V[i].getAllSetBits() ){
                cerr << "(" << i << "," << p << ")    ";
            }
            cerr << endl;
        }
    }

    int countEdges(){
        int res = 0;
        for(auto a : vertices.getAllSetBits()){
            res += V[a].count();
        }
        return res / 2;
    }

    int countNodesWithDegree(int deg){
        int res = 0;
        for(auto a : vertices.getAllSetBits()){
            if( V[a].count() == deg ) res++;
        }
        return res;
    }

    Bitset getNodesWithDegree(int deg){
        Bitset b(vertices.size());
        for( auto a : vertices.getAllSetBits() ){
            if( V[a].count() == deg ) b.set(a,1);
        }
        return b;
    }


    bool isChordal(){
        VI bits = vertices.getAllSetBits();

        for( int a : bits ){

            VI neigh = V[a].getAllSetBits();
            for( int x : neigh ){
                for(int y : neigh){
                    if(x <= y)continue;

                    if( V[x][y] == 0 || V[y][x] == 0 ){

                        if( (V[x] & V[y]).count() > 1 ){
                            cerr << "Graph not chordal, a = " << a << "  neighbors: " << x << ", " << y << endl;
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }

    Bitset getNodesWithAtLeastTwoLeafNeighbors(){
        Bitset b( vertices.size() );

        VI v(b.size(),0);
        for( int p : vertices.getAllSetBits() ){
            if( V[p].count() == 1 ) v[ V[p].lower_bound(0) ]++;
        }

        for( int i=0; i<v.size(); i++ ){
            if( v[i] >= 2 ) b.set(i,1);
        }
        return b;

    }

    vector<Bitset> V;
    Bitset vertices;
    VI componentIds;

    VI L;
    VI arcBeg;
    VI arcEnd;

};


#endif //GENOMEALIGNMENT_GRAPHBIT_H
