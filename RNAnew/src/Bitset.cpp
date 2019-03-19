/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bitset.cpp
 * Author: sylwester
 * 
 * Created on November 20, 2018, 9:11 PM
 */

#include <Bitset.h>
#include <bitset>

#include "Bitset.h"

Bitset::Bitset(int size) : N(size) {
    initializeStaticBlock();
    blocks = BL_NUM(N-1) + 1;
    V = VT( blocks );
    for( auto & a : V ) a = ZEROS;
    lastElementModifier = ZEROS;
    
    for( long long i=0; i< ( IND_IN_BL(N)==0 ? BLOCK_SIZE : IND_IN_BL(N)  ); i++ ) lastElementModifier |= bits[i];
    
   
}

Bitset::Bitset(const Bitset& oth) {
    blocks = oth.blocks;
    N = oth.N;
    if( V.size() != oth.V.size() ) V.resize( oth.V.size() );
    for( int i=0; i<V.size(); i++ ) V[i] = oth.V[i];
    lastElementModifier = oth.lastElementModifier;
}
//
//Bitset::~Bitset() {
//    clear();
//}

bool Bitset::operator!=(const Bitset& oth) {
    return !( *this == oth );
}

Bitset& Bitset::operator&=(const Bitset& oth) {
    for( int i=0; i<V.size(); i++ ) V[i] &= oth.V[i];
    return *this;
}

Bitset Bitset::operator&(const Bitset& oth) {
    Bitset b( *this );
    b &= oth;
    return b;
}
/*
bool Bitset::operator<(const Bitset& oth) {
    
}

bool Bitset::operator<=(const Bitset& oth) {
    
}*/


Bitset Bitset::operator<<(int offset) {
    Bitset b( *this );
    b <<= offset;
    return b;
}

Bitset& Bitset::operator<<=(int offset) {
    int p = 0;
    const int beg = IND_IN_BL(offset);
    const int end = beg-1;   
    int q1 = BL_NUM(offset);
    int q2 = BL_NUM(offset -1 + BLOCK_SIZE );
    
    while( q1 < blocks ){
        TYPE a = ( V[q1] & ( zerosOnes[beg] ) );
        TYPE b = ZEROS;
        if( q2 < blocks ) b = ( V[q2] & ( ~zerosOnes[end+1] ) );
        
        a >>= beg;
        b <<= BLOCK_SIZE-1-end;
        
        V[p] = ( a | b );
        
        p++;
        q1++;
        q2++;
    }
    
    while( p < blocks ){
        V[p] = ZEROS;
        p++;
    }
    
    return *this;
}


bool Bitset::operator==(const Bitset& oth) {
    if( size() != oth.size() ) return false;
    for( int i=0; i<blocks; i++ ){
        if( V[i] != oth.V[i] ) return false;
    }
    return true;
}

Bitset Bitset::operator>>(int offset) {
    Bitset b( *this );
    b >>= offset;
    return b;
}

Bitset& Bitset::operator>>=(int offset) {
    int p = blocks-1;
    
    const int end = BLOCK_SIZE-1 - IND_IN_BL(offset);
    const int beg = end+1;    
    
  //  cerr << "beg: " << beg << "     end: " << end << endl;
    
    int q2 = p - BL_NUM( offset );
    int q1 = p - BL_NUM(offset -1 + BLOCK_SIZE );
        
    while( q2 >= 0 ){
        TYPE b = ( V[q2] & ( ~zerosOnes[end+1] ) );
        TYPE a = ZEROS;
        if( q1 >= 0 ) a = ( V[q1] & ( zerosOnes[beg] ) );
        
     //   cerr << "p:     " << p << endl;
     //   cerr << "q1:    " << q1 << "      q2: " << q2 << endl << "a: " << toBinary(a) << endl << "b: " << toBinary(b) << endl << endl;
     //   cerr << "V[q1]: " << toBinary(V[q1]) << "   V[q2]: " << toBinary(V[q2]) << endl;
        
        
        a >>= beg;
        b <<= BLOCK_SIZE-1 - end;
        
     //   cerr << "a: " << toBinary(a) << endl << "b: " << toBinary(b) << endl << endl;
        
        V[p] = (a|b);
     //   cerr << "V[p]: " << toBinary(V[p]) << endl;
        
        q1--;
        q2--;
        p--;
    }
    
    while( p >= 0 ) V[p--] = ZEROS;
    
    return *this;
}

int Bitset::operator[](int ind) {
    if( (V[ BL_NUM(ind) ] & bits[ IND_IN_BL(ind) ]) != 0 ) return 1;
    else return 0;
}

Bitset& Bitset::operator=(const Bitset& oth) {
    blocks = oth.blocks;
    if( V.size() != oth.V.size() ) V.resize( oth.V.size() );
    for( int i=0; i<V.size(); i++ ) V[i] = oth.V[i];

    N = oth.N;
    lastElementModifier = oth.lastElementModifier;
    return *this;
}

Bitset& Bitset::set(int pos, bool value) {   
    if( pos >= size() ) return *this;
    
    if( value ) V[ BL_NUM(pos) ] |= bits[ IND_IN_BL(pos) ];
    else V[ BL_NUM(pos) ] &= (~bits[ IND_IN_BL(pos) ]);
    
    if( BL_NUM(pos) == blocks-1 ) V[ BL_NUM(pos) ] &= lastElementModifier;
    return *this;
}

Bitset& Bitset::set(int beg, int end, bool value) {

//    cerr << "before this = " << endl << *this << endl;
    if( end >= size() ) end = max( beg, size()-1 );
    if( beg > end ) return *this;

    int p = BL_NUM(beg);
    int q = BL_NUM(end);

//    cerr << "p = " << p << "   q = " << q << "   beg = " << beg << "    end = " << end <<  endl;

    TYPE A = V[p];
    TYPE B = V[q];
    if( value ) A |= zerosOnes[ IND_IN_BL(beg) ];
    else A &= (~zerosOnes[IND_IN_BL(beg)]);

    V[p] = A;

    for( int i=p+1; i<q; i++ ){
        if( value ) V[i] = ONES;
        else V[i] = ZEROS;
    }

//    cerr << "p = " << p << "   q = " << q << endl;
//    cerr << "V[p]: " << endl << toBinary(V[p]) << endl;

    if( value ) B |= ( IND_IN_BL(end+1) == 0 ? ~ZEROS :  (  ~zerosOnes[ IND_IN_BL(end+1) ] ) );
    else{
//        cerr << "p = " << p << "   q = " << q << "   B = " << endl << toBinary(B) << endl;
        B &= ( IND_IN_BL(end+1) == 0 ? ZEROS : zerosOnes[ IND_IN_BL(end+1) ] );
//        cerr << "zerosOnes[end+1]:" << endl << toBinary(zerosOnes[ IND_IN_BL(end+1) ]) << endl;
//        cerr << "p = " << p << "   q = " << q << "   B = " << endl << toBinary(B) << endl;
    }


    if( p == q ){
        if( value ) V[p] &= B;
        else V[p] |= B;
    }
    else V[q] = B;

//    cerr << "V[p]: " << endl << toBinary(V[p]) << endl;

    if( q == blocks-1 ) V[q] &= lastElementModifier;

//    cerr << "after this = " << endl << *this << endl;
    return *this;
}

Bitset Bitset::flip(int pos) {
    if( pos >= size() ) return *this;

    if( (*this)[pos] ) set(pos,false);
    else set(pos,true);
    return *this;
}

Bitset& Bitset::flip(int beg, int end) {
    if( end >= size() ) end = max( beg, size()-1 );
    
    int p = BL_NUM(beg);
    int q = BL_NUM(end);
    
    int indBeg = IND_IN_BL(beg);    
    int indEnd = IND_IN_BL( end );
    
    TYPE rest = V[p] & ( ~zerosOnes[ indBeg ] );
  //  cerr << "r: " << toBinary(rest) << endl;
    TYPE a = (V[p] & zerosOnes[ indBeg ]);
 //   cerr << "a: " << toBinary(a) << endl << endl;
    
    a |= (~zerosOnes[indBeg]);
    
   // cerr << "a: " << toBinary(a) << endl;
    a = ~a;
   // cerr << "a: " << toBinary(a) << endl;
    a |= rest;        
 //   cerr << "a: " << toBinary(a) << endl;
    if( p == q ) a &= (~zerosOnes[indEnd+1]);
  //  cerr << "a: " << toBinary(a) << endl;
    
    for( int i=p+1; i<q; i++ ) V[i] = ~V[i];
    
    rest = (V[q] & zerosOnes[indEnd+1]);
    TYPE b = (V[q] & ( ~zerosOnes[indEnd+1] ));
    b |= zerosOnes[indEnd+1];
    b = ~b;
    b |= rest;
    if( p == q ) b &= ( zerosOnes[indBeg] );
    
 //   cerr << "b: " << toBinary(b) << endl;
    
    if( p == q ) V[p] = ( a | b );
    else {
        V[p] = a;
        V[q] = b;
    }
    
    if( q == blocks-1 ) V[q] &= lastElementModifier;
    
    return *this;
}



Bitset Bitset::operator ^(const Bitset& oth) {
    Bitset b( *this );
    b ^= oth;
    return b;
}

Bitset& Bitset::operator^=(const Bitset& oth) {
    int m = min( blocks, oth.blocks );
    for( int i=0; i<m; i++ ) V[i] ^= oth.V[i];
    return *this;
}

Bitset Bitset::operator|(const Bitset& oth) {
    Bitset b( *this );
    b |= oth;
    return b;
}

Bitset& Bitset::operator|=(const Bitset& oth) {
    int m = min( blocks, oth.blocks );
    for( int i=0; i<m; i++ ) V[i] |= oth.V[i];
    return *this;
}

Bitset Bitset::operator~() {
    Bitset b( *this );
    for( auto &a : b.V ) a = ~a;
    //V.back() &= lastElementModifier;
    return b;
}

int Bitset::count() const{
    int res = 0;
    if( sizeof(TYPE) == 4 ){ 
        for( auto a : V ) res += __builtin_popcount(a);
    }else if( sizeof(TYPE) == 8 ){
        for( auto a : V ) res += __builtin_popcountll(a);
    }
    return res;
}


int Bitset::count(int a, int b) const {
    int res = 0;

    int p = BL_NUM(a);
    int q = BL_NUM(b);

    int beg = IND_IN_BL(a);
    int end = IND_IN_BL(b);


    if( BL_NUM(a) == BL_NUM(b) ){
        TYPE t = V[ BL_NUM(a) ];
        t &= zerosOnes[ beg ];
        t &= ( IND_IN_BL(end+1) == 0 ? ONES : ~zerosOnes[ IND_IN_BL(end+1) ] );
        if( sizeof(TYPE) == 4 )res += __builtin_popcount(t);
        else if( sizeof(TYPE) == 8 ) res += __builtin_popcountll(t);
    }else{
        if( sizeof(TYPE) == 4 )res += __builtin_popcount( V[ p ] & zerosOnes[beg] );
        else if( sizeof(TYPE) == 8 ) res += __builtin_popcountll( V[ p ] & zerosOnes[beg]  );

        for( int i=p+1; i<=q-1; i++ ){
            if( sizeof(TYPE) == 4 )res += __builtin_popcount( V[ i ] );
            else if( sizeof(TYPE) == 8 ) res += __builtin_popcountll( V[ i ]  );
        }

        if( sizeof(TYPE) == 4 )res += __builtin_popcount( V[ q ] & ( IND_IN_BL(end+1) == 0 ? ONES : ~zerosOnes[ IND_IN_BL(end+1) ] ) );
        else if( sizeof(TYPE) == 8 ) res += __builtin_popcountll( V[ q ] & ( IND_IN_BL(end+1) == 0 ? ONES : ~zerosOnes[ IND_IN_BL(end+1) ] ) );
    }

    return res;
}


int Bitset::size() const{
    return N;
}

bool Bitset::any() {
    for( auto a : V ){
        if( a != ZEROS ) return true;
    }
    return false;
}

bool Bitset::all() {
    for( auto a : V ){
        if( a != ONES ) return false;
    }
    return true;
}


int Bitset::hash() const{
    long long P = 20000000001;
    long long res = 0;
    for( auto a : V ){
        res *= P;
        res += ( a % P );
        if( res > P ) res %= P;
    }
    return res;
}

VI Bitset::getAllSetBits()const {
    VI res;
    for( int i=0; i<blocks; i++ ){
        TYPE b = V[i];
        while( b != 0 ){
            TYPE t = (b & -b);
            int r;
            if( sizeof(TYPE) == 4 ) r = __builtin_ctz(t);
            else r = __builtin_ctzll(t);
            res.push_back( i*BLOCK_SIZE + r );
            b ^= t;
        }
    }
    return res;
}

void Bitset::clear() {
    //V.clear();
    VT().swap(V);
}

int Bitset::lower_bound(int pos) {
    if( pos >= size() ) return INF;
    TYPE b = V[ BL_NUM(pos) ];
    int d = IND_IN_BL(pos);
    
    if( d > 0 ) b &= zerosOnes[d];
    if( b != 0 ){
        if( sizeof(TYPE) == 4 ) return ( BL_NUM(pos)*BLOCK_SIZE + __builtin_ctz(b) );
        else return ( BL_NUM(pos)*BLOCK_SIZE + __builtin_ctzll(b) );
    }
    
    for( int i = BL_NUM(pos)+1; i < blocks; i++ ){
        if( ( V[i] & ONES ) != 0 ){
            if( sizeof(TYPE) == 4 ) return i*BLOCK_SIZE + __builtin_ctz( V[i] );
            else return i*BLOCK_SIZE + __builtin_ctzll( V[i] );
        }
    }
    
    return INF;
}

int Bitset::upper_bound(int pos) {
    return lower_bound(pos + 1);
}

string Bitset::toBinary(TYPE a) {
    string s = "";
    while(a > 0){
        if(a&1!=0) s += "1";
        else s += "0";
        a >>= 1;
    }
    while( s.size() < BLOCK_SIZE) s += "0";
   // reverse( s.begin(), s.end() );
    return s;
}


string Bitset::toString() {
    string s = "";
    for( int i=0; i<size(); i++ ){
      //  if( i > 0 && (i%BLOCK_SIZE==0) ) s += " ";
        if( (*this)[i] != 0 ) s += "1";
        else s += "0";        
    }
    return s;
}

bool Bitset::operator<(const Bitset& oth) const{
    int p = blocks-1;
    int q = oth.blocks-1;
    
    while( p > q ){
        if( V[p] > 0 ) return false;
        p--;
    }
    while( q > p ){
        if( oth.V[q] > 0 ) return true;
    }
    
    while( p >= 0 ){
        if( V[p] != oth.V[p] ) return V[p] < oth.V[p];
        p--;
    }
    return false;    
}

ostream& operator<<( ostream & str, Bitset & b ){
//    str << b.toString();
    str << "(";
    for(int p : b.getAllSetBits()) str << p << ", ";
    str << ")";
    return str;
}

void Bitset::negate() {
    for( auto &a : V ){
        auto b = a;
        a = ~b;
    }
    V.back() &= lastElementModifier;
}




#define WRITE(myb, cppb){\
cerr << endl << myb << endl;\
for(int j=0; j<N; j++) cerr << cppb[j];\
cerr << endl;\
}

/*#define CHECK(myb, cppb) {\
\
TimeMeasurer::startMeasurement("myb");\
int mycnt = myb.count();\
TimeMeasurer::stopMeasurement("myb");\
\
TimeMeasurer::startMeasurement("cppb");\
int cppcnt = cppb.count();\
TimeMeasurer::stopMeasurement("cppb");\
bool same = true; \
for( int j=0; j<N; j++ ) if( myb[j] != cppb[j] ) same = false; \
if( same == false ){\
cerr << " diff after " << (i+1) << " cycles of operations" << endl;\
exit(1);\
}}*/
//
//void Bitset::test() {
//
//    const int N = 2000;
//    Bitset myb(N);
//    bitset<N> cppb;
//
//    Bitset temp(N);
//    bitset<N> tempcpp;
//
//    int operations = 50000;
//    for( int i=0; i<operations; i++ ){
//        int a,b;
//
//        a = rand()%N; b = rand()%N; if( a > b ) swap(a,b);
//
//        // SET ON POSITION
//        TimeMeasurer::startMeasurement("myb");
//        myb.set( a, b%2 );
//        TimeMeasurer::stopMeasurement("myb");
//
//        TimeMeasurer::startMeasurement("cppb");
//        cppb.set(a,b%2);
//        TimeMeasurer::stopMeasurement("cppb");
//
//     //   cerr << "\rSET DONE" << flush;
//        CHECK(myb,cppb)
//
//
//
//
//
//        // SHL
//        a = rand()%N; b = rand()%N; if( a > b ) swap(a,b);
//
//        TimeMeasurer::startMeasurement("myb");
//        myb <<= (b/10);
//        TimeMeasurer::stopMeasurement("myb");
//
//        TimeMeasurer::startMeasurement("cppb");
//        cppb >>= (b/10);
//        TimeMeasurer::stopMeasurement("cppb");
//
//     //   cerr << "\rSHL DONE" << flush;
//        CHECK(myb,cppb)
//
//
//
//
//        // SET ON INTERVAL
//        a = rand()%N; b = rand()%N; if( a > b ) swap(a,b);
//
//        TimeMeasurer::startMeasurement("myb");
////        myb.set( a,b, b%2 );
////        TimeMeasurer::stopMeasurement("myb");
////
////        TimeMeasurer::startMeasurement("cppb");
////        for( int k=a; k<=b; k++ ) cppb.set(k,b%2);
////        TimeMeasurer::stopMeasurement("cppb");
////
////     //   cerr << "\rSET ON INTERVAL DONE" << flush;
////        CHECK(myb,cppb)
////
////
////
////
////
////        // FLIP ON INERVAL
////        a = rand()%N; b = rand()%N; if( a > b ) swap(a,b);
////
////        TimeMeasurer::startMeasurement("myb");
////        myb.flip( a,b );
////        TimeMeasurer::stopMeasurement("myb");
////
////        TimeMeasurer::startMeasurement("cppb");
////        for( int k=a; k<=b; k++ ) cppb.flip(k);
////        TimeMeasurer::stopMeasurement("cppb");
////
////     //   cerr << "\rFLIP ON INTERVAL DONE" << flush;
////        CHECK(myb,cppb)
////
////
////
////
////        // SHR
////        a = rand()%N; b = rand()%N; if( a > b ) swap(a,b);
////
////        TimeMeasurer::startMeasurement("myb");
////        myb >>= (b/10);
////        TimeMeasurer::stopMeasurement("myb");
////
////        TimeMeasurer::startMeasurement("cppb");
////        cppb <<= (b/10);
////        TimeMeasurer::stopMeasurement("cppb");
////
////    //    cerr << "\rSHR DONE" << flush;
////        CHECK(myb,cppb)
////
////
////
////
////        for( int k=0; k<N; k++ ){
////            if( rand()%2 == 1 ){
////             //   TimeMeasurer::startMeasurement("myb");
////                temp.set( k,1 );
////            //    TimeMeasurer::stopMeasurement("myb");
////
////            //    TimeMeasurer::startMeasurement("cppb");
////                tempcpp.set(k,1);
////            //    TimeMeasurer::stopMeasurement("cppb");
////            }
////        }
////
////
////
////        // XOR AND OR SHIFT
////        a = rand()%N; b = rand()%N; if( a > b ) swap(a,b);
////
////        TimeMeasurer::startMeasurement("myb");
////        myb &= temp;
////        myb ^= (temp<<1);
////        myb |= (temp ^ (temp<<1) );
////        TimeMeasurer::stopMeasurement("myb");
////
////        TimeMeasurer::startMeasurement("cppb");
////        cppb &= tempcpp;
////        cppb ^= (tempcpp>>1);
////        cppb |= (tempcpp ^ (tempcpp>>1) );
////        TimeMeasurer::stopMeasurement("cppb");
////
////     //   cerr << "\rXOR AND OR SHIFT DONE" << flush;
////        CHECK(myb,cppb)
////
////
////
////        a = rand()%N; b = rand()%N; if( a > b ) swap(a,b);
////        TimeMeasurer::startMeasurement("myb");
////        int mycnt = myb.count(a,b);
////        TimeMeasurer::stopMeasurement("myb");
////
////        TimeMeasurer::startMeasurement("cppb");
////        int cppcnt = 0;
////        for(int k=a; k<=b; k++) if( cppb[k] ) cppcnt++;
////        TimeMeasurer::stopMeasurement("cppb");
////
////        if( mycnt != cppcnt ){
////            WRITE(myb,cppb);
////            cerr << "cnt on interval diff in " << (i+1) << " cycles" << endl;
////            cerr << "mycnt = " << mycnt << "    cppcnt = " << cppcnt << endl;
////            exit(1);
////        }
////    }
////
////
////    cerr << "correct!" << endl;
////    TimeMeasurer::writeAllMeasurements();
////    exit(0);
////
////
////}


Bitset::VT Bitset::bits;
Bitset::VT Bitset::zerosOnes;