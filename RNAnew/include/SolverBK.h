//
// Created by sylwester on 2/22/19.
//

#ifndef GENOMEALIGNMENT_SOLVERBK_H
#define GENOMEALIGNMENT_SOLVERBK_H


#include <set>
#include <unordered_set>
#include "GraphBit.h"

typedef vector<int> VI;
typedef vector<VI> VVI;

class SolverBK {


public:

    VVI solve( GraphBit  g ){
        static int layer = 0;

//        if( !g.isChordal() ){
//            g.write();
//            exit(1);
//        }

//        g.write();

//        cerr << "Nodes with at least two leaves: " << endl; for(int p : g.getNodesWithAtLeastTwoLeafNeighbors().getAllSetBits()) cerr << p << " "; cerr << endl;
//        Bitset fL(g.vertices.size());
//
//        addIterativelyNodesWithAtLeastTwoLeafNeighborsToLayer(g,fL);
//        cerr << "first layer: " << endl; for(int p : fL.getAllSetBits()) cerr << p << " "; cerr << endl;
//        cerr << "there are " << fL.count() << " nodes out of " << g.vertices.count() << " sure in the first layer" << endl;
//        exit(1);

        if( g.vertices.count() == 0 ) return VVI();
        if( g.vertices.count() == 1 ) return VVI( 1, VI(1,g.vertices.lower_bound(0)) );

        layer++;
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
            VI remapper = g2.induce( comp, /*false*/ g2.vertices.count() > maxSmallCompSize && comp.count() <= maxSmallCompSize );

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
                /*if( g2.vertices.count() > maxSmallCompSize ){
                    Bitset inters = calculateRandomMisIntersection(g2, 10 * g2.vertices.count() );

                    cerr << "found maximal MIS intersection of size " << inters.count() << endl;


                    for (int u = inters.lower_bound(0); u != Bitset::INF; u = inters.lower_bound(u+1)) {
                        cur.set(u,1);
                        allowed &= g2[u];
                        forbidden &= g2[u];
                    }
                    currentMax = inters.count();
                    exit(1);
                }*/
                if(g2.vertices.count() > maxSmallCompSize){
                    Bitset fL(g2.vertices.size());
                    addIterativelyNodesWithAtLeastTwoLeafNeighborsToLayer(g2,fL);
                    VI colors(g2.vertices.size(),-1);
                    for( int p : fL.getAllSetBits() ) colors[p] = 0;
                    int iter = 10000000;
                    Bitset inducer = fL;


//                    Bitset inters = calculateRandomMisIntersection(g2, iter / g2.vertices.count() );
                    Bitset inters = calculateRandomMisIntersectionByHybrid(g2, iter / g2.vertices.count(), colors );
                    inducer |= inters;
//                    for( int p : g2.vertices.getAllSetBits() ){
//                        if( (g2.V[p] & inters).count() > 0 ) inducer.set(p,1);
//                    }

                    cerr << "fL.count() = " << fL.count() << "   inducer.count() = " << inducer.count() << "    inters.count() = " << inters.count() << endl;

                    for( int p : inducer.getAllSetBits() ) colors[p] = 0;
                    bestAnsPerComp = solveByHybrid(g2, iter / g2.vertices.count(), colors );
                    VI firstLayer = bestAnsPerComp[0];
                    cerr << "found first layer with " << firstLayer.size() << " nodes" << endl;
                    fL = Bitset(g2.vertices.size());
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
                    bestAnsPerComp = BronKerbosch(g2,cur,allowed,forbidden,currentMax );
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



    VVI BronKerbosch( GraphBit g, Bitset cur, Bitset allowed, Bitset forbidden, int &currentMax ) {
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
//        for( int i=0; i<min(a.size(), b.size()); i++ ){
//            if(a[i].size() < b[i].size()) return true;
//            else if( a[i].size() > b[i].size() ) return false;
//        }
//        return b.size() < a.size();


        if( a[0].size() == 0 ) return true;
        if( b[0].size() == 0 ) return false;
        if( a[0].size() != b[0].size() ) return a[0].size() < b[0].size();

        vector<int> weights(10,1);
        for( int i=1; i<weights.size(); i++ ) weights[i] = (weights[i-1] << 3);
//        for( int i=1; i<weights.size(); i++ ) weights[i] = i;

        int res1 = 0;
        for( int i=0; i<a.size(); i++ ){
            if(i==0)res1 += a[i].size();
            else res1 -= weights[i] * a[i].size();
        }

        int res2 = 0;
        for( int i=0; i<b.size(); i++ ){
            if(i==0)res2 += b[i].size();
            else res2 -= weights[i] * b[i].size();
        }

        return res1 < res2;

    }

    /**
     * Creates @iterations randoms MISs. For each maximum of hte found MISs we take intersection and return that.
     */
    Bitset calculateRandomMisIntersection( GraphBit & g, int iterations ){

        Bitset inters(g.vertices.size());
        inters.set( 0, inters.size()-1,1 );

        int M = 0;
        set<Bitset> differentMISs;
        VI perm = g.vertices.getAllSetBits();

        for(int i=0; i<iterations; i++){
            random_shuffle(perm.begin(), perm.end());
            Bitset b = getMIS(g,perm);
            if( b.count() > M ){
                inters.set( 0, inters.size()-1,1 );
                M = b.count();
                differentMISs.clear();
            }

            if( b.count() == M ){
                inters &= b;
                differentMISs.insert(b);
            }
        }

        cerr << "there are at least " << differentMISs.size() << " different MIS's of size " << M << endl;
        cerr << "found maximal MIS intersection of size " << inters.count() << endl;
        return inters;

    }

    Bitset calculateRandomMisIntersectionByHybrid( GraphBit & g, int iterations, VI initialColors ){

        Bitset inters(g.vertices.size());
        inters.set( 0, inters.size()-1,1 );

        int M = 0;
        set<Bitset> differentMISs;
        VI perm = g.vertices.getAllSetBits();

        for(int i=0; i<iterations; i++){
            random_shuffle(perm.begin(), perm.end());

            VVI r = solveByHybrid( g,1,initialColors );
            Bitset b(g.vertices.size());
            for(int p : r[0]) b.set(p,1);

//            Bitset b = getMIS(g,perm);

            if( b.count() > M ){
                inters.set( 0, inters.size()-1,1 );
                M = b.count();
                differentMISs.clear();
            }

            if( b.count() == M ){
                inters &= b;
                differentMISs.insert(b);
            }
        }

        cerr << "there are at least " << differentMISs.size() << " different MIS's of size " << M << endl;
        cerr << "found maximal MIS intersection of size " << inters.count() << endl;
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


    VVI solveByHybrid( GraphBit & g, int iterations, VI & initialColors ){

        VVI best(g.vertices.size()+1), temp;
        VI perm = g.vertices.getAllSetBits();
        VI colors(g.vertices.size(),-1);

        int maxColors = 60;
        Bitset freeColors(maxColors);

        while(iterations--){
//            for(int p : perm) colors[p] = -1;
            colors = initialColors;
            random_shuffle(perm.begin(), perm.end() );

            int m = 0;
            for( int p : perm ){
                if(colors[p] != -1) continue;

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



    void addIterativelyNodesWithAtLeastTwoLeafNeighborsToLayer( GraphBit g, Bitset &fL ){
        Bitset b;
//        cerr << "g in add fL" <<  endl;
//        g.write();
        Bitset leaves = g.getNodesWithDegree(1);
        cerr << "leaves: " << endl; for(int p : leaves.getAllSetBits()) cerr << p << " "; cerr << endl;

        if( ( b = g.getNodesWithAtLeastTwoLeafNeighbors() ).count() == 0 ) return;



        Bitset toRemoveFromLayer = b;

        for( int p : leaves.getAllSetBits() ){
            if( b[ g.V[p].lower_bound(0) ] ){
                toRemoveFromLayer.set( p,1 );
                fL.set(p,1);
            }
        }

        cerr << "removing from graph: "; for(int p : toRemoveFromLayer.getAllSetBits()) cerr << p << " "; cerr << endl; cerr << endl;

        g.induce( g.vertices & ~toRemoveFromLayer, false );

        addIterativelyNodesWithAtLeastTwoLeafNeighborsToLayer(g, fL);
    }

//
//    /**
//     * Returns optimal value of largest MIS of agraph induced by [a,a+1,...,b]
//     */
//    int getOptimalMISSizeOnInterval( GraphBit & g, int a, int b, int arcA, int arcB, VVI & opt ){
//        if(a>b || arcA > arcB) return 0;
//        if( opt[a][b] != -1 ) return opt[a][b];
////        cerr << "hello! a = " << a << "  b = " << b << "   g.L[" << a << "] = " << g.L[a] << endl;
////        if( a == b ) return (opt[a][b] = g.L[a] <= b );
////        if( g.L[a] == g.vertices.size()+1 ){
////            cerr << "\tg.L[" << a << "] = " << g.L[a] << endl;
////            return (opt[a][b] = 1 + getOptimalMISSizeOnInterval(g,a+1,b,opt));
////        }
//
//        int res = 0;
//        for( int i=a; i<=b; i++ ){
//            if( g.arcBeg[i] >= arcA && g.arcEnd[i] <= arcB ){
//                res = max(res, 1 + getOptimalMISSizeOnInterval( g,a,i-1, arcA, g.arcBeg[i]-1, opt)
//                            + getOptimalMISSizeOnInterval( g,i+1,g.L[i], g.arcBeg[i]+1, g.arcEnd[i]-1, opt  )
//                            + getOptimalMISSizeOnInterval( g,g.L[i]+1,b, g.arcEnd[i]+1, arcB, opt  ) );
//            }
//        }
//
////        cerr << "\treturning " << res << " as best on interval (" << a << "," << b << ")" << endl;
//        return (opt[a][b] = res);
//    }
//
//    Bitset getOptimalMISIntersectionDP( GraphBit & g ){
//        int N = g.vertices.size();
//        VVI opt( N, VI(N,-1) );
//        int INF = 1000000000;
//        int maxIS = getOptimalMISSizeOnInterval( g,0,N-1, 0, INF , opt );
//
//        cerr << "maxIS = " << maxIS << endl;
//        exit(1);
//
//        Bitset mustBeInMaxIS(N);
//
//        for( int i=0; i <N; i++ ){
//            opt = VVI( N, VI(N,-1) );
//            int prevVal = g.L[i];
//            g.L[i] = N+1;
//
//            int res2;
//            if( (res2 = getOptimalMISSizeOnInterval( g,0,N,0,INF, opt )) != maxIS ){
//                mustBeInMaxIS.set(i,1);
//                cerr << "maxIS without node " << i << " = " << res2 << endl;
//            }
//
//            g.L[i] = prevVal;
//        }
//
//
//        cerr << "There are " << mustBeInMaxIS.count() << " vertices that must be in MaxIS" << endl;
//        for(int p : mustBeInMaxIS.getAllSetBits()) cerr << p << " "; cerr << endl;
//
//        return mustBeInMaxIS;
//
//    }


};


#endif //GENOMEALIGNMENT_SOLVERBK_H
