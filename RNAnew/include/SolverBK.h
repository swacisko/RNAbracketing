//
// Created by sylwester on 2/22/19.
//

#ifndef GENOMEALIGNMENT_SOLVERBK_H
#define GENOMEALIGNMENT_SOLVERBK_H


#include "GraphBit.h"

typedef vector<int> VI;
typedef vector<VI> VVI;

class SolverBK {


public:

    VVI solve( GraphBit  g ){
        static int layer = 0;
//        cerr << endl << "g in solve:" << endl;
//        g.write();
        if( g.vertices.count() == 0 ) return VVI();
        if( g.vertices.count() == 1 ) return VVI( 1, VI(1,g.vertices.lower_bound(0)) );

        layer++;
//        g.makeComplement();

//

        vector<Bitset> components = g.getConnectedComponents();

        if(layer <= 3){
            for(int i=0; i<layer;i++) cerr << "\t";
            cerr << "your connected components sizes: ";
            for( Bitset comp : components ){
                cerr << comp.count() << "  ";
            }
            cerr << endl;
        }



       /* for( Bitset comp : components ){

            VI randomSeparators = comp.getAllSetBits();
            random_shuffle( randomSeparators.begin(), randomSeparators.end() );
            randomSeparators.resize( randomSeparators.size() / 5 );
            Bitset inducer(comp.size());
            for(int a : randomSeparators) inducer.set(a,1);
            comp &= ~inducer;

            GraphBit g2 = g;
            g2.induce(comp);
            solve( g2 );
        }

        if(layer <= 15){
            for(int i=0; i<layer;i++) cerr << "\t";
            cerr << "returning" << endl;

        }


        return VVI();*/
//        exit(1);

        int maxSmallCompSize = 54;

        VVI res;
        for( Bitset comp : components ){
            if( comp.count() == 0 ) continue;


//            VI test = comp.getAllSetBits();
//            cerr << "connected component induced by vertices:  " << flush;
//            for(auto a : test) cerr << a << " "; cerr << endl;

            GraphBit g2 = g;
            VI remapper = g2.induce( comp, false /*g2.vertices.count() > 62 && comp.count() <= 62*/ );

            if( comp.count() > maxSmallCompSize ){
                for(int i=0; i<layer;i++) cerr << "\t";
                cerr << "component of size " << comp.count() << " in layer " << layer << endl;
                cerr << "edges: " << g2.countEdges() << endl;
//                for(int i=0; i<50; i++){
//                    cerr << "nodes with degree " << i << ": " << g2.countNodesWithDegree(i) << endl;
//                }
                cerr << endl;
            }

//            g2.write();
//            cerr << "compliment conn.comp." << endl;
//            g2.write();

            int N = g2.vertices.size();
            int currentMax = 1;
            Bitset cur(N), allowed(N), forbidden(N);
            allowed = g2.vertices;

            VVI bestAnsPerComp;
            if( g2.vertices.count() == 0 ) bestAnsPerComp = VVI();
            else if( g2.vertices.count() == 1 ) bestAnsPerComp = VVI( 1, VI(1,g2.vertices.lower_bound(0)) );
            else{
//                if( g2.vertices.count() > maxSmallCompSize ){
//                    Bitset inters = calculateRandomMisIntersection(g2, 10 * g2.vertices.count() );
//
//                    cerr << "found maximal MIS intersection of size " << inters.count() << endl;
//
//
//                    for (int u = inters.lower_bound(0); u != Bitset::INF; u = inters.lower_bound(u+1)) {
//                        cur.set(u,1);
//                        allowed &= g2[u];
//                        forbidden &= g2[u];
//                    }
//                    currentMax = inters.count();
//                }

                if(g2.vertices.count() > maxSmallCompSize){
                    bestAnsPerComp = solveByHybrid(g2, 30 * g2.vertices.count() );
                    VI firstLayer = bestAnsPerComp[0];
                    cerr << "found first layer with " << firstLayer.size() << " nodes" << endl;
                    Bitset fL(g2.vertices.size());
                    for(int p : firstLayer) fL.set(p,1);
                    fL = g.vertices & ~fL;
                    g2.induce( fL, false );
                    cerr << "trying to find best for graph without first layer, with altogether " << g2.vertices.count() << " nodes" << endl;
                    VVI rest = solve(g2);
                    bestAnsPerComp.clear();
                    bestAnsPerComp.push_back(firstLayer);
                    for(auto v : rest) bestAnsPerComp.push_back(v);

                }else{
                    g2.makeComplement();
                    bestAnsPerComp = BronKerbosch(g2,cur,allowed,forbidden,currentMax);
                }

            }


            if( comp.count() > maxSmallCompSize ){
                for(int i=0; i<layer;i++) cerr << "\t";
                cerr << "component of size " << comp.count() << " resolved" << endl;
            }

//            cerr << "best answer for this component:" << endl;
//            for( auto v : bestAnsPerComp ){
//                for( auto a : v ) cerr << a << " ";
//                cerr << endl;
//            }
//            cerr << endl;

            for( int i=0; i<bestAnsPerComp.size(); i++ ){
                if( res.size() == i ) res.push_back(VI());

                for( int k=0; k<bestAnsPerComp[i].size(); k++ ){
                    res[i].push_back( remapper[ bestAnsPerComp[i][k] ] );
                }

            }


        }

//            cerr << endl << endl << endl << endl;

        layer--;
        return res;

    }


    VVI BronKerbosch( GraphBit g, Bitset cur, Bitset allowed, Bitset forbidden, int &currentMax) {
        if (allowed.count()==0 && forbidden.count()==0 && cur.count() >= currentMax) {
            currentMax = cur.count();

//            cerr << "currentMax = " << currentMax << endl;
            if( cur.count() > 20 ) cerr << "cur:  " << cur.count() << endl;//for (int u = cur.lower_bound(0); u != Bitset::INF; u = cur.lower_bound(u+1)) cerr << u << " "; cerr << endl;
//            return VVI();


            VVI res(1);
            for (int u = cur.lower_bound(0); u != Bitset::INF; u = cur.lower_bound(u+1)) res[0].push_back(u);

            GraphBit g2 = g;

//            cerr << "curNeg:" << endl;
//            for(auto a : (~cur).getAllSetBits() ) cerr << a << " "; cerr << endl;

            Bitset inducer = g2.vertices & (~cur);

//            cerr << "inducer" << endl;
//            for (int u = inducer.lower_bound(0); u != Bitset::INF; u = inducer.lower_bound(u+1)) cerr << u << " "; cerr << endl;


            g2.induce(inducer,false);

//            cerr << "g2 induced in bron-kerbosh" << endl;
//            g2.write();

            g2.makeComplement();

//            cerr << "g2 induced in bron-kerbosh complement (normal)" << endl;
//            g2.write();

            VVI r = solve( g2 );
            for( VI & v : r ) res.push_back(v);

//            cerr << "returning for cur:  ";for (int u = cur.lower_bound(0); u != Bitset::INF; u = cur.lower_bound(u+1)) cerr << u << " "; cerr << endl;
//            for( auto v : res ){ for( auto a : v ) cerr << a << " ";cerr << endl; }
//            cerr << endl;

            return res;
        }
        if (allowed.count() == 0){
//            cerr << "in BK returning nothing, allowed.count() == 0" << endl;
            return VVI();

        }

        Bitset begAllowed = allowed;

        VVI res( allowed.count() );
        Bitset af = allowed | forbidden;
        int pivot = af.lower_bound(0);
        Bitset z = allowed & ~g[pivot];

        Bitset b( cur.size() );
        for (int u = z.lower_bound(0); u != Bitset::INF; u = z.lower_bound(u+1)) {

            b.set(u,1);
            if( cur.count() + allowed.count() >= currentMax ){
                VVI newRes = BronKerbosch(g, cur | b, allowed & g[u], forbidden & g[u],currentMax);
                if( newRes.size() > 0 && compareResults( res, newRes ) ){
//                    cerr << "\tassigning newRes to res" << endl;
                    res = newRes;
                }
            }


            allowed ^= b;
            forbidden |= b;
            b.set(u,0);
        }

//        cerr << "best answer in bron-kerbosh for allowed: ";
//        for(auto p : begAllowed.getAllSetBits()) cerr << p << " ";
//        cerr << endl;
//        for( auto v : res ){
//            for( auto a : v ) cerr << a << " ";
//            cerr << endl;
//        }
//        cerr << endl;

        return res;
    }

    // returns true if a < b so if b is better solution then returns true.
    bool compareResults( VVI & a, VVI b ){
        for( int i=0; i<min(a.size(), b.size()); i++ ){
            if(a[i].size() < b[i].size()) return true;
            else if( a[i].size() > b[i].size() ) return false;
        }
        return b.size() < a.size();
    }

    /**
     * Creates @iterations randoms MISs. For each maximum of hte found MISs we take intersection and return that.
     */
    Bitset calculateRandomMisIntersection( GraphBit & g, int iterations ){

        Bitset inters(g.vertices.size());
        inters.set( 0, inters.size()-1,1 );

        int M = 0;
        VI perm = g.vertices.getAllSetBits();

        for(int i=0; i<iterations; i++){
            random_shuffle(perm.begin(), perm.end());
            Bitset b = getMIS(g,perm);
            if( b.count() > M ){
                inters.set( 0, inters.size()-1,1 );
                M = b.count();
            }

            if( b.count() == M ) inters &= b;
        }
        return inters;

    }

    Bitset getMIS( GraphBit & g, VI & perm ){
        Bitset mis(g.vertices.size());
        for(int p : perm){
            int inters = (mis & g[p]).count();
            if( inters == 0 ) mis.set(p,1);
        }
        return mis;
    }


    VVI solveByHybrid( GraphBit & g, int iterations ){

        VVI best(g.vertices.size()+1), temp;
        VI perm = g.vertices.getAllSetBits();
        VI colors(g.vertices.size(),-1);

        int maxColors = 60;
        Bitset freeColors(maxColors);

        while(iterations--){
            for(int p : perm) colors[p] = -1;
            random_shuffle(perm.begin(), perm.end() );

            int m = 0;
            for( int p : perm ){
                freeColors.set( 0, maxColors-1,1 );
                for( int u : g[p].getAllSetBits() ){
                    if( colors[u] != -1 ) freeColors.set( colors[u] ,0);
                }

                int firstFreeColor = freeColors.lower_bound(0);
                colors[p] = firstFreeColor;
                m = max(m, firstFreeColor+1);
            }

            temp = VVI(m);
            for( int p : perm ) temp[ colors[p] ].push_back(p);
            if( compareResults( best, temp) ){
//                    cerr << "\tassigning newRes to res" << endl;
                best = temp;
            }


        }

        return best;

    }


};


#endif //GENOMEALIGNMENT_SOLVERBK_H
