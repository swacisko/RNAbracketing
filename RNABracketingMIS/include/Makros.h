/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Makros.h
 * Author: sylwester
 *
 * Created on November 20, 2018, 11:16 PM
 */

#ifndef MAKROS_H
#define MAKROS_H

//#include <bits/stdc++.h>

using namespace std;
/*
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err23781(_it, args); }

//void err23781(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err23781(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err23781(++it, args...);
}*/

#define WRITE(tab) {for( auto a : tab ) cerr << a << " "; cerr << endl;}
#define WRITE2(tab){ for( auto v : tab ){ for( auto a : v ) { cerr << a << " "; } cerr << endl; } }



class Makros {
public:
    Makros();
    Makros(const Makros& orig);
    virtual ~Makros();
private:

};

#endif /* MAKROS_H */

